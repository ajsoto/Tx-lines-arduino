volatile boolean first;
volatile boolean triggered;
volatile unsigned long overflowCount;
volatile unsigned long startTime;
volatile unsigned long finishTime;
int valorA0 = 0;
int valorA1 = 0;

// here on rising edge
void isr2(){
  // wait until we noticed last one
  if(triggered)
    return;

  if(first){
    startTime = (overflowCount << 16) + TCNT1;
    first = false;
    detachInterrupt(digitalPinToInterrupt(2));
    EIFR = _BV (INTF1);  // clear flag for interrupt 1
    attachInterrupt(digitalPinToInterrupt(3), isr3, RISING);
    return;  
  }
}

void isr3(){
  finishTime = (overflowCount << 16) + TCNT1;
  triggered = true;
  detachInterrupt(digitalPinToInterrupt(3));
}
// timer overflows (every 65536 counts)
ISR (TIMER1_OVF_vect){
  overflowCount++;
}  // end of TIMER1_OVF_vect

void prepareForInterrupts(){
  // get ready for next time
  EIFR = _BV (INTF0);  // clear flag for interrupt 0
  first = true;
  triggered = false;  // re-arm for next time
  attachInterrupt(digitalPinToInterrupt(2), isr2, RISING);     
}  // end of prepareForInterrupts

void setup () {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(115200);       
  // reset Timer 1
  TCCR1A = 0;
  TCCR1B = 0;
  // Timer 1 - interrupt on overflow
  TIMSK1 = _BV (TOIE1);   // enable Timer1 Interrupt
  // zero it
  TCNT1 = 0;     
  // start Timer 1
  TCCR1B =  _BV (CS10);  //  no prescaling
  // set up for interrupts
  prepareForInterrupts ();   
} // end of setup

void loop(){
  for(int i=0;i<31;i++){
    valorA0 += analogRead(A0);
    valorA1 += analogRead(A1);
  }
  valorA0=valorA0/30;
  valorA1=valorA1/30;
  Serial.println("Atenuación: "+String(valorA1-valorA0));
  valorA0=0;
  valorA1=0;
  
  if (!triggered)
    return;
  unsigned long elapsedTime = finishTime - startTime;
  float freq = 1.0/((float(elapsedTime)*62.5e-9));  // each tick is 62.5 nS
  Serial.print("# de ciclos: ");
  Serial.print(160-elapsedTime);
  Serial.println(" ciclos");
  delay(500);
  prepareForInterrupts();
}

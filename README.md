# Measuring parameters in transmission lines with embedded systems

**Repository for results and code related to the paper: "Measuring parameters in transmission lines with embedded systems"**  
*Published in Tecnura Journal*  
[Link to Full Paper](https://revistas.udistrital.edu.co/index.php/Tecnura/article/view/18131/18360)

---

## Table of Contents
1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Results](#results)

---

## Introduction
This repository provides the code to replicate our results. Our goal was to explain the operation of a transmission line parameter measurement system as a low-cost and automated proposal for its characterization, implemented through embedded systems (Arduino in this case). 

## Usage
The following shows the schematic circuits needed to replicate our experiments (4 in total). For further details, please refer to the paper.
![Experiment 1](./figures/Experiment1.jpg)
![Experiment 2](./figures/Experiment2.jpg)
![Experiment 3](./figures/Experiment3.jpg)
![Experiment 4](./figures/Experiment4.jpg)
## Results

| Parameter       | Value                                        | Experiment                                            |         |
|-----------------|------------------------|---------------------|-------------------------------------------------------| % de    |
|                 | Nominal                | Theoric             | 1           | 2           | 3           | 4           | error   |
|-----------------|------------------------|---------------------|-------------|-------------|-------------|-------------|---------|
| Z₀ (Ω)          | 75                     | 75                  | 74.3        | 74          | 74.2        | 74.3        | 0       |
| α (dB/m)        | 0.02                   | 0.0197              | 0.0138      | 0.015       | 0.02        | 0.0148      | 7.5     |
| r (µs)          | 1.3                    | 1.3                 | 1.3         | 1.4         | 1.44        | 1.38        | 6.15    |
| β (rad/m)       | 0.00265                | 0.0027              | 0.0027      | 0.0029      | 0.003       | 0.0028      | 3.7     |
| vₚ (m/s)        | 0.78c                  | 0.78c               | 0.78c       | 0.73c       | 0.71c       | 0.74c       | 5.13    |
| R (Ω/m)         | 0.146                  | 0.146               | 0.141       | 0.17        | 0.148       | 0.149       | 5.68    |
| G (S/m)         | 7.38                   | 6.85                | 7.1         | 5.88        | 6.74        | 6.73        | 5.22    |
| C (pF/m)        | 56.78                  | 56.76              | 56.48       | 62          | 63.63       | 60.9        | 7.83    |
| L (µH/m)        | 0.318                  | 0.318              | 0.312       | 0.34        | 0.35        | 0.34        | 8.98    |


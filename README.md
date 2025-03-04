# High-Order Runge-Kutta Integration for Globular Cluster Dynamics within Dwarf Galaxies

## Overview
This repository contains the C++ implementation of a **10th-order Runge-Kutta integration method**, developed for high-precision simulations of globular cluster escape dynamics from satellite dwarf galaxies. 
The code was used in the published paper:

**"The Escape of Globular Clusters from the Satellite Dwarf Galaxies of the Milky Way"**  
*MNRAS 513, 3526–3540 (2022), DOI: [10.1093/mnras/stac1070](https://doi.org/10.1093/mnras/stac1070)*


## Features
- Implements a **10th-order Runge-Kutta** integrator for accurate orbital calculations.
- Designed for modeling **three-body interactions** in a galactic potential.
- Optimized for performance in long-term dynamical simulations.
- Supports Hernquist potential for dwarf galaxies and a multi-component Milky Way potential.

## Requirements
- **C++ Compiler** (GCC, Clang, or MSVC recommended)
- Standard C++ libraries (STL)
- [Optional] **OpenMP** for parallel execution

## Installation & Compilation
To compile the code, run:
```sh
g++ -O3 -std=c++17 -fopenmp main.cpp -o run_simulation
```

## Run
```sh
./run_simulation
```

## Citation
If you use this code in your research please cite the following paper:
```sh
@article{Shirazi2022,
  author = {A. R. Shirazi, H. Haghi, P. Khalaj, A. F. Asl, and A. H. Zonoozi},
  title = {The Escape of Globular Clusters from the Satellite Dwarf Galaxies of the Milky Way},
  journal = {MNRAS},
  volume = {513},
  pages = {3526–3540},
  year = {2022},
  doi = {10.1093/mnras/stac1070}
}
```
## License
This code is released under the MIT License – feel free to use, modify, and distribute with proper attribution.

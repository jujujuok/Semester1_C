#include "eulerLib.h"
#include <stdio.h>
/*******************************************************
* NAME: main.c (main)
*
* AUTHOR: jannik wiessler
*
* DATE: 2021-01-10
*
* DESCRIPTION:  implementation of simple explicit euler method to solve first order ode system
*               mass spring damper system
*
* DEPENDENCIES: eulerLib.h
                gnuplot in PATH
*
* INFO: For DHBW use only.
*   >> Practice of explicit euler method
*
*   >> CREDITS FOR TEMPLATE TO FABIAN HAAS
**/

int main()
{
    char *filename = "simData.txt";

    printf("\n\n--- MASS SPRING DAMPER CALCULATION ---\n");

    SimulationHandle handle = getHandle();
    calculateSimulation(&handle, filename);
    plotSimulation(filename);

    return 0;
}
#include "eulerLib.h"
#include <stdio.h>
/*******************************************************
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
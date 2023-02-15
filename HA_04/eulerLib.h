#ifndef EULERLIB_H_
#define EULERLIB_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    double position;
    double velocity;
} SimulationState;

typedef struct
{
    SimulationState *states;
    double duration;
    double stepSize;
} SimulationHandle;

SimulationHandle getHandle();

void calculateSimulation(SimulationHandle *handle, const char *filename);

void plotSimulation(const char *filename);

#endif

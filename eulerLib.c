#include <stdio.h>
#include "eulerLib.h"
#include <stdlib.h>

#define NUMOFSTATES 2

//Credits to: https://bitly.com/98K8eH

double numberInput(char *message) {
    printf("\n%s", message);

    double input;
    if (scanf("%lf", &input) == 1)
        return input;
    exit(1);
}

SimulationHandle getHandle() {
    SimulationHandle handle;

    // get user defined simulation time
    handle.duration = numberInput("\t- Simulation time (in s): ");

    // get user defined step size
    handle.stepSize = numberInput("\t- Step size (in s): ");

    handle.states = malloc(sizeof(SimulationState) * NUMOFSTATES);

    // get init state position
    handle.states->position = numberInput("\t- Position(t = 0): ");

    // get init state speed
    handle.states->velocity = numberInput("\t- Speed(t = 0): ");

    return handle;
}


void massSpringDamperCalculation(SimulationState *state, double stepsize) { // mass spring damper
    double MASS_CONST = 1.0;
    double SPRING_CONST = 2.0;
    double DAMPER_CONST = 2.8;

    double  x = state->position,
            v = state->velocity;

    double acceleration =
            -1 * ((DAMPER_CONST / MASS_CONST) * v +
            (SPRING_CONST / MASS_CONST) * x);

    // Formel (7) - x'
    state->position = state->position + state->velocity * stepsize;
    // Formel (8) - v'
    state->velocity = state->velocity + acceleration * stepsize;
}


FILE *open_file(const char *filename) {
    FILE *file_ptr = fopen("simData.txt", "w");
    if (file_ptr == NULL) {
        printf("Error while trying to open the file. Are you stupid! ");
        exit(1);
    }

    return file_ptr;
}


void print_vals(SimulationHandle *handle) {
    printf("duration: %lf\n", handle->duration);
    printf("stepSize: %lf\n", handle->stepSize);
    printf("state pos: %lf\n", handle->states->position);
    printf("state vel: %lf\n", handle->states->velocity);
}


void calculateSimulation(SimulationHandle *handle, const char *filename) {
    // this is called only once

    FILE *file = open_file("simData.txt");

    print_vals(handle);

    double time = 0;
    while (time < handle->duration) {
        // get derivatives
        fprintf(file, "%lf %lf %lf\n",
                time,
                handle->states->position,
                handle->states->velocity);
        massSpringDamperCalculation(handle->states, handle->stepSize);
        time += handle->stepSize;
    }
    fclose(file);
}


void plotSimulation(const char *filename) {
    char *gnuPlotInput[] = {"set title 'Mass Damper Simulation'",
                            "set xlabel 'time in s'",
                            "plot 'simData.txt' using 1:2 title 'position', 'simData.txt' using 1:3 title 'speed'"};


    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("AAAALARM: gnuplot file could not be opened");
        return;
    }

    for(int i = 0; i < 3; i++) fprintf(gnuplotPipe, "%s\n", gnuPlotInput[i]);

    fprintf(gnuplotPipe, "exit");
    pclose(gnuplotPipe);
}
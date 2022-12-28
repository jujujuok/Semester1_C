#include <stdio.h>
#include <string.h>
#include "newton_lib.h"

double func_f(double x)
{
    return x * x - 6 * x + 9;
}

double func_df(double x, double (*f_ptr)(double))
{
    return 2 * x - 6;
}

double numericalApproxFunc(double x, double (*f_ptr)(double))
{
    long double h = 0.00000001;
    return ((f_ptr(x + h) - f_ptr(x)) / h);
}

int newtonRaphson(double x0, int accuracy, double (*f_ptr)(double), double (*df_ptr)(double, double (*func_ptr)(double)))
{
    int iterations;
    double h, x1, allerr;
    accuracy += 1; // weil komma mitgezählt wird

    for (iterations = 1; iterations <= 1000; iterations++)
    {
        x1 = x0 - (f_ptr(x0) / df_ptr(x0, f_ptr));
        // DEBUG printf("Iteration: %d, x = %lf\n", iterations, x1);

        // check for accuracy
        char s_x0[100], s_x1[100];
        sprintf(s_x0, "%lf", x0);
        sprintf(s_x1, "%lf", x1);
        char *ptr_s_x0 = strchr(s_x0, '.');
        char *ptr_s_x1 = strchr(s_x1, '.');
        // DEBUG printf("\tstrings: %s, %s\n", s_x0, s_x1);
        if (strncmp(ptr_s_x0, ptr_s_x1, accuracy) == 0)
        {
            printf("\nResult: x = %lf", x1);
            return iterations;
        };

        x0 = x1;
    }
    printf("\nResult: x = %lf", x1);
    return iterations;
}

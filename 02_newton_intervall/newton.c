#include <stdio.h>
#include "./newton_lib.h"

int main()
{
    // variables
    double startX;
    int acc;
    int approx;
    int iterations;

    // input
    printf("Enter startvalue for x: ");
    scanf("%lf", &startX);
    // printf("%lf\n", startX);

    printf("Enter the accuracy you want after the comma (up to 6-default): ");
    scanf("%d", &acc);
    // printf("%d\n", acc);

    printf("Do you want a numerical Aproximation of the differential Function? [1: yes 0: no]: ");
    scanf("%d", &approx);
    // printf("Approximation: %d", approx);
    // printf("\nFunc pointer: %d", &func_f);

    if (approx == 1)
    {
        //printf("numerical Approximation");
        iterations = newtonRaphson(startX, acc, &func_f, &numericalApproxFunc);
    }
    else
    {
        //printf("festgelegte Differentialfunktion");
        iterations = newtonRaphson(startX, acc, &func_f, &func_df);
    }

    printf("\nIt took %d iterations to get to the accuracy you wanted.", iterations);

    return 0;
}
#include <stdio.h>
#include "./calculator_lib.h"

int main()
{
    // variables
    char operation;
    int format;

    number num1, num2, result;

    printf("--- COMPLEX CALCULATOR ---\n");

    // first number
    printf("\nEnter your first number: ");
    scanf("%s", &num1.s_num);
    num1 = process_number(num1.s_num);
    if (num1.a_error == 1)
    {
        printf("Error: num1");
        return 0;
    }

    // DEBUG
    // printf("Real part: %lf\n", num1.real);
    // printf("Imaginary part: %lf\n", num1.imag);
    // printf("Str: %s", num1.s_num);

    // second number
    printf("\nEnter your second number: ");
    scanf("%s", &num2.s_num);
    num2 = process_number(num2.s_num);
    if (num2.a_error == 1)
    {
        printf("Error: num2");
        return 0;
    }

    // operation
    printf("\nEnter your operation: ");
    scanf(" %c", &operation);

    // format
    printf("\nEnter your preferred format for the result. ");
    printf("\n1: Cartesian\n2: Polar1 (Euler)\n3: Polar2\nFormat: ");
    scanf("%d", &format);

    result = calculate(num1, num2, operation);
    // printf("RES ERROR: %d", result.a_error);
    if (result.a_error == 1)
    {
        printf("\nError: result");
        return 0;
    }

    print_result(result, format);

    calculate_print_all(num1, num2, format);

    return 0;
}

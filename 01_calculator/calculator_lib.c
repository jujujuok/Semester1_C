#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculator_lib.h"

number process_number(char str_num[100])
{
    number num;
    char *plus_ptr = strchr(str_num, '+');
    if (plus_ptr == NULL)
    {
        char *minus_ptr = strchr(str_num, '-');
        if (minus_ptr == NULL)
        {
            printf("\nError: invalid complex number format\n");
            num.a_error = 1;
            return num;
        }
        else
        {
            num.imag *= -1;
        }
    }

    int num_parsed = sscanf(str_num, "%lf%lfi", &num.real, &num.imag);
    // printf("num parsed: %d\n", num_parsed);
    if (num_parsed != 2)
    {
        printf("\nError: invalid complex number format\n");
        num.a_error = 1;
        return num;
    }

    // printf("Real part: %lf\nImaginary part: %lf\n", num.real, num.imag);

    strcpy(num.s_num, str_num);
    return num;
}

number calculate(number num1, number num2, char op)
{
    number result;
    result.a_error = 0;
    double a, b, n;
    switch (op)
    {
    case '+':
        result.real = num1.real + num2.real;
        result.imag = num1.imag + num2.imag;
        break;
    case '-':
        result.real = num1.real - num2.real;
        result.imag = num1.imag - num2.imag;
        break;
    case '*':
        result.real = num1.real * num2.real - num1.imag * num2.imag;
        result.imag = num1.real * num2.imag + num1.imag * num2.real;
        break;
    case '/':
        a = num1.real * num2.real + num1.imag * num2.imag;
        b = num1.imag * num2.real - num1.real * num2.imag;
        n = num2.real * num2.real + num2.imag * num2.imag;
        if (n == 0)
        {
            result.a_error = 1;
            break;
        }
        result.real = a / n;
        result.imag = b / n;
        break;

    default:
        result.a_error = 1;
        break;
    }
    // DEBUG
    // printf("\nNUM1: Real part: %lf\tImaginary part: %lf", num1.real, num1.imag);
    // printf("\nNUM2: Real part: %lf\tImaginary part: %lf", num2.real, num2.imag);
    // printf("\nResult: Real part: %lf\tImaginary part: %lf\n", result.real, result.imag);

    return result;
};

int print_result(number num, int format)
{
    double mag = sqrt(num.real * num.real + num.imag * num.imag);
    double ang = atan2(num.imag, num.real);
    switch (format)
    {
    case 1:
        printf("\nCartesian Number: %lf + %lfi", num.real, num.imag);
        break;
    case 2:
        printf("Polar1 Format: z = %lf*e^(i*%lf)", mag, ang);
        break;
    case 3:
        printf("Polar2 Format: z = %lf*(cos(%lf)+i*sin(%lf)", mag, ang, ang);
        break;
    default:
        printf("Error: Invalid format.");
        break;
    }

    return 0;
};

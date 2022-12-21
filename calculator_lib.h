#ifndef _CALCULATOR_LIB_H_
#define _CALCULATOR_LIB_H_

struct numbers
{
    int a_error;
    double real;
    double imag;
    char s_num[100];
};

typedef struct numbers number;

number process_number(char *s_num);

number calculate(number num1, number num2, char op);

int print_result(number num, int format);

#endif
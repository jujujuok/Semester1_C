#ifndef _NEWTON_LIB_H_
#define _NEWTON_LIB_H_

int newtonRaphson(double x0, int accuracy, double (*f_ptr)(double), double (*df_ptr)(double, double (*func_ptr)(double)));

double func_f(double x);
double func_df(double x, double (*f_ptr)(double));
double numericalApproxFunc(double x, double (*f_ptr)(double));

#endif
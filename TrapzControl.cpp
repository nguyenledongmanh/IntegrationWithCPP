#include <iostream>
#include <math.h>
#define MAX_ITER 30
using namespace std;

double Func(double x)
{
    return (x * x * x * exp(-x));
}

double qTrapzCtrl(double Func(double), double a, double b, double eps)
{
    double h = b - a;
    int n = 1;

    double T_prev = 0.5 * h * (Func(b) + Func(a));
    double T_new;
    for (int iter = 1; iter < MAX_ITER; iter++)
    {
        double sumf = 0e0;
        for (int i = 1; i <= n; i++)
        {
            sumf += Func(a + (i - 0.5) * h);
        }
        T_new = 0.5 * (T_prev + h * sumf);
        if (iter > 1)
        {
            if (fabs(T_new - T_prev) < eps * fabs(T_new))
                break;
            if (fabs(T_new) <= eps && fabs(T_new) <= fabs(T_new - T_prev))
                break;
        }
        h = h / 2;
        n = 2 * n;
        T_prev = T_new;
    }

    return T_new;
}

int main()
{
    double a = 0e0, b = 1e0;
    cout << "Result: " << qTrapzCtrl(Func, a, b, 1e-6);

    return 0;
}
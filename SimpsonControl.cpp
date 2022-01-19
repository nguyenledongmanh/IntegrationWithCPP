#include <iostream>
#include <math.h>
#define MAX_ITER 30
using namespace std;

double Func(double x)
{
    return (x * x * x * exp(-x));
}

double qSimpsonCtrl(double Func(double), double a, double b, double eps)
{
    double h = b - a;
    int n = 1;
    double T_prev = 0.5 * h * (Func(a) + Func(b));
    double T_new, S_new;
    double S_prev = T_prev;
    for (int iter = 1; iter < MAX_ITER + 1; iter++)
    {
        double sumf = 0e0;
        for (int i = 1; i < n + 1; i++)
        {
            sumf += Func(a + (i - 0.5) * h);
        }
        T_new = 0.5 * (T_prev + h * sumf);
        S_new = (4 * T_new - T_prev) / 3;
        if (iter > 1)
        {
            if (fabs(S_new - S_prev) < eps * fabs(S_new))
                break;
            if (fabs(S_new) <= eps && fabs(S_new) <= fabs(S_new - S_prev))
                break;
        }
        S_prev = S_new;
        T_prev = T_new;
        h = h / 2;
        n *= 2;
    }

    return S_new;
}

int main()
{
    double a = 0e0, b = 1e0;
    cout << "Result: " << qSimpsonCtrl(Func, a, b, 1e-6);

    return 0;
}
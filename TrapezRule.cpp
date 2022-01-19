#include <iostream>
#include "math.h"

using namespace std;

double Func(double x)
{
    return (x * x * x * exp(-x));
}

double qTrapz(double Func(double), double a, double b, int n)
{
    double h = (b - a) / (n - 1);
    double s = 0.5 * (Func(a) + Func(b));
    for (int i = 1; i < n - 1; i++)
    {
        s += Func(a + i * h);
    }

    return h * s;
}

int main()
{
    double a = 0e0, b = 1e0, n = 100;
    cout << "Result: " << qTrapz(Func, a, b, n);
}
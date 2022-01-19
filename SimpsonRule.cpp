#include <iostream>
#include <math.h>
using namespace std;

double Func(double x)
{
    return (x * x * x * exp(-x));
}

double simpsonRule(double Func(double), double a, double b, int n)
{
    double h = (b - a) / (n - 1);
    double s = Func(a) + Func(b);
    for (int i = 3; i <= n - 2; i = i + 2)
    {
        s += 2 * Func(a + i * h);
    }
    for (int i = 2; i <= n - 1; i = i + 2)
    {
        s += 4 * Func(a + i * h);
    }

    return h * s / 3;
}

int main()
{
    double a = 0e0, b = 1e0;
    int n = 100;
    cout << "Result: " << simpsonRule(Func, a, b, n);

    return 0;
}

#include <iostream>
#include <math.h>
#include <vector>
#define MAX_ITER 30
#define EPS 1e-6
using namespace std;

double Func(double x)
{
    return (x * x * x * exp(-x));
}

double qRomberg(double Func(double), double a, double b, double eps)
{
    double r_prev[MAX_ITER + 1] = {0}, r_new[MAX_ITER + 1] = {0};
    double h = b - a;
    int n = 1;
    int k;
    r_prev[0] = 0.5 * h * (Func(a) + Func(b));
    for (k = 1; k <= MAX_ITER; k++)
    {
        double sumf = 0;
        for (int i = 1; i <= n; i++)
        {
            sumf += Func(a + (i - 0.5) * h);
        }

        r_new[0] = (0.5 * (r_prev[0] + h * sumf));
        double f = 1e0;

        for (int j = 1; j <= k; j++)
        {
            f *= 4;
            r_new[j] = (f * r_new[j - 1] - r_prev[j - 1]) / (f - 1);
        }

        if (k > 1)
        {
            if (fabs(r_new[k] - r_prev[k - 1]) < eps * fabs(r_new[k]))
                break;

            if (fabs(r_new[k]) <= eps && fabs(r_new[k]) <= fabs(r_new[k] - r_prev[k - 1]))
                break;
        }

        h /= 2;
        n *= 2;

        for (int j = 0; j <= k; j++)
        {
            r_prev[j] = r_new[j];
        }
    }
    if (k >= MAX_ITER)
    {
        k -= 1;
        cout << "max. no. of iterations exceeded !" << endl;
    }

    return r_new[k];
}
// TEST
int main()
{
    double a = 0e0, b = 1e0;
    cout << "Result: " << qRomberg(Func, a, b, EPS);

    return 0;
}
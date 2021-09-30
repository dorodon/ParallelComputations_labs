#include "mycom.h"

double dabs(double a)
{
    if (a >= 0)
        return a;
    else
        return (-a);
}

double integrate(double f(double x), double a, double b, int n)
{
    int i; double h, s;

    h = (b - a) / n;
    s = 0.5 * f(a);
    for (i = 1; i < n - 1; i++)
        s = s + f(a + h * i);
    s = s + 0.5 * f(b);

    return h * s;
}

double mytime(const int n)
{
    static LARGE_INTEGER t1;
    LARGE_INTEGER t2;
    if (n == 0) {
        QueryPerformanceCounter(&t1);
        return 0.0;
    }
    else {
        QueryPerformanceCounter(&t2);
        return ((double)t2.QuadPart - (double)t1.QuadPart) * 1e-6;
    }
}
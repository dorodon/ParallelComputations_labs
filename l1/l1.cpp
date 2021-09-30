#include <iostream>
#include "mycom.h"

double f(double x)
{
    return (41.7 / (1.7 / x + x));
}
double f1(double x)
{
    return (41.7 / (1.7 / (x + 512000.7) + (x + 512000.7)));
}
double f2(double x)
{
    return (41.7 / (1.7 / (x - 512000.7) + (x - 512000.7)));
}
double f3(double x)
{
    return (41.7 / (1.7 / (x * 512000.7) + (x * 512000.7)));
}
double f4(double x)
{
    return (41.7 / (1.7 / (x / 512000.7) + (x / 512000.7)));
}
double f5(double x)
{
    return (41.7 / (1.7 / pow(x, 4) + pow(x, 4)));
}
double f6(double x)
{
    return (41.7 / (1.7 / exp(x) + exp(x)));
}
double f7(double x)
{
    return (41.7 / (1.7 / log(x) + log(x)));
}
double f8(double x)
{
    return (41.7 / (1.7 / sin(x) + sin(x)));
}

int main()
{
    int nc = 1000000000;
    double t1, t2, dt, sum;

    t1 = mytime(0); sum = integrate(f, 0.0, 1.0, nc); t1 = mytime(1);

    t2 = mytime(0); sum = integrate(f1, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec + perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f2, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec - perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f3, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec * perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f4, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec / perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f5, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec pow perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f6, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec exp perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f7, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec ln perf.: %le GFlops\n", t1, t2, dt);

    t2 = mytime(0); sum = integrate(f8, 0.0, 1.0, nc); t2 = mytime(1);
    dt = 2.0 / dabs(t2 - t1);
    printf("Time: %lf %lf sec sin perf.: %le GFlops\n", t1, t2, dt);

    return 0;
}
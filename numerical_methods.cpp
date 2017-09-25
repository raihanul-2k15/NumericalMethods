#include<cmath>
#include "numerical_methods.h"
namespace numerical_methods {

double bisection(const Function& f, double lo, double up)
{
    double x_prev=lo;
    double x0;
    while (true)
    {
        x0=(lo+up)/2;
        if (f(lo)*f(x0)<0) up=x0;
        else lo=x0;
        if (std::abs((x_prev-x0)/x0)<REL_ERR) break;
        x_prev=x0;
    }
    return x0;
}
double false_position(const Function& f, double lo, double up)
{
    double x_prev=lo;
    double x0;
    while (true)
    {
        x0=lo-f(lo) * (up-lo) / (f(up)-f(lo));
        if (f(lo)*f(x0)<0) up=x0;
        else lo=x0;
        if (std::abs((x_prev-x0)/x0)<REL_ERR) break;
        x_prev=x0;
    }
    return x0;
}
double derivative(const Function& f, double point)
{
    return (f(point+DRV_STP) - f(point-DRV_STP)) / (2*DRV_STP);
}
double trapezoidal(const Function& f, double a, double b, int n)
{
    double h=(b-a)/n;
    double integral=f(a);
    double x=a;
    for (int i=1;i<n;i++)
        integral+=2.0*f(x+=h);
    integral+=f(b);
    return integral * h / 2.0;
}
double simphson_1_3rd(const Function& f, double a, double b, int n)
{
    double h=(b-a)/n;
    double integral=f(a);
    double x=a;
    for (int i=1;i<n;i++)
    {
        if (i%2==1) integral+=4.0*f(x+=h);
        else integral+=2.0*f(x+=h);
    }
    integral+=f(b);
    return integral * h / 3.0;
}
double simphson_3_8th(const Function& f, double a, double b, int n)
{
    double h=(b-a)/n;
    double integral=f(a);
    double x=a;
    for (int i=1;i<n;i++)
    {
        if (i%3!=0) integral+=3.0*f(x+=h);
        else integral+=2.0*f(x+=h);
    }
    integral+=f(b);
    return integral * 3.0 * h / 8.0;
}

}

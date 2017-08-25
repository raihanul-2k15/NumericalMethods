#include<cmath>
#include "numerical_methods.h"
namespace numerical_methods {

double nonLinear_bisection(const Function& f, double lo, double up)
{
    double x_prev=lo;
    double x0;
    while (true)
    {
        x0=(lo+up)/2;
        if (f(lo)*f(x0)<0) up=x0;
        else lo=x0;
        if (std::abs((x_prev-x0)/x0)<ABS_ERR) break;
        x_prev=x0;
    }
    return x0;
}
}

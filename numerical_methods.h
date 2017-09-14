#ifndef NUM_MTD_H
#define NUM_MTD_H
#include "expression_tools.h"
namespace numerical_methods {
const double REL_ERR=0.000001;
const double DRV_STP=0.001;
double bisection(const Function&,double,double);
double derivative(const Function&,double);
}
#endif

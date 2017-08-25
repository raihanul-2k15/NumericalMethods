#ifndef NUM_MTD_H
#define NUM_MTD_H
#include "expression_tools.h"
namespace numerical_methods {
const double ABS_ERR=0.000001;
double nonLinear_bisection(const Function&,double,double);
}
#endif

#ifndef NUM_MTD_H
#define NUM_MTD_H
#include "expression_tools.h"
namespace numerical_methods {
const double REL_ERR=0.000001;
const double DRV_STP=0.001;
double bisection(const Function& f,double lower_lim,double upper_lim);          // solve equation
double false_position(const Function& f,double lower_lim,double upper_lim);     // solve equation
double derivative(const Function& f,double x);
double trapezoidal(const Function& f, double x1, double x2, int steps);      // integration
double simphson_1_3rd(const Function& f, double x1, double x2, int steps);   // integration
double simphson_3_8th(const Function& f, double x1, double x2, int steps);   // integration
}
#endif

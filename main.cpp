#include <iostream>
#include<cmath>
#include "expression_tools.h"
#include "numerical_methods.h"
using namespace std;
void test_bisection();
void test_derivative();
void test_integration();
int main()
{
    test_integration();
    return 0;
}
void test_integration()
{
    string func;
    cout << "Enter function (e.g: 1/(1+x) ): ";
    getline(cin,func);
    char var;
    for (int i=0;i<func.size();i++)
    {
        if (func[i]>='a' and func[i]<='z')
        {
            var=func[i];
            break;
        }
    }
    Function f(func,1,var);
    double lo,hi;
    cout << "Enter lower-limit and upper-limit (e.g: 0 1): ";
    cin >> lo >> hi;
    double integral=numerical_methods::trapezoidal(f,lo,hi,10);
    cout << "Trapezoidal approximation   : " << integral << endl;
    integral=numerical_methods::simphson_1_3rd(f,lo,hi,10);
    cout << "Simphson 1/3rd approximation: " << integral << endl;
    integral=numerical_methods::simphson_3_8thf,lo,hi,10);
    cout << "Simphson 3/8th approximation: " << integral << endl;
}
void test_derivative()
{
    string func;
    cout << "Enter function (e.g: x^2+2*x+10): ";
    getline(cin,func);
    char var;
    for (int i=0;i<func.size();i++)
    {
        if (func[i]>='a' and func[i]<='z')
        {
            var=func[i];
            break;
        }
    }
    Function f(func,1,var);
    double point;
    cout << "Enter point to calculate derivative (e.g 1.5): ";
    cin >> point;
    double deriv=numerical_methods::derivative(f,point);
    cout << "Derivative is " << deriv << endl;
}
void test_bisection()
{
    string equation;
    cout << "Enter equation (example: x +10= 2 *x^ 2" << endl;
    getline(cin,equation);
    int equalSign=0;
    while (equation[equalSign]!='=') equalSign++;
    string func=equation.substr(0,equalSign);
    func+="-(";
    func+=equation.substr(equalSign+1,equation.size()-equalSign+1);
    func+=")";
    char var;
    for (int i=0;i<func.size();i++)
    {
        if (func[i]>='a' and func[i]<='z')
        {
            var=func[i];
            break;
        }
    }
    Function f(func,1,var);
    double lowerLimit,upperLimit;
    cout << "Enter range for solution (example: -500 500): ";
    cin >> lowerLimit >> upperLimit;
    double solution= numerical_methods::bisection(f,lowerLimit,upperLimit);
    cout << "Solution is x = " << solution << endl;
}

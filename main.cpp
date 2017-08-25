#include <iostream>
#include<cmath>
#include "expression_tools.h"
#include "numerical_methods.h"
using namespace std;
int main()
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
    double solution= numerical_methods::nonLinear_bisection(f,lowerLimit,upperLimit);
    cout << "Solution is x = " << solution << endl;
    return 0;
}

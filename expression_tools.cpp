#include "expression_tools.h"
#include<math.h>
#include<stack>
#include<map>
#include<stdarg.h>

#include<iostream>
bool Function::isOperator(const char& c)
{
    return (c=='+' or c=='-' or c=='*' or c=='/' or c=='^');
}

bool Function::isVariable(const char& c)
{
    return c>='a' and c<='z';
}

bool Function::isNumeric(const char& c)
{
    return (c>='0' and c<='9');
}
double Function::performOperation(const float& op1, const char& op, const float& op2)
{
    if (op=='+') return op1+op2;
    if (op=='-') return op1-op2;
    if (op=='*') return op1*op2;
    if (op=='/') return op1/op2;
    if (op=='^') return pow(op1,op2);
}

double Function::stoi(const std::string& s)
{
    int number=0, multiplier=1;
    for (int i=s.size()-1;i>=0;i--)
    {
        number+= (s[i]-'0')*multiplier;
        multiplier*=10;
    }
    return (double)number;
}
int Function::getPrec(const char& c)
{
    int prec[]={1,1,2,2,3};
    if (c=='+') return prec[0];
    if (c=='-') return prec[1];
    if (c=='*') return prec[2];
    if (c=='/') return prec[3];
    if (c=='^') return prec[4];
}
bool Function::higherOrEqualPrec(const char& a,const char& b)
{
    return getPrec(a) >= getPrec(b);
}
std::string Function::infixToPostfix(std::string infix)
{
    std::stack<char> s;
    infix+=")";
    std::string out;
    s.push('(');
    for (int i=0;i<infix.size();i++)
    {
        if (isVariable(infix[i]))
        {
            out+=infix[i];
            out+=' ';
        }
        if (isNumeric(infix[i]))
        {
            while (isNumeric(infix[i]))
                out+=infix[i++];
            i--;
            out+= ' ';
        }
        else if (infix[i]=='(')
            s.push('(');
        else if (infix[i]==')')
        {
            while (!s.empty() and s.top()!='(')
            {
                out+=s.top();
                out+=' ';
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(infix[i]))
        {
            while (!s.empty() and s.top()!='(' and higherOrEqualPrec(s.top(),infix[i]))
            {
                out += s.top();
                s.pop();
                out+= ' ';
            }
            s.push(infix[i]);
        }
    }
    return out;
}
Function::Function(const std::string& infix,int params,...)
{
    postfix=infixToPostfix(infix);
    parameter_count=params;
    va_list listPointer;
    va_start(listPointer,parameter_count);
    for (int i=0;i<parameter_count;i++)
        parameters.push_back(va_arg(listPointer,int));
    va_end(listPointer);
}
double Function::operator () ( ... )const
{
    std::map<char,double>argValues;
    va_list listPointer;
    va_start(listPointer,parameter_count);
    for(int i=0;i<parameter_count;i++)
        argValues[parameters[i]]=va_arg(listPointer,double);
    va_end(listPointer);
    std::stack<double> s;
    for (int i=0;i<postfix.size();i++)
    {
        if (isOperator(postfix[i]))
        {
            double op2=s.top();
            s.pop();
            double op1=s.top();
            s.pop();
            s.push(performOperation(op1,postfix[i],op2));
        }
        else if (isNumeric(postfix[i]))
        {
            std::string temp="";
            while (isNumeric(postfix[i]))
                temp+=postfix[i++];
            i--;
            s.push(stoi(temp));
        }
        else if (isVariable(postfix[i]))
        {
            double value=argValues[postfix[i]];
            s.push(value);
        }
    }
    return s.top();
}

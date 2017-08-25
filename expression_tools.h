#ifndef EXPR_T_H
#define EXPR_T_H
#include<vector>
#include<string>
class Function
{
    static std::string infixToPostfix(std::string infix);
    static bool isOperator(const char& c);
    static bool isVariable(const char& c);
    static bool isNumeric(const char& c);
    static double performOperation(const float& op1, const char& op, const float& op2);
    static double stoi(const std::string& s);
    static int getPrec(const char& c);
    static bool higherOrEqualPrec(const char& a,const char& b);

    std::string postfix;
    int parameter_count;
    std::vector<char> parameters;
public:
    Function(const std::string& infix,int params,...);
    double operator () ( ... )const;
};
#endif

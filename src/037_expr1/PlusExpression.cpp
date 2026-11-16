#include "expr.hpp"
#include <string>

PlusExpression::PlusExpression(Expression *lhs, Expression *rhs):lhs(lhs), rhs(rhs) {};

std::string PlusExpression::toString() const{
    return "(" + lhs->toString() + " + " + rhs->toString() + ")";
};


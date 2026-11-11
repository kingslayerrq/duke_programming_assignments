#include "expr.hpp"
#include <string>

NumExpression::NumExpression(long n):val(n) {};

std::string NumExpression::toString() const {
    return std::to_string(val);
}
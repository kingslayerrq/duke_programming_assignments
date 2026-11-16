#pragma once

#include <string>

class Expression {
public:
    virtual ~Expression() = default;
    virtual std::string toString() const = 0;
};

class NumExpression : public Expression {
private:
    long val;
public:
    NumExpression(long);
    std::string toString() const;
};

class PlusExpression : public Expression {
private:
    Expression* lhs;
    Expression* rhs;
public:
    PlusExpression(Expression *lhs, Expression *rhs);
    ~PlusExpression();
    std::string toString() const;
};

PlusExpression::PlusExpression(Expression *lhs, Expression *rhs):lhs(lhs), rhs(rhs) {};

std::string PlusExpression::toString() const{
    return "(" + lhs->toString() + " + " + rhs->toString() + ")";
};

PlusExpression::~PlusExpression() {
    delete lhs;
    delete rhs;
}

NumExpression::NumExpression(long n):val(n) {};

std::string NumExpression::toString() const {
    return std::to_string(val);
}
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
    std::string toString() const;
};

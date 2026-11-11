#pragma once
#include <ostream>
#include <string>
#include <memory> 

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
    std::string toString() const override;
};

class PlusExpression : public Expression {
private:
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;
public:
    PlusExpression(Expression *lhs, Expression *rhs);
    std::string toString() const override;
};

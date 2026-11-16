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
    std::string toString() const override;
};

class OpExpression : public Expression {
protected:
    Expression* lhs;
    Expression* rhs;
public:
    OpExpression(Expression* lhs, Expression* rhs);
    virtual ~OpExpression();
    virtual std::string getOp() const = 0;
    virtual std::string toString() const override;
};

class PlusExpression : public OpExpression {
public:
    PlusExpression(Expression* lhs, Expression* rhs);
    std::string getOp() const override;
};

class MinusExpression : public OpExpression {
public:
    MinusExpression(Expression* lhs, Expression* rhs);
    std::string getOp() const override;
};

class TimesExpression : public OpExpression {
public:
    TimesExpression(Expression* lhs, Expression* rhs);
    std::string getOp() const override;
};

class DivExpression : public OpExpression {
public:
    DivExpression(Expression* lhs, Expression* rhs);
    std::string getOp() const override;
};

OpExpression::OpExpression(Expression* lhs, Expression* rhs):lhs(lhs), rhs(rhs){};

OpExpression::~OpExpression(){
    delete lhs;
    delete rhs;
};

std::string OpExpression::toString() const {
    return "(" + lhs->toString() + " " + getOp() + " " + rhs->toString() + ")";
};

PlusExpression::PlusExpression(Expression* lhs, Expression* rhs):OpExpression(lhs, rhs){};

MinusExpression::MinusExpression(Expression* lhs, Expression* rhs):OpExpression(lhs, rhs){};

TimesExpression::TimesExpression(Expression* lhs, Expression* rhs):OpExpression(lhs, rhs){};

DivExpression::DivExpression(Expression* lhs, Expression* rhs):OpExpression(lhs, rhs){};

std::string PlusExpression::getOp() const {
    return "+";
};

std::string MinusExpression::getOp() const {
    return "-";
};

std::string TimesExpression::getOp() const {
    return "*";
};

std::string DivExpression::getOp() const {
    return "/";
};

NumExpression::NumExpression(long n):val(n) {};

std::string NumExpression::toString() const {
    return std::to_string(val);
}
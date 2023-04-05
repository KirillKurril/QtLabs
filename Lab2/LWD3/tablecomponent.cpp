#include "tablecomponent.h"

tableComponent::tableComponent()
{

}

QString tableComponent::getExpression() const
{
    return expression;
}

void tableComponent::setExpression(const QString &newExpression)
{
    expression = newExpression;
}

double tableComponent::getA() const
{
    return a;
}

void tableComponent::setA(double newA)
{
    a = newA;
}

double tableComponent::getB() const
{
    return b;
}

void tableComponent::setB(double newB)
{
    b = newB;
}

double tableComponent::getC() const
{
    return c;
}

void tableComponent::setC(double newC)
{
    c = newC;
}

double tableComponent::getD() const
{
    return d;
}

void tableComponent::setD(double newD)
{
    d = newD;
}

double tableComponent::getE() const
{
    return e;
}

void tableComponent::setE(double newE)
{
    e = newE;
}

double tableComponent::getAnswer() const
{
    return answer;
}

void tableComponent::setAnswer(double newAnswer)
{
    answer = newAnswer;
}

#ifndef TABLECOMPONENT_H
#define TABLECOMPONENT_H
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>


class tableComponent
{
public:
    tableComponent();
    QString getExpression() const;
    void setExpression(const QString &newExpression);

    double getA() const;
    void setA(double newA);

    double getB() const;
    void setB(double newB);

    double getC() const;
    void setC(double newC);

    double getD() const;
    void setD(double newD);

    double getE() const;
    void setE(double newE);

    double getAnswer() const;
    void setAnswer(double newAnswer);

private:
    QString expression;
    double a;
    double b;
    double c;
    double d;
    double e;
    double answer;

};

#endif // TABLECOMPONENT_H

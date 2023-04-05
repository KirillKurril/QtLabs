#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>
#include "tablecomponent.h"

#ifndef RPN_H
#define RPN_H


class RPN
{
public:
    RPN();
    bool SisEmpty() const;
    bool SisFull() const;
    void Spush(QChar ch);
    void Spop();
    QChar Stop() const;
    bool VisEmpty() const;
    bool VisFull() const;
    void Vpush(double value);
    void Vpop();
    double Vtop() const;
    QString process(tableComponent row);
private:
    double* vstack;
    QChar* sstack;
    int vtopIndex;
    int stopIndex;
    QString answerstring;
    QString ans;
};

#endif // RPN_H

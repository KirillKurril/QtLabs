#ifndef FLIGHT_H
#define FLIGHT_H
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>
#include <QTime>



class Flight
{
public:
    Flight();
    QString getNumber() const;
    void setNumber(const QString &newNumber);

    QString getTime() const;
    void setTime(const QString &newTime);

    QString getModel() const;
    void setModel(const QString &newModel);

    QString getDestination() const;
    void setDestination(const QString &newDestination);







private:
    QString number;
    QString time;
    QString model;
    QString destination;
 };



#endif // FLIGHT_H

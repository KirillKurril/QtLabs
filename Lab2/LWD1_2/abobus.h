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
#include <QIcon>

#ifndef ABOBUS_H
#define ABOBUS_H


class Abobus
{
public:
    Abobus();
    void insert(Abobus* replased);
    QString getNumber() const;
    void setNumber(const QString &newNumber);

    QString getStart_time() const;
    void setStart_time(const QString &newStart_time);

    QString getFinish_time() const;
    void setFinish_time(const QString &newFinish_time);

    QString getModel() const;
    void setModel(const QString &newModel);

    QString getDestination() const;
    void setDestination(const QString &newDestination);

private:
    QString number;
    QString start_time;
    QString finish_time;
    QString model;
    QString destination;
};

#endif // ABOBUS_H

#include "abobus.h"

Abobus::Abobus()
{

}

QString Abobus::getNumber() const
{
    return number;
}

void Abobus::setNumber(const QString &newNumber)
{
    number = newNumber;
}

QString Abobus::getStart_time() const
{
    return start_time;
}

void Abobus::setStart_time(const QString &newStart_time)
{
    start_time = newStart_time;
}

QString Abobus::getFinish_time() const
{
    return finish_time;
}

void Abobus::setFinish_time(const QString &newFinish_time)
{
    finish_time = newFinish_time;
}

QString Abobus::getModel() const
{
    return model;
}

void Abobus::setModel(const QString &newModel)
{
    model = newModel;
}

QString Abobus::getDestination() const
{
    return destination;
}

void Abobus::setDestination(const QString &newDestination)
{
    destination = newDestination;
}


#include "flight.h"

Flight::Flight()
{

}

QString Flight::getNumber() const
{
    return number;
}

void Flight::setNumber(const QString &newNumber)
{
    number = newNumber;
}

QString Flight::getTime() const
{
    return time;
}

void Flight::setTime(const QString &newTime)
{
    time = newTime;
}

QString Flight::getModel() const
{
    return model;
}

void Flight::setModel(const QString &newModel)
{
    model = newModel;
}

QString Flight::getDestination() const
{
    return destination;
}

void Flight::setDestination(const QString &newDestination)
{
    destination = newDestination;
}




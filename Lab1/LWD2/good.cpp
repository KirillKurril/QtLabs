#include "good.h"



Good::Good(int i)
{
QString file_path = "C:/C++/Labs/Lab1/LWD2/goods/good" + QString::number(i) + ".txt";
QFile file(file_path);
if (file.open(QIODevice::ReadOnly | QIODevice::Text))
{
    qDebug() << "File is successfully open!\n";
}
else
{
    qDebug() << "File isn't open!\n";
}
QTextStream ptr(&file);
ptr.seek(0);
type = ptr.readLine();
manufacturer = ptr.readLine();
model = ptr.readLine();
parameters = ptr.readLine();
price = ptr.readLine();
amount = ptr.readLine();
file.close();
}

QString Good::getType() const
{
    return type;
}

void Good::setType(const QString &newType)
{
    type = newType;
}

QString Good::getManufacturer() const
{
    return manufacturer;
}

void Good::setManufacturer(const QString &newManufacturer)
{
    manufacturer = newManufacturer;
}

QString Good::getModel() const
{
    return model;
}

void Good::setModel(const QString &newModel)
{
    model = newModel;
}

QString Good::getParameters() const
{
    return parameters;
}

void Good::setParameters(const QString &newParameters)
{
    parameters = newParameters;
}

QString Good::getPrice() const
{
    return price;
}

void Good::setPrice(const QString &newPrice)
{
    price = newPrice;
}

QString Good::getAmount() const
{
    return amount;
}

void Good::setAmount(QString newAmount)
{
    amount = newAmount;
}



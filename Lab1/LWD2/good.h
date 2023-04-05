#ifndef GOOD_H
#define GOOD_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>
#include <QFileDialog>


class Good
{
public:
    Good(int i);


    QString getType() const;
    void setType(const QString &newType);

    QString getManufacturer() const;
    void setManufacturer(const QString &newManufacturer);

    QString getModel() const;
    void setModel(const QString &newModel);

    QString getParameters() const;
    void setParameters(const QString &newParameters);

    QString getPrice() const;
    void setPrice(const QString &newPrice);

    QString getAmount() const;
    void setAmount(QString newAmount);



private:
QString type;
QString manufacturer;
QString model;
QString parameters;
QString price;
QString amount;
};

#endif // GOOD_H

//extern std::vector<Good> Goods;
//extern std::vector<Good> motherboards;
//extern std::vector<Good> processors;
//extern std::vector<Good> rams;
//extern std::vector<Good> roms;
//extern std::vector<Good> power_units;
//extern std::vector<Good> cases;

#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>


class Date
{
public:
    Date();
    Date NextDay();
    Date PreviousDay();
    int DaysTillYourBithday();
    int Duration();
    bool IsLeap();
    short WeekNumber();
    static void openFile();
    static void addNewDate(QString str);
    static void deleteDate(QString str);
    static void reverse(QString from, QString to);
    static void fullDelete();


    void setfullDate(QString str)
    {
            fullDate = str;
    }
    QString getfullDate()
    {
            return fullDate;
    }



    static QString getBirthDay();
    static void setBirthDay(const QString &newBirthDay);

    static QString getFileName();
    static void setFileName(const QString &newFileName);

private:
    QString fullDate;
    int day;
    int month;
    int year;

    static QString fileName;
    static QString birthDay;
    static QDate today;
    static int measure;
};

extern std::vector<Date> AllTheDates;

#endif // DATE_H

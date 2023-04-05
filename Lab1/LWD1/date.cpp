#include "date.h"

QString Date::fileName;
QString Date::birthDay;
QDate Date::today = QDate::currentDate();
int Date::measure;
std::vector<Date> AllTheDates;

Date::Date()
{

}

void Date::openFile()
{
    fileName = QFileDialog::getOpenFileName();
    QFile file (fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is successfully open!\n";
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }

    QTextStream counter(&file);
    counter.seek(0);
    measure = 1;
    int spaces = 1;
    while(!counter.atEnd())
    {
        AllTheDates.resize(spaces);
        QString str = counter.readLine();
        QDate temp = QDate::fromString(str, "dd.MM.yyyy");
        if(temp.isValid())
        {
        AllTheDates[spaces - 1].setfullDate(str);
        measure++;
        ++spaces;
        }
        else
        {
            QMessageBox::warning(Q_NULLPTR,"Warning", "File containes incorrect data!");
            break;
        }
    }
    measure--;
    AllTheDates.resize(measure);
    file.close();
}

QString Date::getBirthDay()
{
    return birthDay;
}

void Date::setBirthDay(const QString &newBirthDay)
{
    birthDay = newBirthDay;
}

QString Date::getFileName()
{
    return fileName;
}

void Date::setFileName(const QString &newFileName)
{
    fileName = newFileName;
}



Date Date::NextDay()

{
    QDate tp = QDate::fromString(fullDate, "dd.MM.yyyy");
    tp = tp.addDays(1);
    QString str = tp.toString("dd.MM.yyyy");
    Date temp;
    temp.fullDate = str;
    return temp;
}

Date Date::PreviousDay()
{
    QDate tp = QDate::fromString(fullDate, "dd.MM.yyyy");
    tp = tp.addDays(-1);
    QString str;
    if (tp.year() < 0)
    {
       tp.setDate(std::abs(tp.year()), tp.month(), tp.day());
       str = tp.toString("dd.MM.yyyy") + " до н. э.";
    }
    else
    {
        str = tp.toString("dd.MM.yyyy");
    }
    Date temp;
    temp.fullDate = str;
    return temp;
}

bool Date::IsLeap()
{
     QDate tp = QDate::fromString(fullDate, "dd.MM.yyyy");

     return QDate::isLeapYear(tp.year());
}

short Date::WeekNumber()
   {
     QDate tp = QDate::fromString(fullDate, "dd.MM.yyyy");
       return tp.weekNumber();
   }

int Date::DaysTillYourBithday()
{
    QDate birth = QDate::fromString(birthDay, "dd.MM.yyyy");
    QDate temp = QDate::fromString(fullDate, "dd.MM.yyyy");
    if(birth.dayOfYear() == temp.dayOfYear())
    {
        return 0;
    }
    if(birth.dayOfYear() > temp.dayOfYear())
    {
        return birth.dayOfYear() - temp.dayOfYear();
    }
    if(birth.dayOfYear() < temp.dayOfYear())
    {
         birth.setDate(temp.year() + 1, birth.month(), birth.day());
         if ((!QDate::isLeapYear(temp.year()))&&QDate::isLeapYear(birth.year())&&birth.month()>2)
         {
             birth.addDays(1);
         }
         if (birth.month() == 2 && birth.day() == 29)
             return (temp.daysInYear()-temp.dayOfYear() + 59);
         else
             return (temp.daysInYear()-temp.dayOfYear() + birth.dayOfYear());
    }


}

int Date::Duration()
{
    QDate currentDate = QDate::fromString(fullDate, "dd.MM.yyyy");
    if (currentDate <= today)
    {
        return currentDate.daysTo(today);
    }
        else
    {
        return today.daysTo(currentDate);
    }

}

void Date::addNewDate(QString str)
{
    if(str == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Enter the deleted date!");
    }
    else
    {
    qDebug() << str;
    QDate temp = QDate::fromString(str, "dd.MM.yyyy");
    if(temp.isValid())
    {
         AllTheDates.resize(AllTheDates.size() + 1);

         AllTheDates[AllTheDates.size() - 1].setfullDate(str);
         QFile file (fileName);
         if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
         {
             qDebug() << "File is successfully open!\n";
         }
         else
         {
             qDebug() << "File isn't open!\n";
         }
         QTextStream ptr(&file);
         ptr.seek(-1);
         ptr << str << '\n';
          file.close();
    }
    else
        QMessageBox::warning(Q_NULLPTR, "Warning", "The entered date is incorrect!");
    return;
    }

}

void Date::deleteDate(QString str)
{
    if (str == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Enter the added date!");
    }
    else if(Date::getFileName() == "")
    {
         QMessageBox::warning(Q_NULLPTR,"Warning", "Open the file first!");
    }
    else
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
        {
            qDebug() << "File is successfully open!\n";
        }
        else
        {
            qDebug() << "File isn't open!\n";
        }

        QTextStream ptr(&file);
        ptr.seek(0);
        QString tmp;
        qint64 index = 0;
        bool flag = true;
        while(!ptr.atEnd())
        {
            index++;
            tmp = ptr.readLine();
            if(tmp == str)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
             QMessageBox::warning(Q_NULLPTR,"Warning", "The file does not contain the date you entered!");
        }
        else
        {
            index--;
            qint64 currentPos = ptr.pos();
            currentPos -= 12;
            QString newContain = ptr.readAll();
            ptr.seek(currentPos);
            ptr << newContain;
            file.resize(file.size() - 12);
            AllTheDates.erase(AllTheDates.begin() + index);
            file.close();
        }
    }

}

void Date::reverse(QString from, QString to)
{
    if(from == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Enter the replaced date!");
    }
    else if(to == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Enter the new date!");
    }
    else if(Date::getFileName() == "")
    {
         QMessageBox::warning(Q_NULLPTR,"Warning", "Open the file first!");
    }
    else
    {
        qDebug() << "from: " << from << '\n' << "to " << to << '\n';
        QDate qfrom = QDate::fromString(from, "dd.MM.yyyy");
        QDate qto = QDate::fromString(to, "dd.MM.yyyy");
        if(qfrom.isValid() && qto.isValid())
        {
            QFile file(fileName);
            if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
            {
                qDebug() << "File is successfully open!\n";
            }
            else
            {
                qDebug() << "File isn't open!\n";
            }

            QTextStream ptr(&file);
            ptr.seek(0);
            QString tmp;
            qint64 index = 0;
            bool flag = true;
            while(!ptr.atEnd())
            {
                index++;
                tmp = ptr.readLine();
                if(tmp == from)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                 QMessageBox::warning(Q_NULLPTR,"Warning", "The file does not contain the date you entered!");

            }
            else
            {
                index--;
                qint64 currentPos = ptr.pos();
                currentPos -= 12;
                ptr.seek(currentPos);
                ptr << to << '\n';
                AllTheDates[index].setfullDate(to);
                file.close();
            }
        }
        else
        {
            QMessageBox::warning(Q_NULLPTR, "Warning", "The entered date is incorrect!");
        }

    }
}

void Date::fullDelete()
{
    QFile file (fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "File is successfully open!\n";
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }
    QTextStream fout (&file);
    fout << "";
    file.close();
    qDebug() << "File is cleared!\n";
}

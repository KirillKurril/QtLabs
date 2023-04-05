#include "rpn.h"
#include "tablecomponent.h"

RPN::RPN()
{
vstack = new double[10000];
sstack = new QChar[10000]{'\0'};
vtopIndex = -1;
stopIndex = -1;
}

bool RPN::VisEmpty() const {
    return vtopIndex == -1;
}

bool RPN::VisFull() const {
    return vtopIndex == 9999;
}

void RPN::Vpush(double value) {
    if (VisFull()) {
        qDebug() << "Error: stack is full!\n";
        return;
    }
    ++vtopIndex;
    vstack[vtopIndex] = value;

}

void RPN::Vpop() {
    if (VisEmpty()) {
        qDebug() << "Error: stack is empty!\n";
    }

    vtopIndex--;
}

double RPN::Vtop() const {
    if (VisEmpty()) {
         qDebug() << "Error: stack is empty!\n";
        return '\0';
    }
    return vstack[vtopIndex];
}

QString RPN::process(tableComponent row)
{
    QString str = row.getExpression();
for(int i = 0; i < str.length(); i++)
{
        if(str[i] == 'a')
        {
        ans +="a";
        continue;
        }
            //vstack[vtopIndex++]=row.getA();
        if(str[i] == 'b')
        {
        ans += "b";
        continue;
        }
            //vstack[vtopIndex++]=row.getB();
        if(str[i] == 'c')
        {
        ans += "c";
        continue;
        }
            //vstack[vtopIndex++]=row.getC();
        if(str[i] == 'd')
        {
        ans += "d";
        continue;
        }
            //vstack[vtopIndex++]=row.getD();
        if(str[i] == 'e')
        {
        ans += "e";
        continue;
        }
            //vstack[vtopIndex++]=row.getE();
        if(str[i] == '(')
        {
            sstack[++stopIndex] = str[i];
            continue;
        }
        if (str[i] == ')')
        {
            while (1)
            {
                ans += sstack[stopIndex--];
                if(sstack[stopIndex] == '(')
                {
                    stopIndex--;
                    break;
                }
            }
            continue;
        }
        if(str[i] == '+' || str[i] == '-')
        {
            if(sstack[stopIndex] == ')' || sstack[stopIndex] == '(')
            {
                sstack[++stopIndex] = str[i];
                continue;
            }
            if(sstack[0] == '\0')
            {
                sstack[++stopIndex] = str[i];
                continue;
            }

            else
            {
                while(stopIndex != -1)
                {
                    ans += sstack[stopIndex--];
                    if(sstack[stopIndex] == ')')
                        break;
                    if(sstack[stopIndex] == '(')
                    {
                        stopIndex--;
                        break;
                    }

                }
                sstack[++stopIndex] = str[i];
                continue;
            }
        }
        if(str[i] == '*' || str[i] == '/')
        {
            if(sstack[0] == '\0')
            {
                sstack[++stopIndex] = str[i];
                continue;
            }
            if(sstack[stopIndex] == ')' || sstack[stopIndex] == '(')
            {
                sstack[++stopIndex] = str[i];
                continue;
            }
            else if (sstack[stopIndex] == '*' || sstack[stopIndex] == '/')
            {
                while(stopIndex != -1)
                {
                    ans += sstack[stopIndex--];
                    if(sstack[stopIndex] == ')')
                        break;
                    if(sstack[stopIndex] == '(')
                    {
                        stopIndex--;
                        break;
                    }

                }
                sstack[++stopIndex] = str[i];
                continue;
            }
            else if(sstack[stopIndex - 1] == '+' || sstack[stopIndex - 1] == '-')
            {
                sstack[++stopIndex] = str[i];
                continue;
            }
        }

}
while(stopIndex != -1)
{
     ans += sstack[stopIndex--];
}
return ans;
}

bool RPN::SisEmpty() const {
    return stopIndex == -1;
}

bool RPN::SisFull() const {
    return stopIndex == 9999;
}

void RPN::Spush(QChar ch) {
    if (SisFull()) {
        qDebug() << "Error: stack is full!\n";
        return;
    }
    ++stopIndex;
    sstack[stopIndex] = ch;
}

void RPN::Spop() {
    if (SisEmpty()) {
        qDebug() << "Error: stack is empty!\n";
    }
    stopIndex--;
}

QChar RPN::Stop() const {
    if (SisEmpty()) {
         qDebug() << "Error: stack is empty!\n";
        return '\0';
    }
    return sstack[stopIndex];
}

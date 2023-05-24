#ifndef PARSER_H
#define PARSER_H
#include<regex>
#include<QtWidgets>
#include"dstring.h"

class Parser
{
public:
    Parser();
    static QString parseVars(QString);
    static QString parseStructs(QString);
    static QString parsePrototypes(QString);
    static QString parseChanges(QString);
    static QString parseLocalVars(QString);
    static QString parseOverloads(QString);
    static QString parseDepth(QString);
    static QString parseLogic(QString);
};

#endif // PARSER_H

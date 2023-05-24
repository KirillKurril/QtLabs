#include "parser.h"

Parser::Parser()
{

}

QString Parser::parseVars(QString s)
{
    std::string code = s.toStdString().c_str();
    std::regex pattern(R"((?!MainWindow)([A-Z][A-Za-z_]*?|int|float|char|bool|qint16|qint32|qint8|qfloat16|std::string|string|QString|QChar)(\*)?\s+(\*)?(?!main)(\w+)((\s*=)\s*(?!new)(?!malloc)([^\n;]+))?\s*;)");
    std::unordered_map<QString, int> type_counts;
    std::cmatch match;
    QString result;
    while (std::regex_search(code.c_str(), match, pattern))
    {
        std::string type_name = match[1].str().c_str();
        std::string pointer = match[2].str().c_str();
        std::string pointer_ = " "; pointer_ += match[3].str().c_str();
        std::string variable_name = match[4].str().c_str();
        std::string default_value = match[7].str().c_str();
        type_counts[type_name.c_str()]++;
        result += type_name.c_str();
        if(pointer.c_str() == "*")
        {
         result+=pointer.c_str();
        }
        else if(pointer_.c_str() == " *")
        {
         result+=pointer_.c_str();
        }
        else
        {
        result += " ";
        }
        result += variable_name.c_str();
        if (!default_value.empty())
        {
            result+= " = ";
            result+=default_value.c_str();
        }
        result +="\n";
        code = match.suffix().first;
    }
    result+="\n\n";

    for (const auto& i : type_counts)
    {
        result += "Count vars of type ";
        result += i.first;
        result+= ": ";
        result+=QString::number(i.second);
        result += "\n";
    }
    if(result=="\n\n")return "none";
    return result;
}

QString Parser::parseStructs(QString s)
{
    std::string code = s.toStdString().c_str();
    std::string code1 = code;
    std::string code2 = code;
    QString result;

    std::regex class_pattern(R"(class\s+\w+\s*\{)");
    std::regex struct_pattern(R"(struct\s+\w+\s*\{)");
    std::regex array_pattern(R"((\w+\s+\w+\s*\[\s*\d+\s*\](\s*=\s*\{)?)|(new))");

    std::unordered_map<QString, int> count_map;
    std::cmatch match;


        while (std::regex_search(code.c_str(), match, class_pattern))
        {
        count_map["class"]++;
        code = match.suffix().first;
        }
        while (std::regex_search(code1.c_str() , match, struct_pattern))
        {
            count_map["struct"]++;
            code1 = match.suffix().first;
        }
        while (std::regex_search(code2.c_str(), match, array_pattern))
        {
            count_map["array"]++;
            code2 = match.suffix().first;
        }
    result+="Count of classes: ";
    result+=QString::number(count_map["class"]);
    result+="\n";
    result+="Count of structs: ";
    result+=QString::number(count_map["struct"]);
    result+="\n";
    result+="Count of arrays: ";
    result+=QString::number(count_map["array"]);
    return result;
}

QString Parser::parsePrototypes(QString s)
{
    std::string code = s.toStdString().c_str();
    QString result;
    std::regex pattern(R"(((?!\s*?(if|while|f|hile|ile|le|e|return|eturn|turn|urn|rn|n))\w+\s+\w*\s*\([^;{]*\))|(\s*\w+(\:\:)\w+\(\w*\)))");
    std::cmatch match;

        while(std::regex_search(code.c_str(), match, pattern))
        {
            result+=QString::fromStdString(match[0]);
            result+="\n";
            if(match.str()=="int main(int argc, char *argv[])"||match.str()=="int main()"
                    ||match.str()=="void main(int argc, char *argv[])"||match.str()=="void main()")break;
            code=match.suffix().first;
        }
        return result;
}



QString Parser::parseChanges(QString s)
{
    std::string code = s.toStdString().c_str();
    QString result;
    int line_num = 0;
    std::cmatch match;
    int pos = 0;
    std::regex pattern("(\\b\\w+\\b)((\\[[^\\]]*\\])*)\\s*=\\s*(.*);");
    while (std::regex_search(code.c_str(), match, pattern))
    {
        result+= "Line ";
        pos = code.find(match[0].str().c_str());
        line_num+= std::count(&code[0] , &code[0] + pos,'\n');
        result+= QString::number(line_num);
        result+= ": ";
        result+= QString::fromStdString(match.str());
        result+= "\n";
        code = match.suffix().first;
    }
    return result;
}

QString Parser::parseLocalVars(QString s)
{
    QString result;
        QStringList lineList = s.split("\n");
        int bracket = 0;
        for(int i = 0; i < lineList.size(); ++i)
        {
            if(bracket)
            {
                std::regex pattern("\\b(?!(struct|class|void|return)\\s)(\\w+)((\\s+)|(\\s*(\\*)\\s*))(\\w+)\\s*(=\\s*(\\S+))?\\s*(,\\s*\\w+\\s*(=\\s*(\\S+))?)*\;");
                std::string code = lineList[i].toStdString().c_str();
                std::cmatch match;
                while(std::regex_search(code.c_str(),match,pattern))
                {
                    result += "line " + QString::number(i + 1) + ": " + QString::fromStdString(match[0].str()) + "\n";
                    code = match.suffix().first;
                }
            }
            if(std::count(lineList[i].begin(), lineList[i].end(), '{')) bracket++;
            if(std::count(lineList[i].begin(), lineList[i].end(), '}')) bracket--;
        }
        return result;
}

QString Parser::parseOverloads(QString s)
{
    std::string code = s.toStdString();
    QString result;
    std::regex pattern("\\b([a-zA-Z_][a-zA-Z_0-9]*)\\s+([a-zA-Z_][a-zA-Z_0-9]*)\\s*\\(([^()]*)\\)\\s*\\{");
       std::map<std::string, std::vector<int>> functions;
       int function_count = 0;
       std::sregex_iterator search_start(code.cbegin(), code.cend(), pattern);
       std::sregex_iterator search_end;
       int line_number = 0;
       while (search_start != search_end) {
           std::string function_name = (*search_start)[2].str();
           std::string function_params = (*search_start)[3].str();
           auto match_start = code.begin() + (*search_start).position();
           auto match_end = code.begin() + (*search_start).position() + (*search_start).length();
           line_number=0;
           line_number += count(code.begin(), match_end,'\n');
           functions[function_name].push_back(line_number);
           ++search_start;
       }
       for (auto it = functions.cbegin(); it != functions.cend(); ++it) {
           if (it->second.size() > 1) {
               result+= "Function ";
               result+= QString::fromStdString(it -> first);
               result+=" is overloaded at lines:";
               for (auto line : it->second) {
                   result+=" ";
                   result+=QString::number(line);
                   function_count++;
               }
               result+='\n';
           }
       }
    result+="\n\nCount of overloded functions is ";
    result+=QString::number(function_count);
    return result;
}

QString Parser::parseDepth(QString s)
{
    std::string code = s.toStdString();
    QString result;
    std::regex pattern("\\b(else if|if|else)\\b");
    std::sregex_iterator search_start(code.begin(), code.end(), pattern);
    std::sregex_iterator search_end;
    int depth = 1;
    std::sregex_iterator search_start_past = search_start;
    while (search_start != search_end)
    {
        int index = search_start->position();
        int line = std::count(code.begin(),code.begin()+index, '\n') + 1;
        result+= "Branch at line ";
        result+= QString::number(line);
        result+=" is at depth ";
        result+=QString::number(depth);
        result+='\n';


        if ((*search_start)[1].str() == "if")
        {
            depth++;
        }
        else
        {
            depth--;
        }

        std::sregex_iterator search_start_past = search_start;
        ++search_start;
}
    return result;
}


QString Parser::parseLogic(QString s)
{
    std::string code = s.toStdString().c_str();
    QString result;
    std::regex pattern2("((const)\\s+(bool)\\s+([a-z]*)\\s*(=)\\s*(true|false)\\s*);");
    std::string buf;
    std::cmatch match2;
    while(std::regex_search(code.c_str(),match2,pattern2))
    {
        buf = "while(";
        buf += match2[4].str().c_str();
        buf.push_back(')');

        QStringList lineList = s.split('\n');
        for(int i=0;i<lineList.size(); ++i)
        {
            qDebug()<<buf.c_str()<<" ";
            qDebug()<<lineList[i].toStdString().c_str()<<Qt::endl;
            if(!strcmp(buf.c_str(),lineList[i].toStdString().c_str()))
            {
                result+=match2[1].str().c_str();
                result+='\n';
                result+=lineList[i];
                result+='\n';
            }
        }
        code = match2.suffix().first;
    }
    result+='\n';
    std::regex pattern("(while\\(true\\)|while\\(false\\))");
    std::cmatch match;
    while(std::regex_search(code.c_str(),match,pattern))
    {
        result+=match.str().c_str();
        result+='\n';
        code = match.suffix().first;
    }
    if(result=='\n') return "none";
    return result;
}

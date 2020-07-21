#include "calc.hpp"

double
Calc::solution(QString str)
{
    double retVal = 0.;
    int i         = 0;
    int endInd    = 0;

    while (str.contains('(') && str.contains(')'))
    {
        i      = str.indexOf('(', i);
        endInd = str.indexOf(')', i);
        retVal = solution(str.mid(i + 1, endInd - i - 1));
        str.remove(i, endInd - i + 1);
        str.insert(i, QString("").number(retVal));
        i = endInd;
    }

    bool ok = false;
    retVal  = str.toDouble(&ok);
    if (ok)
        return retVal;

    // Иначе
    QStringList strs;
    strs = str.split('+');
    if (strs.size() == 1)
    {
        strs = str.split('-');
        if (strs.size() == 1)
        {
            strs = str.split('*');
            if (strs.size() == 1)
            {
                strs = str.split('/');
                if (strs.size() == 1)
                {
                    // Такое бы отсеялось ещё на строчке
                    // if(ok) return retVal;
                    // ну да ладно. Можно exception выдавать при некорректно
                    // введённом числе
                    retVal = str.toDouble();
                }
                else
                {
                    retVal = solution(strs[0]);
                    for (int i = 1; i < strs.size(); i++)
                    {
                        retVal /= solution(strs[i]);
                    }
                }
            }
            else
            {
                retVal = solution(strs[0]);
                for (int i = 1; i < strs.size(); i++)
                {
                    retVal *= solution(strs[i]);
                }
            }
        }
        else
        {
            retVal = solution(strs[0]);
            for (int i = 1; i < strs.size(); i++)
            {
                retVal -= solution(strs[i]);
            }
        }
    }
    else
    {
        retVal = solution(strs[0]);
        for (int i = 1; i < strs.size(); i++)
        {
            retVal += solution(strs[i]);
        }
    }
    return retVal;
}

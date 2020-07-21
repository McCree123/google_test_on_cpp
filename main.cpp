#include "calc.hpp"
#include <QCoreApplication>
#include <iostream>

using namespace std;

int
main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString str("55 + 44 * (4 / 2 - 3 / 5) + 2 * 2");
    Calc* calc      = new Calc();
    QString workStr = str.replace(" ", "");
    double res      = calc->solution(workStr);
    cout << "Результат 1:" << endl << res << endl;

    str     = "55 + 44 * 4 / 2 - 3 / 5 + 2 * 2";
    workStr = str.replace(" ", "");
    res     = calc->solution(workStr);
    cout << "Результат 2:" << endl << res << endl;

    return a.exec();
}

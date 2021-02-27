#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Переводчик
    QTranslator translator;
    translator.load(":/Translation/msget89_ru.qm", ".");
    QApplication::installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}

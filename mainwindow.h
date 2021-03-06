#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>
#include <QDebug>
#include <QTabWidget>
#include <QHBoxLayout>
#include "maindata.h"
#include "database.h"
#include "controller.h"
#include "calibration.h"
#include "console.h"
#include "data.h"


class Console;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:

    void on_action_Connecting_triggered();
    void on_actionNew_triggered();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //в статус бар1
    void inStatusBar1(const QString&);
    //в статус бар2
    void inStatusBar2(const QString&);

private:
    Ui::MainWindow *ui;

    //вкладки
    QTabWidget* m_tabWidget = nullptr;
    //входные данные
    mainData* m_data = nullptr;

    //виджет настроек калибровки
    Calibration* m_calibration = nullptr;

    //виджет базы данных
    Database* m_database = nullptr;


    //отображение состония подключения к приборам
    QLabel *m_status1 = nullptr;//статус подключения QSatusBar
    QLabel *m_status2 = nullptr;//статус подключения QSatusBar

    // Контроллер управления приборами
    Controller* m_controller = nullptr;

    //Консоль вывода
    Console* m_console = nullptr;

    //Данные
    Data* pData;



};
#endif // MAINWINDOW_H

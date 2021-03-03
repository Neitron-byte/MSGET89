#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>
#include <devicedialog.h>
#include <QDebug>
#include <controller.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:

    void on_action_Connecting_triggered();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //отображение состония подключения к приборам
    QLabel *m_status1 = nullptr;//статус подключения QSatusBar
    QLabel *m_status2 = nullptr;//статус подключения QSatusBar

    //диалоговое окно настройки оборудования
    DeviceDialog* m_settingsDevices = nullptr;

    // Контроллер управления приборами
    Controller* m_controller = nullptr;
};
#endif // MAINWINDOW_H

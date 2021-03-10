#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
#include <dialogsettingscom.h>
#include <QDebug>
#include "Device/EnumModelsDevice.h"
#include "Device/cominterface.h"

namespace Ui {
class DeviceDialog;
}

//_____________Диалоговое окно настроек подключения к приборам______________//



class DeviceDialog : public QDialog
{
    Q_OBJECT

    //загрузка моделей
    void addModel() const;
    //загрузка типа подключения
    void addTypeConnected() const;

public:
    explicit DeviceDialog(QWidget *parent = nullptr);
    ~DeviceDialog();

private slots:
    void on_pushButton_settings_cal_clicked();

    void on_comboBox_device_cal_currentIndexChanged(int index);

    void on_comboBox_Device_Vol_currentIndexChanged(int index);

    void on_comboBox_type_connect_cal_currentIndexChanged(int index);

    void on_comboBox_Type_conVol_currentIndexChanged(int index);

    void on_pushButton_settings_Vol_clicked();

    void on_pushButton_Connect_to_Cal_clicked();

    void on_pushButton_Connect_to_vol_clicked();

signals:
    //создание приборов
    void createCalibrator(const enumModelCalibrator::models&);
    void createVoltmeter(const enumModelVoltmeter::models&);

    //создание интерфейса
    void createConnectionCalibrator(const enumTypeConnection::type&);
    void createConnectionVoltmeter(const enumTypeConnection::type&);

    //вызов диалогового окна настроек
    void showDialogSettingCal();
    void showDialogSettingVol();

    //сигнал на подключение
    void connectionCal();
    void connectionVol();

private:
    Ui::DeviceDialog *ui;
    //модели
    enumModelCalibrator::models m_calibrator;
    enumModelVoltmeter::models m_voltmeter;
    //тип подключения
    enumTypeConnection::type m_typeConnectCalibrator;
    enumTypeConnection::type m_typeConnectVoltmeter;

};

#endif // DEVICEDIALOG_H

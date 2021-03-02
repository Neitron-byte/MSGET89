#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
#include <dialogsettingscom.h>
#include <QDebug>
#include "Device/EnumModelsDevice.h"

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

private:
    Ui::DeviceDialog *ui;
    //модели
    enumModelDevice::models m_calibrator;
    enumModelDevice::models m_voltmeter;
    //тип подключения
    enumTypeConnection::type m_typeConnectCalibrator;
    enumTypeConnection::type m_typeConnectVoltmeter;

};

#endif // DEVICEDIALOG_H

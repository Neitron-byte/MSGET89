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

    void initModel();

public:
    explicit DeviceDialog(QWidget *parent = nullptr);
    ~DeviceDialog();

private slots:
    void on_pushButton_settings_cal_clicked();

private:
    Ui::DeviceDialog *ui;




};

#endif // DEVICEDIALOG_H

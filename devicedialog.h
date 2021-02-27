#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>


namespace Ui {
class DeviceDialog;
}

class DeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceDialog(QWidget *parent = nullptr);
    ~DeviceDialog();

private:
    Ui::DeviceDialog *ui;


};

#endif // DEVICEDIALOG_H

#include "devicedialog.h"
#include "ui_devicedialog.h"

void DeviceDialog::initModel()
{

    ui->comboBox_device_cal->addItem();
}

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);
}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_pushButton_settings_cal_clicked()
{


}

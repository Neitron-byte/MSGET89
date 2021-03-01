#include "devicedialog.h"
#include "ui_devicedialog.h"



void DeviceDialog::addModel()
{
    // m_ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);

    ui->comboBox_device_cal->addItem(QStringLiteral("H4-7"), enumsdevice::models::H4_7);
    ui->comboBox_Device_Vol->addItem("HP34420A",enumsdevice::models::HP34420);
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

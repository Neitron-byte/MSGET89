#include "devicedialog.h"
#include "ui_devicedialog.h"



void DeviceDialog::addModel() const
{
    ui->comboBox_device_cal->addItem("");
    ui->comboBox_device_cal->addItem(QStringLiteral("H4-7"), enumModelDevice::H4_7);
    ui->comboBox_Device_Vol->addItem("");
    ui->comboBox_Device_Vol->addItem(QStringLiteral("HP34420A"),enumModelDevice::HP34420);
}

void DeviceDialog::addTypeConnected() const
{
    ui->comboBox_type_connect_cal->addItem("");
    ui->comboBox_type_connect_cal->addItem(QStringLiteral("COM"), enumTypeConnection::COM);
    ui->comboBox_type_connect_cal->addItem(QStringLiteral("TCP"), enumTypeConnection::TCP);
    ui->comboBox_Type_conVol->addItem("");
    ui->comboBox_Type_conVol->addItem(QStringLiteral("COM"), enumTypeConnection::COM);
    ui->comboBox_Type_conVol->addItem(QStringLiteral("TCP"), enumTypeConnection::TCP);
}

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);

    this->setModal(true);
    this->addModel();
    this->addTypeConnected();

    qDebug()<<m_calibrator;

}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_pushButton_settings_cal_clicked()
{

    emit showDialogSettingCal();
      //connect( &dlg, SIGNAL( applied() ), SLOT( onApplied() ) );
}

void DeviceDialog::on_comboBox_device_cal_currentIndexChanged(int index)
{

    m_calibrator = ui->comboBox_device_cal->itemData(index).value<enumModelDevice::models>();
    //qDebug()<<m_calibrator;
    emit createCalibrator(m_calibrator);
}

void DeviceDialog::on_comboBox_Device_Vol_currentIndexChanged(int index)
{
    m_voltmeter = ui->comboBox_Device_Vol->itemData(index).value<enumModelDevice::models>();
    //qDebug()<<m_voltmeter;
    emit createVoltmeter(m_voltmeter);
}

void DeviceDialog::on_comboBox_type_connect_cal_currentIndexChanged(int index)
{
    m_typeConnectCalibrator = ui->comboBox_type_connect_cal->itemData(index).value<enumTypeConnection::type>();
    //qDebug()<<m_typeConnectCalibrator;
    emit createConnectionCalibrator(m_typeConnectCalibrator);
}

void DeviceDialog::on_comboBox_Type_conVol_currentIndexChanged(int index)
{
    m_typeConnectVoltmeter = ui->comboBox_Type_conVol->itemData(index).value<enumTypeConnection::type>();
    //qDebug()<<m_typeConnectVoltmeter;
    emit createConnectionVoltmeter(m_typeConnectVoltmeter);
}

void DeviceDialog::on_pushButton_settings_Vol_clicked()
{
    emit showDialogSettingVol();
}

void DeviceDialog::on_pushButton_Connect_to_Cal_clicked()
{
    emit connectionCal();
}

void DeviceDialog::on_pushButton_Connect_to_vol_clicked()
{
    emit connectionVol();
}

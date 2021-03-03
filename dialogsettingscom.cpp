#include "dialogsettingscom.h"
#include "ui_dialogsettingscom.h"

void DialogSettingsCom::fillPortsParameters()
{

    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);


    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}

void DialogSettingsCom::fillPortsInfo()
{
    ui->comBox ->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->comBox->addItem(info.portName());
    }
}

DialogSettingsCom::DialogSettingsCom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettingsCom)
{
    ui->setupUi(this);
    qDebug() << "Constructor settings COM";
    this->fillPortsParameters();
    this->fillPortsInfo();
}

DialogSettingsCom::~DialogSettingsCom()
{
    delete ui;
    qDebug() << "Distructor settings COM";
}

QString DialogSettingsCom::getNameCom()
{
    return ui->comBox->currentText();

}

QSerialPort::BaudRate DialogSettingsCom::getBaudRate()
{
    return static_cast<QSerialPort::BaudRate>(
                ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
}

QSerialPort::DataBits DialogSettingsCom::getDataBits()
{
    return static_cast<QSerialPort::DataBits>(
                ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
}

QSerialPort::StopBits DialogSettingsCom::getStopBits()
{
    return static_cast<QSerialPort::StopBits>(
                ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
}

QSerialPort::Parity DialogSettingsCom::getParity()
{
    return static_cast<QSerialPort::Parity>(
                ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
}

QSerialPort::FlowControl DialogSettingsCom::getFlow()
{
    return static_cast<QSerialPort::FlowControl>(
                ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt());
}




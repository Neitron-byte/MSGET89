#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_settingsDevices(new DeviceDialog),
      m_controller(new Controller)

{
    ui->setupUi(this);

    this->setWindowTitle(tr("Software MS-GET89"));

    //Statusbar
    m_status1 = new QLabel(this);
    ui->statusbar->addWidget(m_status1);
    m_status2 = new QLabel(this);
    ui->statusbar->addWidget(m_status2);

    //m_status1->setText("Create status1");
    //m_status2->setText("Create status2");

    //____________сигналы слоты_______________________//
    //создание приборов
    connect(m_settingsDevices,SIGNAL(createCalibrator(enumModelDevice::models)),m_controller, SLOT(createCalibrator(enumModelDevice::models)));
    connect(m_settingsDevices,SIGNAL(createVoltmeter(enumModelDevice::models)),m_controller,SLOT(createVoltmeter(enumModelDevice::models)));
    //создание интерфейса подключения
    connect(m_settingsDevices,SIGNAL(createConnectionCalibrator(enumTypeConnection::type)),m_controller,SLOT(createInterfaceCalibrator(enumTypeConnection::type)));
    connect(m_settingsDevices,SIGNAL(createConnectionVoltmeter(enumTypeConnection::type)),m_controller,SLOT(createInterfaceVoltmeter(enumTypeConnection::type)));

}

MainWindow::~MainWindow()
{
    if(m_settingsDevices){

        delete m_settingsDevices;
    }
    if(ui){
        delete ui;
    }
    if(m_controller){
    delete m_controller;
    }
}


void MainWindow::on_action_Connecting_triggered()
{
    m_settingsDevices->show();

}

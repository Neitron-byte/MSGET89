#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_settingsDevices(new DeviceDialog)

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



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Connecting_triggered()
{
    m_settingsDevices->show();

}

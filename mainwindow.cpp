#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_controller(new Controller)

{
    ui->setupUi(this);

    this->setWindowTitle(tr("Software MS-GET89"));

    //Statusbar
    m_status1 = new QLabel(this);
    ui->statusbar->addWidget(m_status1);
    m_status2 = new QLabel(this);
    ui->statusbar->addWidget(m_status2);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(m_controller){
    delete m_controller;
    }
}


void MainWindow::on_action_Connecting_triggered()
{

    m_controller->showDialogSettingDevice();
}

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



    //получение сообщений о состонии подключения в статус бар
    connect(m_controller,SIGNAL(signalStatus1(QString)),this,SLOT(inStatusBar1(QString)));
    connect(m_controller,SIGNAL(signalStatus2(QString)),this,SLOT(inStatusBar2(QString)));



}

MainWindow::~MainWindow()
{
    if(m_controller){
    delete m_controller;
    }
    if(m_database){
        delete m_database;
    }
    if(m_data){
        delete m_data;
    }
    if (m_tabWidget){
        delete m_tabWidget;
    }
    delete ui;
}






void MainWindow::inStatusBar1(const QString & message)
{

   m_status1->setText(message);

}

void MainWindow::inStatusBar2(const QString & message)
{
    m_status2->setText(message);
}


void MainWindow::on_action_Connecting_triggered()
{

    m_controller->showDialogSettingDevice();
}

void MainWindow::on_actionNew_triggered()
{
    ui->menu_Settings_Device->setEnabled(true);

    m_tabWidget = new QTabWidget(this);
    m_data = new mainData();
    m_tabWidget->addTab(m_data,tr("Data") );
    m_database = new Database();
    m_tabWidget->addTab(m_database, tr("Database"));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_tabWidget);
    this->setCentralWidget(m_tabWidget);
    this->setLayout(layout);
    this->show();
}



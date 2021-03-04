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

    connect(m_controller,SIGNAL(signalStatus1(QString)),this,SLOT(inStatusBar1(QString)));
    connect(m_controller,SIGNAL(signalStatus2(QString)),this,SLOT(inStatusBar2(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tabWidget;
    //delete m_dataWidget;

    if(m_controller){
    delete m_controller;
    }

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
    m_tabWidget = new QTabWidget(this);
    m_tabWidget->addTab(new mainData,tr("Data") );
    m_tabWidget->addTab(new mainData,tr("Database"));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_tabWidget);

    this->setLayout(layout);
    this->show();

    //ui->setupUi(m_tabWidget);

}

#include "maindata.h"
#include "ui_maindata.h"

void mainData::SetLenght()
{
    ui->doubleSpinBox_temp->setValue(20);
    ui->doubleSpinBox_temp->setMinimum(0);
    ui->doubleSpinBox_temp->setMaximum(40);
    ui->doubleSpinBox_temp->setSingleStep(0.1);

    ui->lineEdit_full_Name->setMaxLength(50);
    ui->lineEdit_Model_Ver_Device->setMaxLength(10);
    ui->lineEdit_serialNum_Dev->setMaxLength(15);
    ui->lineEdit_company->setMaxLength(10);

}



mainData::mainData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainData)
{
    ui->setupUi(this);

    //TimeDate
    m_timerinterval = 1000;
    m_idTimer = startTimer(m_timerinterval);
    time = QTime::currentTime();
    date = QDate::currentDate();
    slot_set_Time(time.toString(Qt::SystemLocaleLongDate));
    slot_set_Date(date.toString(Qt::SystemLocaleLongDate));

    //ограничения на ввод данных
    this->SetLenght();


}

mainData::~mainData()
{
    delete ui;
}

void mainData::slot_set_Time(const QString strTime)
{
    ui->label_Time->setText(strTime);
}

void mainData::slot_set_Date(const QString strDate)
{
    ui->label_Date->setText(strDate);
}

void mainData::timerEvent(QTimerEvent *event)
{
    time = QTime::currentTime();
    date = QDate::currentDate();
    slot_set_Time(time.toString(Qt::SystemLocaleLongDate));
    slot_set_Date(date.toString(Qt::SystemLocaleLongDate));
}



void mainData::on_pushButton_start_calibration_clicked()
{
      Data* pData = Data::getData();
      pData->setTemp(ui->doubleSpinBox_temp->value());
      pData->setFullName(ui->lineEdit_full_Name->text());
      pData->setModel(ui->lineEdit_Model_Ver_Device->text());
      pData->setSerial(ui->lineEdit_serialNum_Dev->text());
      pData->setCompany(ui->lineEdit_company->text());

}

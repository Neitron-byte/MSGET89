#include "maindata.h"
#include "ui_maindata.h"

uint mainData::m_counterNumVerification = 0;

void mainData::SetLenght()
{
    ui->doubleSpinBox_temp->setValue(20);
    ui->doubleSpinBox_temp->setMinimum(0);
    ui->doubleSpinBox_temp->setMaximum(40);
    ui->doubleSpinBox_temp->setSingleStep(0.1);

    ui->lineEdit_full_Name->setMaxLength(10);
    ui->lineEdit_Model_Ver_Device->setMaxLength(5);
    ui->lineEdit_serialNum_Dev->setMaxLength(5);
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

void mainData::addRezulttoVector(float val)
{
    m_vectorRezultVal.push_back(val);

    m_counterNumVerification++;
}

void mainData::addTypetoVector(int freq)
{
    m_vectorTypeVer.push_back(freq);
}

void mainData::setVoltage(float volt)
{
    m_voltage = volt;
}

void mainData::print()
{
        if(!m_vectorRezultVal.isEmpty()){
        QAxObject* pword = new QAxObject("Word.Application");
        QAxObject* pdoc = pword->querySubObject("Documents");
        pdoc = pdoc->querySubObject("add()");

        pword->setProperty("Visible",true);

          }
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

      m_temp = ui->doubleSpinBox_temp->value();
      m_fullName = ui->lineEdit_full_Name->text();
      m_model = ui->lineEdit_Model_Ver_Device->text();
      m_serialNum = ui->lineEdit_serialNum_Dev->text();
      m_company = ui->lineEdit_company->text();
      emit signalFromMainToConsole(("Temperature: "+QString::number(m_temp)).toLocal8Bit());
      emit signalFromMainToConsole(("Full name: " + m_fullName).toLocal8Bit());
      emit signalFromMainToConsole(("Model: "+ m_model).toLocal8Bit());
      emit signalFromMainToConsole(("Serial number" + m_serialNum).toLocal8Bit());
      emit signalFromMainToConsole(("Company: " + m_company).toLocal8Bit());
}

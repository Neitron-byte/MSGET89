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
        //if(!m_vectorRezultVal.isEmpty()){
        QAxObject* pword = new QAxObject("Word.Application");
        QAxObject* pdoc = pword->querySubObject("Documents");
        pdoc = pdoc->querySubObject("Add()");

//        QAxObject* pFont = pword->querySubObject("Font");
//        pFont->setProperty("Size",14);

        QAxObject* prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",0,100);
        prange->setProperty("Text",tr("Protocol verification"));
        QAxObject* pFont = prange->querySubObject("Font");
        pFont->setProperty("Size",14);
        pFont->setProperty("Name", "Times New Roman");

        QAxObject *alignment_range = prange->querySubObject("ParagraphFormat");
           alignment_range->setProperty("Alignment", "wdAlignParagraphCenter");
           alignment_range->setProperty("SpaceAfter", 0);

        prange->dynamicCall("InsertParagraphAfter()");
        prange->dynamicCall("InsertParagraphAfter()");

        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",101,200);
        prange->setProperty("Text",tr("Time: ")+time.toString(Qt::SystemLocaleLongDate));

        alignment_range = prange->querySubObject("ParagraphFormat");
        alignment_range->setProperty("Alignment", "wdAlignParagraphLeft");
        alignment_range->setProperty("SpaceAfter", 0);


        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text","              ");

        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Date: ")+date.toString(Qt::SystemLocaleLongDate));

        prange->dynamicCall("InsertParagraphAfter()");
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Temperature: ")+ QString::number(m_temp));

        prange->dynamicCall("InsertParagraphAfter()");
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Full name: ")+ m_fullName);

        prange->dynamicCall("InsertParagraphAfter()");
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Model: ")+ m_model);

        prange->dynamicCall("InsertParagraphAfter()");
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Serial number: ")+ m_serialNum);

        prange->dynamicCall("InsertParagraphAfter()");
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",201,300);
        prange->setProperty("Text",tr("Company: ")+ m_company);
        prange->dynamicCall("InsertParagraphAfter()");

        for (int i = 0; i < m_vectorRezultVal.size(); ++i) {
            qDebug()<<m_vectorRezultVal.size();
            prange = pdoc->querySubObject("Range()");
            prange->dynamicCall("SetRange(int,int)",201,300);
            if(m_vectorTypeVer[i] == 0){
                prange->setProperty("Text",tr("DC-AC: ")+ QString::number(m_vectorRezultVal[i]));
            } else {
                prange->setProperty("Text",tr("AC-AC: ")+ QString::number(m_vectorRezultVal[i]));
            }

            prange->dynamicCall("InsertParagraphAfter()");
        }

        pword->setProperty("Visible",true);

          //}
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
      emit signalFromMainToConsole((tr("Temperature: ")+QString::number(m_temp)).toLocal8Bit());
      emit signalFromMainToConsole((tr("Full name: ") + m_fullName).toLocal8Bit());
      emit signalFromMainToConsole((tr("Model: ")+ m_model).toLocal8Bit());
      emit signalFromMainToConsole((tr("Serial number") + m_serialNum).toLocal8Bit());
      emit signalFromMainToConsole((tr("Company: ") + m_company).toLocal8Bit());
}

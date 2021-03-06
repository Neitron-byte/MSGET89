#include "calibration.h"
#include "ui_calibration.h"


void Calibration::addItem()
{
    ui->comboBox_calibration_Dev_2->addItem(tr("None"));
    ui->comboBox_calibration_Dev_2->addItem(tr("DC->AC"));
    ui->comboBox_calibration_Dev_2->addItem(tr("AC1kHz->NHz"));



}

void Calibration::setLenght()
{
    ui->doubleSpinBox_voltage->setMinimum(0);
    ui->doubleSpinBox_voltage->setMaximum(100);
    ui->doubleSpinBox_voltage->setSingleStep(0.1);

    ui->spinBox_number_meas_2->setMinimum(1);
    ui->spinBox_number_meas_2->setMaximum(10);
    ui->spinBox_number_meas_2->setSingleStep(1);

    ui->spinBox_freq->setMinimum(0);
    ui->spinBox_freq->setMaximum(100);
    ui->spinBox_freq->setSingleStep(1);

   ui->doubleSpinBox_correct->setMinimum(0);
   ui->doubleSpinBox_correct->setMaximum(10);
   ui->doubleSpinBox_correct->setDecimals(5);
   ui->doubleSpinBox_correct->setSingleStep(0.00001);

}

void Calibration::setParametersCalibration()
{
    if(m_calibration){
        m_calibration->setNumberMeasurement(ui->spinBox_number_meas_2->value());


         m_calibration->setCorrect(ui->doubleSpinBox_correct->value());


        Verification_U* pVer = dynamic_cast<Verification_U*>(m_calibration);
        if(pVer){
            pVer->setVoltage(ui->doubleSpinBox_voltage->value());
            pVer->setFrequency(ui->spinBox_freq->value());
        }


        if(ui->checkBox_ref_square->isChecked()){
            m_calibration->setTypeRef(2);
        } else {
            m_calibration->setTypeRef(1);
        }

        if(ui->checkBox_cal_squa->isChecked()){
            m_calibration->setTypeCalib(2);
        } else {
            m_calibration->setTypeCalib(1);
        }

        Data* pData = Data::getData();
        pData->setVoltage(ui->doubleSpinBox_voltage->value());
        pData->setFrequency(ui->spinBox_freq->value());

    }
}

Calibration::Calibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calibration)
{
    ui->setupUi(this);

    //добавление в инетерфейс
    this->addItem();

    this->setLenght();

}


Calibration::~Calibration()
{
    delete ui;
}

//const Verification *Calibration::getCalibration()
//{
//    return m_calibration;
//}


void Calibration::on_comboBox_calibration_Dev_2_currentIndexChanged(int index)
{
    if (index == 1){

        m_calibration = new Verification_U_DC_AC();
        ui->label_freq->setEnabled(false);
        ui->spinBox_freq->setEnabled(false);


    }
    if (index == 2 ){

        m_calibration = new Verification_U_AC_AC();
        ui->label_freq->setEnabled(true);
        ui->spinBox_freq->setEnabled(true);


    }
    if (index){

    emit setCalibration(m_calibration);
    }

}

void Calibration::on_pushButton_start_calibration_2_clicked()
{
    if(ui->comboBox_calibration_Dev_2->currentIndex()){
    this->setParametersCalibration();
    emit signalStartCalibration();
    }
}

void Calibration::on_pushButton_print_clicked()
{
    Data* pData = Data::getData();
    pData->print();
}

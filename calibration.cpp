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

    ui->spinBox_number_meas_2->setMinimum(3);
    ui->spinBox_number_meas_2->setMaximum(10);
    ui->spinBox_number_meas_2->setSingleStep(1);


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


void Calibration::on_comboBox_calibration_Dev_2_currentIndexChanged(int index)
{
    if (index == 1){

        m_calibration = new Verification_U_DC_AC();
    }
    if (index == 2 ){

        m_calibration = new Verification_U_AC_AC();
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

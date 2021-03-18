#include "verification.h"

int Verification::Count = 0;

void Verification_U_DC_AC::startVerification(Calibrator * calibrator, Voltmeter * voltmeter)
{
    qDebug()<<"Start calibration DC_AC";
    qDebug()<<m_numberMeasurements
           <<m_Voltage
          <<m_correctRef
         <<m_TypeRefDev
        <<m_TypeCalDev;


    //проверка на ненулевые указатели
    if(calibrator && voltmeter){

    //проверка статуса подключения приборов
    if(calibrator->getStatusConnect() && voltmeter->getStatusConnect()){



        preparingAnArray();

         //инициализация диалогового окна прогресса
        int max = m_numberMeasurements*12;

        m_pprd = new QProgressDialog(tr("Start calibration"),0,0,max);
        m_pprd->setMinimumDuration(0);

        m_pprd->setWindowTitle(tr("Calibration progress"));
        m_pprd->setWindowModality(Qt::WindowModal);
        m_pprd->setAutoReset(true);

        for (uint i = 0; i < m_numberMeasurements; ++i) {

            uint Counter = 0;
            qDebug() << "Цикл " << i;
            m_pprd->setLabelText(tr("Set DC U: %1 F: 1kHz").arg(m_Voltage));
            if (calibrator->setFreqValue(m_Voltage,1)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }

            QThread::msleep(m_timeOut);

            Counter++;
            m_pprd->setLabelText(tr("Set DC U: %1").arg(m_Voltage));
            if (calibrator->setValue(m_Voltage)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }

            QThread::msleep(m_timeOut);

            Counter++;
             m_pprd->setLabelText(tr("Set DC -U: %1").arg(m_Voltage));
            if (calibrator->setValue(-m_Voltage)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }

            QThread::msleep(m_timeOut);

            Counter++;
            m_pprd->setLabelText(tr("Set DC U: %1 F: 1kHz").arg(m_Voltage));
            if (calibrator->setFreqValue(m_Voltage,1)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }


            calculation(i);



    }

    calculationRezult();
    delete m_pprd;
    Count = 0;
    qDebug()<<"End process";

    QMessageBox* pmbx =
                        new QMessageBox("MessageBox",
                        "SAVE?",
                        QMessageBox::Information,
                        QMessageBox::Yes,
                        QMessageBox::No,
                        0
                        );
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Yes)
    {
      //Нажата кнопка Yes
        print();

    }

        }
    }
}


void Verification_U_AC_AC::startVerification(Calibrator * calibrator, Voltmeter * voltmeter)
{
    qDebug()<<"Start calibration AC_AC";
    qDebug()<<m_numberMeasurements
           <<m_Voltage
          <<m_correctRef
         <<m_TypeRefDev
        <<m_TypeCalDev;
}

float Verification::calculation(uint iteration)
{
    //рассчет погрешности для эталона
    float averageRefDC = (m_arrForMeasurement[0][iteration][1] + m_arrForMeasurement[0][iteration][2])/2;
    float averageRefAC = (m_arrForMeasurement[0][iteration][0] + m_arrForMeasurement[0][iteration][3])/2;
    float deltaRef = (averageRefAC - averageRefDC)/ (m_TypeRefDev * averageRefDC);

    //рассчет погрешности для поверяемого прибора

    float averageDC = (m_arrForMeasurement[1][iteration][1] + m_arrForMeasurement[1][iteration][2])/2;
    float averageAC = (m_arrForMeasurement[1][iteration][0] + m_arrForMeasurement[1][iteration][3])/2;

    float deltaVer = (averageAC - averageDC)/ (m_TypeCalDev * averageDC);

    //разность погрешностей

    float RezultDelta = deltaVer - deltaRef;
    qDebug() << "Промежуточный результат Итерации " << iteration <<" " << RezultDelta;
    m_arrForRezultForEachIteration[iteration] = RezultDelta;
}

void Verification::calculationRezult()
{
    float Summ = 0;

    for (int i = 0; i < m_numberMeasurements; ++i) {
        Summ+=m_arrForRezultForEachIteration[i];
    }

        m_Rezult = Summ/m_numberMeasurements + m_correctRef;
        qDebug() << "Результат Поверки: " << m_Rezult;
}

void Verification::setIncValue()
{
    ++Count;
    m_pprd->setValue(Count);
}

void Verification::preparingAnArray()
{
    //подготовка массива для показаний
    m_arrForRezultForEachIteration = new float [m_numberMeasurements];

    for (int i = 0; i < m_numberMeasurements; ++i) {
        m_arrForRezultForEachIteration[i] = 0;
    }

    //подготовка массива для приёма данных
    m_arrForMeasurement = new float**[2];

    for (int i = 0; i < 2; ++i) {
        m_arrForMeasurement[i] = new float* [m_numberMeasurements];
        for (int j = 0; j < m_numberMeasurements; ++j) {
            m_arrForMeasurement[i][j] = new float [4];
        }
    }


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m_numberMeasurements; ++j) {
            for (int k = 0; k < 4; ++k) {
                m_arrForMeasurement[i][j][k] = 0;
            }

        }
    }


}

void Verification::print()
{
    std::cout << "Rezults measurement: " << std::endl;
    for (int j = 0; j < m_numberMeasurements; ++j) {

        for (int i = 0; i < 4; ++i) {
            for (int k = 0; k < 2; ++k) {
                std::cout << m_arrForMeasurement[k][j][i];
            }
            std::cout << std::endl;
        }
        std::cout << "Rezult" << m_arrForRezultForEachIteration[j] << std::endl;

    }
}

Verification::~Verification()
{
    for (int i = 0; i < m_numberMeasurements; ++i) {
        for (int j = 0; j < 4; ++j) {
            delete [] m_arrForMeasurement[i][j];
        }
        delete[] m_arrForMeasurement[i];
    }
        delete[] m_arrForMeasurement;

    delete[] m_arrForRezultForEachIteration;


}

void Verification::setNumberMeasurement(uint number)
{
    m_numberMeasurements = number;
}

void Verification::setCorrect(float correct)
{
    m_correctRef = correct;
}

void Verification::setTypeRef(uint typeRef)
{
    m_TypeRefDev = typeRef;
}

void Verification::setTypeCalib(uint typeCal)
{
    m_TypeCalDev = typeCal;
}

void Verification::receiversMeasurement(Voltmeter * voltmeter, int iteration, uint counter)
{


    m_pprd->setLabelText(tr("receive data CH1"));
    float val1 = voltmeter->receiveValue(1);
    if(val1 == 0) return;
    m_arrForMeasurement[0][iteration][counter] = val1;
    this->setIncValue();
   qDebug()<<"1 канал" << val1;
   QThread::msleep(m_timeOut);

    m_pprd->setLabelText(tr("receive data CH2"));
    float val2 = voltmeter->receiveValue(2);
    if(val2 == 0) return;
    qDebug()<<"Cохранение";
     m_arrForMeasurement[1][iteration][counter] = val2;

     this->setIncValue();
    qDebug()<<"2 канал" << val2;

}

void Verification_U::setVoltage(float volt)
{

        m_Voltage = volt;

}

void Verification_U::setFrequency(uint freq)
{
    m_Frequency = freq;
}

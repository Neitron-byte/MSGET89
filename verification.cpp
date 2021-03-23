#include "verification.h"

int Verification::Count = 0;

Verification_U_DC_AC::~Verification_U_DC_AC()
{
    qDebug()<< "VerU_DC_AC dist";
}

void Verification_U_DC_AC::startVerification(Calibrator * calibrator, Voltmeter * voltmeter)
{
    qDebug()<<"Start calibration DC_AC";

    //проверка на ненулевые указатели
    if(calibrator && voltmeter){

    //проверка статуса подключения приборов
    if(calibrator->getStatusConnect() && voltmeter->getStatusConnect()){



        this->preparingAnArray();

         //инициализация диалогового окна прогресса
        int max = m_numberMeasurements*m_stepMeasurement*3;
        qDebug()<<"Step "<<m_stepMeasurement;
        m_pprd = new QProgressDialog(tr("Start calibration DC-AC"),0,0,max);
        m_pprd->setMinimumDuration(0);

        m_pprd->setWindowTitle(tr("Calibration progress"));
        m_pprd->setWindowModality(Qt::WindowModal);
        m_pprd->setAutoReset(true);

        for (uint i = 0; i < m_numberMeasurements; ++i) {



            uint Counter = 0;
            qDebug() << "Цикл " << i;
            m_pprd->setLabelText(tr("Set AC U: %1 V F: 1kHz").arg(m_Voltage));

            if (calibrator->setFreqValue(m_Voltage,1)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }



            QThread::msleep(m_timeOut);


            Counter++;
            m_pprd->setLabelText(tr("Set DC +U: %1 V").arg(m_Voltage));

            if (calibrator->setValue(m_Voltage)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }


            QThread::msleep(m_timeOut);

            Counter++;
             m_pprd->setLabelText(tr("Set DC -U: %1 V").arg(m_Voltage));

            if (calibrator->setValue(-m_Voltage)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }

            QThread::msleep(m_timeOut);

            Counter++;
            m_pprd->setLabelText(tr("Set AC U: %1 V F: 1kHz").arg(m_Voltage));

            if (calibrator->setFreqValue(m_Voltage,1)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }


            this->calculation(i);

    }

    this->calculationRezult();



    Count = 0;


            delete m_pprd;
            this->saveRezult();

        }
    }

}

void Verification_U_DC_AC::preparingAnArray()
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
            m_arrForMeasurement[i][j] = new float [m_stepMeasurement];
        }
    }


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m_numberMeasurements; ++j) {
            for (int k = 0; k < m_stepMeasurement; ++k) {
                m_arrForMeasurement[i][j][k] = 0;
            }
        }
    }
}

void Verification_U_DC_AC::calculation(uint iteration)
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


Verification_U_AC_AC::~Verification_U_AC_AC()
{
    qDebug()<< "VerU_DC_AC Bass dist";

}

void Verification_U_AC_AC::startVerification(Calibrator * calibrator, Voltmeter * voltmeter)
{
    qDebug() << "Ver AC-AC";
    //проверка на ненулевые указатели
    if(calibrator && voltmeter){

    //проверка статуса подключения приборов
    if(calibrator->getStatusConnect() && voltmeter->getStatusConnect()){



        this->preparingAnArray();

         //инициализация диалогового окна прогресса
        int max = m_numberMeasurements*m_stepMeasurement*3;
        qDebug()<<"Step "<<m_stepMeasurement;
        m_pprd = new QProgressDialog(tr("Start calibration AC-AC"),0,0,max);
        m_pprd->setMinimumDuration(0);

        m_pprd->setWindowTitle(tr("Calibration progress"));
        m_pprd->setWindowModality(Qt::WindowModal);
        m_pprd->setAutoReset(true);

        for (uint i = 0; i < m_numberMeasurements; ++i) {


            uint Counter = 0;
            m_pprd->setLabelText(tr("Set AC U: %1 V F: %2 kHz").arg(m_Voltage).arg(m_Frequency));

            if (calibrator->setFreqValue(m_Voltage,m_Frequency)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }


            QThread::msleep(m_timeOut);

            Counter++;
            m_pprd->setLabelText(tr("Set AC U: %1 V F: 1 kHz").arg(m_Voltage));

            if (calibrator->setFreqValue(m_Voltage,1)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }



            QThread::msleep(m_timeOut);

            Counter++;
            m_pprd->setLabelText(tr("Set AC U: %1 V F: %2 kHz").arg(m_Voltage).arg(m_Frequency));

            if (calibrator->setFreqValue(m_Voltage,m_Frequency)){
               this->setIncValue();
                QThread::msleep(m_timeOut);
                receiversMeasurement(voltmeter,i,Counter);
            }


            this->calculation(i);

    }

    this->calculationRezult();



    Count = 0;


    delete m_pprd;

    this->saveRezult();

        }
    }

}

void Verification_U_AC_AC::preparingAnArray()
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
            m_arrForMeasurement[i][j] = new float [m_stepMeasurement];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m_numberMeasurements; ++j) {
            for (int k = 0; k < m_stepMeasurement; ++k) {
                m_arrForMeasurement[i][j][k] = 0;
            }
        }
    }

qDebug()<<"Array";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m_numberMeasurements; ++j) {
            for (int k = 0; k < m_stepMeasurement; ++k) {
                std::cout << m_arrForMeasurement[i][j][k] << " ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }

}

void Verification_U_AC_AC::calculation(uint iteration)
{
    //рассчет погрешности для эталона

    float averageRefAC = (m_arrForMeasurement[0][iteration][0] + m_arrForMeasurement[0][iteration][2])/2;
    float deltaRef = (averageRefAC - m_arrForMeasurement[0][iteration][1])/ (m_TypeRefDev * m_arrForMeasurement[0][iteration][1]);

    //рассчет погрешности для поверяемого прибора


    float averageAC = (m_arrForMeasurement[1][iteration][0] + m_arrForMeasurement[1][iteration][2])/2;
    float deltaVer = (averageAC - m_arrForMeasurement[1][iteration][1])/ (m_TypeCalDev * m_arrForMeasurement[1][iteration][1]);

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

        m_rezult = Summ/m_numberMeasurements + m_correctRef;
        qDebug() << "Результат Поверки: " << m_rezult;


}

void Verification::setIncValue()
{
    ++Count;
    m_pprd->setValue(Count);
}

void Verification::saveRezult()
{
    Data* pData = Data::getData();
    pData->addRezult(m_rezult);
}



Verification::~Verification()
{
    if(m_arrForMeasurement){
        qDebug()<<"Ver Bass dist";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m_numberMeasurements; ++j) {
                delete[] m_arrForMeasurement[i][j];
                qDebug()<<"delete "<< i << j;
            }
            delete[] m_arrForMeasurement[i];
            qDebug()<<"delete "<< i;
        }

           delete[] m_arrForMeasurement;
           qDebug()<<"delete end";
            m_arrForMeasurement = nullptr;

    }

    if (m_arrForRezultForEachIteration){
        delete[] m_arrForRezultForEachIteration;
        m_arrForRezultForEachIteration = nullptr;
    }

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

    qDebug()<< "Channel 1: " << val1;
    m_arrForMeasurement[0][iteration][counter] = val1;
    this->setIncValue();


   QThread::msleep(m_timeOut);

    m_pprd->setLabelText(tr("receive data CH2"));
    float val2 = voltmeter->receiveValue(2);

    qDebug()<< "Channel 2: " << val2;
    m_arrForMeasurement[1][iteration][counter] = val2;
    this->setIncValue();

}

void Verification_U::setVoltage(float volt)
{

        m_Voltage = volt;

}

void Verification_U::setFrequency(uint freq)
{
    m_Frequency = freq;
}



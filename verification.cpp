#include "verification.h"


void Verification_U_DC_AC::startVerification(Calibrator * calibrator, Voltmeter * voltmeter)
{
    qDebug()<<"Start calibration DC_AC";
    qDebug()<<m_numberMeasurements
           <<m_Voltage
          <<m_correctRef
         <<m_TypeRefDev
        <<m_TypeCalDev;
    qDebug()<<"Set Value";

    //проверка на ненулевые указатели
    if(calibrator && voltmeter){

    //проверка статуса подключения приборов
    if(calibrator->getStatusConnect() && voltmeter->getStatusConnect()){

        qDebug()<< "статус" << calibrator->getStatusConnect() << voltmeter->getStatusConnect();

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

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m_numberMeasurements; ++j) {
                for (int k = 0; k < 4; ++k) {
                    qDebug() << m_arrForMeasurement[i][j][k];
                }

            }
        }


        for (uint i = 0; i < m_numberMeasurements; ++i) {

            uint Count = 0;

            if(calibrator->setFreqValue(m_Voltage,1)){
                qDebug()<<"Снятие показаний F1";
                if (!receiversMeasurement(voltmeter,i,Count)){
                    break;//вызывать throw
                }

             } else {
                break;
            }
            Count++;

            if(calibrator->setValue(m_Voltage)){
                if (!receiversMeasurement(voltmeter,i,Count)){
                    break;//вызывать throw
                }

             } else {
                break;
            }
            Count++;

            if(calibrator->setValue(-m_Voltage)){
                if (!receiversMeasurement(voltmeter,i,Count)){
                    break;//вызывать throw
                }

             } else {
                break;

            }
            Count++;
            if(calibrator->setFreqValue(m_Voltage,1)){
                if (!receiversMeasurement(voltmeter,i,Count)){
                    break;//вызывать throw
                }

             } else {
                break;

            }


            this->calculation(i);


            }
        }
        // вычисление результирующей погрешности Отдельный метод

            this->calculationRezult();


    }

    qDebug()<<"End process";
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
    float averageRefDC = (m_arrForMeasurement[1][iteration][2] + m_arrForMeasurement[1][iteration][3])/2;
    float averageRefAC = (m_arrForMeasurement[1][iteration][1] + m_arrForMeasurement[1][iteration][4])/2;
    float deltaRef = (averageRefAC - averageRefDC)/ (m_TypeRefDev * averageRefDC);

    //рассчет погрешности для поверяемого прибора

    float averageDC = (m_arrForMeasurement[2][iteration][2] + m_arrForMeasurement[2][iteration][3])/2;
    float averageAC = (m_arrForMeasurement[2][iteration][1] + m_arrForMeasurement[2][iteration][4])/2;

    float deltaVer = (averageAC - averageDC)/ (m_TypeCalDev * averageDC);

    //разность погрешностей

    float RezultDelta = deltaVer - deltaRef;

    m_arrForRezultForEachIteration[iteration] = RezultDelta;
}

void Verification::calculationRezult()
{
    float Summ = 0;

    for (int i = 0; i < m_numberMeasurements; ++i) {
        Summ+=m_arrForRezultForEachIteration[i];
    }

    m_Rezult = Summ/m_numberMeasurements + m_correctRef;
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

bool Verification::receiversMeasurement(Voltmeter * volt, uint iteration,uint count )
{
    if (volt->receiveValue(1)){
        m_arrForMeasurement[1][iteration][count] = volt->receiveValue(1);
    }else {
        return false;
    }
    if(volt->receiveValue(2)){
        m_arrForMeasurement[2][iteration][count] = volt->receiveValue(2);
    } else {
        return false;
    }

    return true;
}

void Verification_U::setVoltage(float volt)
{

        m_Voltage = volt;

}

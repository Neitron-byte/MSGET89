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

    float Summ = 0;

    for (int i = 0; i < m_numberMeasurements; ++i) {

        QVector<float> arrforCH1;
        QVector<float> arrforCH2;

        if(calibrator->setFreqValue(m_Voltage,1)){
            arrforCH1.push_back(voltmeter->receiveValue(1));
            arrforCH2.push_back(voltmeter->receiveValue(2));
         } else {
            break;
        }
        if(calibrator->setValue(m_Voltage)){
            arrforCH1.push_back(voltmeter->receiveValue(1));
            arrforCH2.push_back(voltmeter->receiveValue(2));
        } else {
            break;
        }
        if(calibrator->setValue(-m_Voltage)){
            arrforCH1.push_back(voltmeter->receiveValue(1));
            arrforCH2.push_back(voltmeter->receiveValue(2));
        } else {
            break;
        }
        if(calibrator->setFreqValue(m_Voltage,1)){
            arrforCH1.push_back(voltmeter->receiveValue(1));
            arrforCH2.push_back(voltmeter->receiveValue(2));
        } else {
            break;
        }

        float Rez = calculation(arrforCH1,arrforCH2);
        m_rezultCalibration.push_back(Rez);

        m_MeasurementRef.push_back(arrforCH1);
        m_MeasurementCal.push_back(arrforCH2);

        Summ+=Rez;
    }
     m_Rezult = Summ/m_numberMeasurements + m_correctRef;
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

float Verification::calculation(const QVector<float>  CH1, const QVector<float>  CH2)
{
    //рассчет погрешности для эталона
    float averageRefDC = (CH1[2] + CH1[3])/2;
    float averageRefAC = (CH1[1] + CH1[4])/2;
    float deltaRef = (averageRefAC - averageRefDC)/ (m_TypeRefDev * averageRefDC);

    //рассчет погрешности для поверяемого прибора

    float averageDC = (CH2[2] + CH2[3])/2;
    float averageAC = (CH2[1] + CH2[4])/2;
    float deltaVer = (averageAC - averageDC)/ (m_TypeCalDev * averageDC);

    //разность погрешностей

    float RezultDelta = deltaVer - deltaRef;

    return RezultDelta;
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

void Verification_U::setVoltage(float volt)
{

        m_Voltage = volt;

}

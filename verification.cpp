#include "verification.h"


void Verification_U_DC_AC::startVerification(const Calibrator * calibrator, const Voltmeter * voltmeter)
{
    qDebug()<<"Start calibration DC_AC";
    qDebug()<<m_numberMeasurements
           <<m_Voltage
          <<m_correctRef
         <<m_TypeRefDev
        <<m_TypeCalDev;
}

void Verification_U_AC_AC::startVerification(const Calibrator *, const Voltmeter *)
{
    qDebug()<<"Start calibration AC_AC";
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

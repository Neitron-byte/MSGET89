#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QObject>
#include <controller.h>

//_____________абстрактный базовый класс процедуры поверки ТП___________________________//
class Verification : public QObject
{

    Q_OBJECT
public:
    explicit Verification(QObject *parent = nullptr);
    virtual ~Verification(){

    }
    virtual void startVerification(const Calibrator* , const Voltmeter* ) = 0;


signals:


protected:
    //поправка на эталон
    float m_correctRef = 0;
    //Количество циклов
    uint m_numberMeasurements = 0;

};

//_____________ определение основной погрешности компарирования преобразователей напряжения ___________________________//
class Verification_U : public Verification {
    Q_OBJECT

public:
    explicit Verification_U(QObject *parent = nullptr);
    virtual ~Verification_U(){

    }

public:


protected:
    //Номинальное напряжение, на которое рассчитан преобразователь
    float m_Voltage =0;

};



//_____________ определение основной погрешности компарирования при переходе DC к AC ___________________________//
class Verification_U_DC_AC : public Verification_U {
    Q_OBJECT
public:
    explicit Verification_U_DC_AC(QObject *parent = nullptr);
    virtual ~Verification_U_DC_AC(){

    }


    virtual void startVerification(const Calibrator* , const Voltmeter* ) override;

private:


};

//_____________ определение основной погрешности компарирования на частотах, отличных от 1 кГц ___________________________//

class Verification_U_AC_AC : public Verification_U {
    Q_OBJECT
public:
    explicit Verification_U_AC_AC(QObject *parent = nullptr);
    virtual ~Verification_U_AC_AC(){

    }

    virtual void startVerification(const Calibrator* , const Voltmeter* ) override;

};

#endif // VERIFICATION_H

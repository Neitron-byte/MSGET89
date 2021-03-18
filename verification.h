#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QObject>
#include <controller.h>
#include <QDebug>
#include <QList>
#include <QQueue>
#include <QVector>
#include <QProgressDialog>
#include <QProgressBar>
#include <QThread>
#include <QApplication>
#include <QMessageBox>
#include <iostream>



//_____________абстрактный базовый класс процедуры поверки ТП___________________________//
class Verification : public QObject
{

    Q_OBJECT



public:
    explicit Verification(QObject *parent = nullptr){
        qDebug()<< "Ver Bass create";

    }
    virtual ~Verification();
    virtual void startVerification(Calibrator* , Voltmeter* ) = 0;
    void setNumberMeasurement(uint);
    void setCorrect(float);
    void setTypeRef(uint);
    void setTypeCalib(uint);
    void receiversMeasurement(Voltmeter*,int,uint);
    float calculation(uint );
    void calculationRezult();
    void setIncValue();
    //счетчик для прогресс диалога
    static int Count;
    //подготовка массива
    void preparingAnArray();
    void print();

signals:


protected:
    //поправка на эталон
    float m_correctRef = 0;

    //Количество циклов
    uint m_numberMeasurements = 0;

    //тип поверяемого преобразователя
    uint m_TypeCalDev = 1; //2 - squa ; 1 - line

    //тип эталонного преобразователя
    uint m_TypeRefDev = 1;//2 - squa ; 1 - line

    //Результат поверки
    float m_Rezult = 0;

    //хранение измерений

    //трехмерный динамиеский массив данных
    float *** m_arrForMeasurement;

    //хранение промежуточных результатов для каждого цикла
    float * m_arrForRezultForEachIteration;

    //диалоговое окно прогресса
    QProgressDialog* m_pprd = nullptr;

    //timeout
    ulong m_timeOut = 3000;



};


//_____________ определение основной погрешности компарирования преобразователей напряжения ___________________________//
class Verification_U : public Verification {
    Q_OBJECT

public:
    explicit Verification_U(QObject *parent = nullptr){
        qDebug()<< "VerU Bass create";
    }
    virtual ~Verification_U(){
         qDebug()<< "VerU Bass dist";
    }

public:
    void setVoltage(float);
    void setFrequency(uint);

protected:
    //Номинальное напряжение, на которое рассчитан преобразователь
    float m_Voltage =0;
    // Частота
    uint m_Frequency = 0;
};





//_____________ определение основной погрешности компарирования при переходе DC к AC ___________________________//
class Verification_U_DC_AC : public Verification_U {
    Q_OBJECT
public:
    explicit Verification_U_DC_AC(QObject *parent = nullptr){
        qDebug()<< "VerU_DC_AC Bass create";
    }
    virtual ~Verification_U_DC_AC(){
        qDebug()<< "VerU_DC_AC Bass dist";
    }


    virtual void startVerification(Calibrator* , Voltmeter* ) override;

private:


};

//_____________ определение основной погрешности компарирования на частотах, отличных от 1 кГц ___________________________//

class Verification_U_AC_AC : public Verification_U {
    Q_OBJECT
public:
    explicit Verification_U_AC_AC(QObject *parent = nullptr){
        qDebug()<< "VerU_АC_AC Bass create";
    }
    virtual ~Verification_U_AC_AC(){
        qDebug()<< "VerU_AC_AC Bass dist";
    }

    virtual void startVerification(Calibrator* , Voltmeter* ) override;

};

#endif // VERIFICATION_H

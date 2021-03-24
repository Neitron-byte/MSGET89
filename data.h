#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDebug>
#include <QAxObject>
#include <QDate>
#include <QTime>
#include "console.h"



class Data : public QObject
{
    Q_OBJECT
public:
    //explicit Data(QObject *parent = nullptr);
    static Data * getData() {
            if(!pData)
                pData = new Data();
            return pData;
        }

    void setTemp(float temp){

        m_temp = temp;
        qDebug()<<"Temp"<<m_temp;
        m_console->putData(tr("Temperature: %1").arg(m_temp).toLocal8Bit());
     }
    void setFullName(const QString& name){
        m_fullName = name;
        m_console->putData(tr("Full name: %1").arg(m_fullName).toLocal8Bit());
    }
    void setModel(const QString& model){
        m_model = model;
        m_console->putData(tr("Model: %1").arg(m_model).toLocal8Bit());
    }
    void setSerial(const QString& serial){
        m_serialNum = serial;
        m_console->putData(tr("Serial Number: %1").arg(m_serialNum).toLocal8Bit());
    }
    void setCompany(const QString& company){
        m_company = company;
        m_console->putData(tr("Company: %1").arg(m_company).toLocal8Bit());
    }
    void setVoltage(float vol){
        m_voltage = vol;
        m_console->putData(tr("Voltage: %1").arg(m_voltage).toLocal8Bit());
    }

    void setFrequency(int freq){
        m_vectorTypeVer.push_back(freq);
        if (freq) {
        m_console->putData(tr("Frequency: %1").arg(freq).toLocal8Bit());
       }
        Count++;
    }
    void addRezult(float Rezult){
        m_vectorRezultVal.push_back(Rezult);
        if (m_vectorTypeVer[Count-1] == 0 ){
            m_console->putData((tr("DC-AC: ")+ QString::number(Rezult)).toLocal8Bit());
        } else {
            m_console->putData((tr("AC-AC: %1 kHz").arg(Rezult)).toLocal8Bit());
        }

    }
    void setConsole(Console* cons){
        m_console = cons;
    }

    void print();

signals:

private:
    //общие данные
    float m_temp = 0;
    QString m_fullName = 0;
    QString m_model = 0;
    QString m_serialNum = 0;
    QString m_company =0;
    float m_voltage = 0;
    static int Count;
    Console* m_console;
    //результаты поверки
    QVector<float> m_vectorRezultVal;
    //тип поверки
    QVector<int> m_vectorTypeVer;
    //

    static Data* pData;
protected:
    explicit Data(QObject *parent = nullptr);
    Data( const Data& ) = delete;
    Data& operator=( Data& ) = delete;
 public:
    ~Data(){
      delete pData;
    }
};

#endif // DATA_H

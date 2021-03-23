#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDebug>
#include <QAxObject>
#include <QDate>
#include <QTime>

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
    }
    void setFullName(const QString& name){
        m_fullName = name;
    }
    void setModel(const QString& model){
        m_model = model;
    }
    void setSerial(const QString& serial){
        m_serialNum = serial;
    }
    void setCompany(const QString& company){
        m_company = company;
    }
    void setVoltage(float vol){
        m_voltage = vol;
    }

    void setFrequency(int freq){
        m_vectorTypeVer.push_back(freq);
    }
    void addRezult(float Rezult){
        m_vectorRezultVal.push_back(Rezult);
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
    int m_frequency = 0;

    //результаты поверки
    QVector<float> m_vectorRezultVal;
    //тип поверки
    QVector<int> m_vectorTypeVer;

    static Data* pData;
    explicit Data(QObject *parent = nullptr);
    Data( const Data& ) = delete;
    Data& operator=( Data& ) = delete;
};

#endif // DATA_H

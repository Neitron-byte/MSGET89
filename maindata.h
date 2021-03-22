#ifndef MAINDATA_H
#define MAINDATA_H

#include <QWidget>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QAxObject>





namespace Ui {
class mainData;
}

class mainData : public QWidget
{
    Q_OBJECT
    void SetLenght();


public:
    explicit mainData(QWidget *parent = nullptr);
    ~mainData();


public slots:
    void slot_set_Time(const QString);
    void slot_set_Date(const QString);
    void addRezulttoVector(float);
    void addTypetoVector(int);
    void setVoltage(float);
    void print();


private:
    Ui::mainData *ui;

    //Дата и время
    int m_timerinterval = 0;
    int m_idTimer = 0;
    QTime time;
    QDate date;

    //общие данные
    float m_temp = 0;
    QString m_fullName = 0;
    QString m_model = 0;
    QString m_serialNum = 0;
    QString m_company =0;
    //Напряжение на которое рассчитан преобразователь
    float m_voltage = 0;

    //результаты поверки
    QVector<float> m_vectorRezultVal;
    //тип поверки
    QVector<int> m_vectorTypeVer;

    static uint m_counterNumVerification;

signals:
    void signalFromMainToConsole(const QByteArray&);



    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_start_calibration_clicked();
};

#endif // MAINDATA_H

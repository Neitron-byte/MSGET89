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


private:
    Ui::mainData *ui;

    //Дата и время
    int m_timerinterval = 0;
    int m_idTimer = 0;
    QTime time;
    QDate date;

    //


    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_start_calibration_clicked();
};

#endif // MAINDATA_H

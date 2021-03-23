#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QWidget>
#include "verification.h"
#include "data.h"


namespace Ui {
class Calibration;
}

class Calibration : public QWidget
{
    Q_OBJECT
    void addItem();
    void setLenght();
    void setParametersCalibration();

signals:
    void setCalibration(const Verification* m_calibration);
    void signalStartCalibration();
    void signalForConsole(const QByteArray&);


public:
    explicit Calibration(QWidget *parent = nullptr);
    ~Calibration();
    //const Verification* getCalibration();

private slots:


    void on_comboBox_calibration_Dev_2_currentIndexChanged(int index);

    void on_pushButton_start_calibration_2_clicked();

    void on_pushButton_print_clicked();

private:
    Ui::Calibration *ui;

    // алгоритм поверки
    Verification* m_calibration = nullptr;
};

#endif // CALIBRATION_H

#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QObject>
#include <controller.h>

class Verification : public QObject
{
    Q_OBJECT
public:
    explicit Verification(QObject *parent = nullptr);
    virtual ~Verification(){

    }
    virtual void startVerification(const Calibrator* , const Voltmeter* ) = 0;

signals:

};

class Verification_AC_DC : public Verification {
    Q_OBJECT

public:
    virtual void startVerification(const Calibrator* , const Voltmeter* ) override;


};


class Verification_AC_AC : public Verification {
    Q_OBJECT

public:
    virtual void startVerification(const Calibrator* , const Voltmeter* ) override;

};

#endif // VERIFICATION_H

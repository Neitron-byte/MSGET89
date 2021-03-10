#ifndef ENUMMODELSDEVICE_H
#define ENUMMODELSDEVICE_H

#include <QObject>

//______________Модели калибратора__________________//

class enumModelCalibrator : public QObject

{
    Q_OBJECT

public:

    enum models
    {
        H4_7

    };


    Q_ENUM(models)


    enumModelCalibrator (QObject *parent = nullptr);
};

//______________Модели вольтметра__________________//

class enumModelVoltmeter: public QObject

{
    Q_OBJECT

public:
    //__________Модели калибраторов__________//
    enum models
    {
        HP34420
    };


    Q_ENUM(models)


    enumModelVoltmeter (QObject *parent = nullptr);
};

//_____________Тип подключения__________________//


class enumTypeConnection : public QObject

{
    Q_OBJECT
public:
    //__________Тип подключения__________//
    enum type
    {
        COM,
        TCP
    };

    Q_ENUM(type)
    //TypeConnection () = delete;
    enumTypeConnection (QObject *parent = nullptr);

};


#endif // ENUMMODELSDEVICE_H



#ifndef ENUMMODELSDEVICE_H
#define ENUMMODELSDEVICE_H

#include <QObject>

class enumsdevice

{


public:
    //__________Модели калибраторов__________//
    enum class models
    {
        H4_7,
        HP34420

    };
    Q_ENUM(models)

    //__________Тип подключения__________//
    enum class typeConnection
    {
        COM,
        TCP
    };

    Q_ENUM(typeConnection)
    Q_GADGET
    //Q_OBJECT
    enumsdevice() = delete;

};

#endif // ENUMMODELSDEVICE_H

#ifndef ENUMMODELSDEVICE_H
#define ENUMMODELSDEVICE_H

#include <QObject>

class enumModelDevice : public QObject

{
    Q_OBJECT

public:
    //__________Модели калибраторов__________//
    enum models
    {
        H4_7,
        HP34420

    };
    Q_ENUM(models)



    //enumsdevice() = delete;
    enumVodelDevice (QObject *parent = nullptr);
};

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



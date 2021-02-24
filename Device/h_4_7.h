#ifndef H_4_7_H
#define H_4_7_H

#include "Device/calibrator.h"
#include <QString>


//_____________Калибратор H4-7_______________//

class H_4_7: public Calibrator
{
    //Команды калибратора H4-7

    enum class Commands
    {
        UD, //постоянное напряжение
        UA, //переменное напряжение
        F  //частота
     };
    


public:
    H_4_7();
    ~H_4_7();

    virtual void connect() override;
    virtual void disconnect() override;


    virtual void setValue() override ; //интерфейс, который должен переопределить каждый наследник
};

#endif // H_4_7_H

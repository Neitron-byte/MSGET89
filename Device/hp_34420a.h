#ifndef HP_34420A_H
#define HP_34420A_H

#include "Device/voltmeter.h"

//___________Вольтметр HP34420A_______________//

class HP_34420A: public Voltmeter
{
    enum class Commands {
        
    }; 
            
public:
    HP_34420A();
    
    virtual void connect() override;
    virtual void disconnect() override;


    virtual void receiveValue() override; //интерфейс, который должен переопределить каждый наследник
};

#endif // HP_34420A_H

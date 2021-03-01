#ifndef DIALOGSETTINGSCOM_H
#define DIALOGSETTINGSCOM_H

#include <QDialog>
#include <QDebug>
#include <QSerialPort>

namespace Ui {
class DialogSettingsCom;
}

//_____________Диалоговое окно настроек COM ______________//

class DialogSettingsCom : public QDialog
{
    Q_OBJECT

    void fillPortsParameters();

public:
    explicit DialogSettingsCom(QWidget *parent = nullptr);
    ~DialogSettingsCom();

private:
    Ui::DialogSettingsCom *ui;

};

#endif // DIALOGSETTINGSCOM_H

#ifndef MAINDATA_H
#define MAINDATA_H

#include <QWidget>

namespace Ui {
class mainData;
}

class mainData : public QWidget
{
    Q_OBJECT

public:
    explicit mainData(QWidget *parent = nullptr);
    ~mainData();

private:
    Ui::mainData *ui;
};

#endif // MAINDATA_H

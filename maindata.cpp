#include "maindata.h"
#include "ui_maindata.h"

mainData::mainData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainData)
{
    ui->setupUi(this);
}

mainData::~mainData()
{
    delete ui;
}

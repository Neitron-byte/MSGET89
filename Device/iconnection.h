#ifndef ICONNECTION_H
#define ICONNECTION_H

#include <QObject>

class IConnection : public QObject
{
    Q_OBJECT
public:
    explicit IConnection(QObject *parent = nullptr);

    virtual void write() =0;



signals:

};

#endif // ICONNECTION_H

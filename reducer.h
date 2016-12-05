#ifndef REDUCER_H
#define REDUCER_H

#include <QMap>
#include <QVariant>
#include <QString>

#include "action.h"

class Reducer
{
protected:
    QMap<QString, QVariant> data;
public:
    Reducer();
    void addProp(const QString& name, QVariant _data);
    virtual void handleAction(Action action) = 0;
    QVariant getProp(const QString& name);
};

#endif // REDUCER_H

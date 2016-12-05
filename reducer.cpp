#include "reducer.h"

Reducer::Reducer()
{

}

void Reducer::addProp(const QString &name, QVariant _data)
{
   data.insert(name, _data);
}

QVariant Reducer::getProp(const QString &name)
{
    QMap<QString, QVariant>::iterator it = data.find(name);
    if(it == data.end())
        throw "Prop not found";

    return (*it);
}


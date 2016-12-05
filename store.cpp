#include "store.h"

QMap<QString,Reducer*> Store::reducers;
QList<StoreSuscriber*> Store::suscribers;

Store::Store()
{

}

void Store::addSuscriber(StoreSuscriber *s)
{
    suscribers.append(s);
}

void Store::removeSuscriber(StoreSuscriber *s)
{
    suscribers.removeOne(s);
}

void Store::dispatch(Action action)
{
    QMap<QString, Reducer*>::iterator it;
    for(it = reducers.begin(); it != reducers.end(); it++) {
        (*it)->handleAction(action);
    }

    for(unsigned i = 0; i < suscribers.count(); i++) {
        suscribers[i]->stateChanged();
    }
}

QVariant Store::getState(const QString &reducer, const QString &prop)
{
    QMap<QString, Reducer*>::iterator it = reducers.find(reducer);
    if(it == reducers.end()) {
        throw "Reducer not found";
    }

    return (*it)->getProp(prop);
}

void Store::addReducer(const QString name, Reducer* reducer)
{
    reducers.insert(name, reducer);
}


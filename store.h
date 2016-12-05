#ifndef STORE_H
#define STORE_H

#include "action.h"
#include "reducer.h"
#include "storesuscriber.h"

class Store
{
    protected:
        static QMap<QString, Reducer*> reducers;
        static QList<StoreSuscriber*> suscribers;
    public:
        Store();
        static void addSuscriber(StoreSuscriber* s);
        static void removeSuscriber(StoreSuscriber* s);
        static void addReducer(const QString name, Reducer* reducer);
        static void dispatch(Action action);
        static QVariant getState(const QString& reducer, const QString& prop);

};

#endif // STORE_H

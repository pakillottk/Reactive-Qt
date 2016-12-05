#include "todosreducer.h"

#include <QDebug>


TodosReducer::TodosReducer()
{
    this->addProp("todos", QList<QVariant>());
}

void TodosReducer::handleAction(Action action)
{
    qDebug() << "TODOS action received: " << action.type;

    if(action.type == "ADD_TODO") {
        qDebug() << "Adding todo";

        QList<QVariant> list = this->getProp("todos").toList();
        list.append(action.payload);
        data["todos"] = list;
    } else if(action.type == "UPDATE_TODO") {
        qDebug() << "Updating todo";

        QList<QVariant> list = this->getProp("todos").toList();
        QMap<QString, QVariant> params = action.payload.toMap();

        if(params["index"].toInt() >= 0 && params["index"].toInt() < list.count())
            list[params["index"].toInt()] = params["todo"].toString();

        data["todos"] = list;
    }
}


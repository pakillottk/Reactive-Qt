#include "todosactions.h"

#include <QMap>

Action TodosActions::AddTodo(QString todo)
{
    return Action("ADD_TODO", todo);
}

Action TodosActions::UpdateTodo(int index, QString todo)
{
    QMap<QString, QVariant> params;
    params.insert("index", index);
    params.insert("todo", todo);

    return Action("UPDATE_TODO", params);
}

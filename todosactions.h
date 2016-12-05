#ifndef TODOSACTIONS_H
#define TODOSACTIONS_H

#include "action.h"

class TodosActions
{
public:
    static Action AddTodo(QString todo);
    static Action UpdateTodo(int index, QString todo);
};

#endif // TODOSACTIONS_H

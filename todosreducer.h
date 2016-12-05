#ifndef TODOSREDUCER_H
#define TODOSREDUCER_H

#include "reducer.h"

#include <QList>

class TodosReducer : public Reducer
{
public:
    TodosReducer();
    void handleAction(Action action);
};

#endif // TODOSREDUCER_H

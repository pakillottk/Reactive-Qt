#include "mainwindow.h"
#include <QApplication>

#include "store.h"
#include "todosreducer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TodosReducer todos;
    Store::addReducer("todos", &todos);

    MainWindow w;
    w.show();

    return a.exec();
}

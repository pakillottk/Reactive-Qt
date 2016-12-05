#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "store.h"
#include "todosactions.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Store::addSuscriber(this);

    QList<QVariant> todos = Store::getState("todos", "todos").toList();
    for(unsigned i = 0; i < todos.count(); i++) {
        ui->listWidget->addItem(todos[i].toString());
    }
}

void MainWindow::stateChanged()
{
    qDebug() << "The store changed";

    QList<QVariant> todos = Store::getState("todos", "todos").toList();
    for(unsigned i = 0; i < todos.count(); i++) {
        if(i >= ui->listWidget->count()) {
            ui->listWidget->addItem(todos[i].toString());
        } else {
           ui->listWidget->item(i)->setText(todos[i].toString());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    Store::removeSuscriber(this);
}

void MainWindow::on_pushButton_clicked()
{
    QString todo = ui->lineEdit->text();
    Store::dispatch(TodosActions::AddTodo(todo));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString todo = ui->lineEdit->text();
    QModelIndex index = ui->listWidget->currentIndex();
    if(index.isValid()) {
        Store::dispatch(TodosActions::UpdateTodo(index.row(), todo));
    }
}

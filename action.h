#ifndef ACTION_H
#define ACTION_H

#include <QString>
#include <QVariant>

class Action
{
    public:
        QString type;
        QVariant payload;
        Action(const QString& type, QVariant _payload);
};

#endif // ACTION_H

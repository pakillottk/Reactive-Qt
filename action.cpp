#include "action.h"

Action::Action(const QString &_type, QVariant _payload)
{
    type = _type;
    payload = _payload;
}


#include "celebrity.h"

Celebrity::Celebrity(QObject *parent)
    : QObject{parent}
{

}

void Celebrity::broadcast_ready()
{
    emit ready_for_signing();
}

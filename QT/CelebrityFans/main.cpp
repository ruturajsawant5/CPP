#include <QCoreApplication>
#include "celebrity.h"
#include "fan.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    Celebrity rdj;
    Fan f1("Ruturaj", "RDJ");
    Fan f2("Ekta", "RDJ");
    Fan f3("Dinesh", "RDJ");

    QObject::connect(&rdj, SIGNAL(ready_for_signing()), &f1, SLOT(get_sign()));
    QObject::connect(&rdj, SIGNAL(ready_for_signing()), &f2, SLOT(get_sign()));
    QObject::connect(&rdj, SIGNAL(ready_for_signing()), &f3, SLOT(get_sign()));

    rdj.broadcast_ready();
}

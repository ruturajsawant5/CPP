#include <QCoreApplication>
#include "swimmer.h"
#include "lifeguard.h"
#include <iostream>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    Lifeguard L1;
    Swimmer sw1("RUturaj",1);
    Swimmer sw2("Sid",2);

    QObject::connect(&sw1, SIGNAL(threat(std::string, int)), &L1, SLOT(save_life(std::string, int)));
    QObject::connect(&sw2, SIGNAL(threat(std::string, int)), &L1, SLOT(save_life(std::string, int)));

    sw1.raise_threat();
    sw2.raise_threat();

    return app.exec();
}



#include "swimmer.h"
#include <string>

Swimmer::Swimmer(std::string name, int id, QObject *parent)
    : QObject{parent}, sw_name(name), sw_id(id)
{

}

void Swimmer::raise_threat()
{
    emit threat(sw_name, sw_id);
}

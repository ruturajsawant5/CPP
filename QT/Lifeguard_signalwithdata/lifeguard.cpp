
#include "lifeguard.h"
#include <iostream>

Lifeguard::Lifeguard(QObject *parent)
    : QObject{parent}
{

}

void Lifeguard::save_life(std::string name, int id)
{
    std::cout<<name<<" "<<id<<std::endl;
}

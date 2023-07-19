
#include "fan.h"

Fan::Fan(std::string _celeb_name, std::string _fan_name, QObject *parent)
    : QObject{parent}, celeb_name(_celeb_name), fan_name(_fan_name)
{

}

void Fan::get_sign()
{
    std::cout<<celeb_name<<" "<<fan_name<<std::endl;
}

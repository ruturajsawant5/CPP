#include <iostream>
#include "Date.h"
#include "IDate.h"

Date::Date(int dd, int mm, int yy)  : day(dd), month(mm), year(yy)
{

}

int Date::get_day() const
{
    return (day); 
}

int Date::get_month() const
{
    return month; 
}

int Date::get_year() const
{
    return year; 
}

void Date::set_day(int n)
{
    day = n; 
} 

void Date::set_month(int n)
{
    month = n; 
}

void Date::set_year(int n)
{
    year = n;
}

void Date::show() const
{
    std::cout << day << "-" << month << "-" << year << std::endl; 
}

IDate* get_date_instance(int dd, int mm, int yy)
{
    return new Date(dd, mm, yy); 
}
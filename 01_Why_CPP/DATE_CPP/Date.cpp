#include <iostream>
#include <stdexcept> 
#include "Date.hpp"

Date::Date(int init_day, int init_month, int init_year)
{
    if(!this->is_date_valid(init_day, init_month, init_year))
        throw std::domain_error("Date value/(s) out of range"); 

    this->day = init_day; 
    this->month = init_month; 
    this->year = init_year;
}

int Date::get_day() const 
{
    return this->day; 
}

int Date::get_month() const 
{
    return this->month; 
}

int Date::get_year() const 
{
    return this->year; 
}

int Date::set_day(int new_day)
{
    if(!is_date_valid(new_day, this->month, this->year))
        throw std::domain_error("day value out of range"); 
    this->day = new_day; 
    return (SUCCESS); 
}

int Date::set_month(int new_month)
{
    if(!is_date_valid(this->day, new_month, this->year))
        throw std::range_error("month value out of range"); 
    this->month = new_month; 
    return (SUCCESS); 
}

int Date::set_year(int new_year)
{
    if(!is_date_valid(this->day, this->month, new_year))
        throw std::range_error("year value out of range"); 
    this->year = new_year; 
    return (SUCCESS); 
}

void Date::show() const 
{
    std::cout << day << "-" << month << "-" << year << std::endl; 
}
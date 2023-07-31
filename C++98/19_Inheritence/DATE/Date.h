#pragma once 

#include "IDate.h"

class Date : public IDate
{
    private: 
        int day, month, year; 

    public: 
        Date(int, int, int); 
        
        int get_day() const; 
        int get_month() const; 
        int get_year() const; 

        void set_day(int); 
        void set_month(int); 
        void set_year(int); 

        void show() const; 
}; 
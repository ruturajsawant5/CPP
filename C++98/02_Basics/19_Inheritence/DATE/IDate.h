#pragma once 

class IDate
{
    public: 
        virtual int get_day() const; 
        virtual int get_month() const; 
        virtual int get_year() const; 
        virtual void show() const; 
        virtual void set_day(int); 
        virtual void set_month(int); 
        virtual void set_year(int); 
}; 

IDate* get_date_instance(int, int, int); 

/* 
    class Shape
    {
        public: 
            virtual void draw() = 0; 
    }; 

    class Triangle : public Shape
    {
        public: 
            void draw()
            {

            }
    }; 
*/
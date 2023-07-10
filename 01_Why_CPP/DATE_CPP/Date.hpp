#ifndef _DATE_H 
#define _DATE_H 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 
    
        static bool is_date_valid(int day, int month, int year);

    public: 
        Date(int init_day, int init_month, int init_year); 

        int get_day() const; 
        int get_month() const; 
        int get_year() const;

        int set_day(int new_day); 
        int set_month(int new_month); 
        int set_year(int new_year); 
        
        void show() const; 

        int get_day() const; 
}; 

#endif /* _DATE_H */



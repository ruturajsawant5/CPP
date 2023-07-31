#ifndef _DATE_H 
#define _DATE_H 

typedef struct Date DATE; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

DATE* get_date_instance(int init_day, int init_month, int init_year); 
int get_day(DATE* p_date); 
void set_day(DATE* p_date, int new_day); 
int get_month(DATE* p_date); 
void set_month(DATE* p_date, int new_month); 
int get_year(DATE* p_date); 
void set_year(DATE* p_date, int new_year);
void show(DATE* p_date);  
void release_date(DATE* p_date); 

#endif /* _DATE_H */
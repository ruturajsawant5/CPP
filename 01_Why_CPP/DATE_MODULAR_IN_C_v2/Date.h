#ifndef _DATE_H 
#define _DATE_H 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

#define E_INV_DAY   2 
#define E_INV_MONTH 3 
#define E_INV_YEAR  4 

typedef struct Date DATE; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

DATE* get_date_instance(int init_day, int init_month, int init_year); 
int get_day(DATE* p_date); 
int set_day(DATE* p_date, int new_day); 
int get_month(DATE* p_date); 
int set_month(DATE* p_date, int new_month); 
int get_year(DATE* p_date); 
int set_year(DATE* p_date, int new_year);
void show(DATE* p_date);  
void release_date(DATE* p_date); 

static int is_date_valid(int day, int month, int year); 

#endif /* _DATE_H */
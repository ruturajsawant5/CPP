#include "Date.h" 

int main(void)
{
    DATE* p_date = 0; 

    p_date = get_date_instance(10, 1, 1999); 
    show(p_date); 
    set_day(p_date, 24); 
    set_month(p_date, 3); 
    set_year(p_date, 2022);
    show(p_date); 
    release_date(p_date); 
    p_date = 0; 

    return (0);  
}
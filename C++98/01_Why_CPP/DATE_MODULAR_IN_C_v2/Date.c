#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#include "Date.h"

DATE* get_date_instance(int init_day, int init_month, int init_year)
{
    DATE* p_date = NULL; 

    if(!is_date_valid(init_day, init_month, init_year))
        return (NULL); 

    p_date = (DATE*)malloc(sizeof(DATE)); 
    if(p_date == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        return (NULL); 
    }

    p_date->day = init_day; 
    p_date->month = init_month; 
    p_date->year = init_year; 

    return (p_date); 
}

int get_day(DATE* p_date)
{
    return (p_date->day); 
}

int set_day(DATE* p_date, int new_day)
{
    if(!is_date_valid(new_day, p_date->month, p_date->year))
        return (E_INV_DAY); 
    p_date->day = new_day; 
    return (SUCCESS); 
}

int get_month(DATE* p_date)
{
    return (p_date->month); 
}

int set_month(DATE* p_date, int new_month)
{
    if(!is_date_valid(p_date->day, new_month, p_date->year))
        return (E_INV_MONTH); 
    p_date->month = new_month; 
    return (SUCCESS); 
}

int get_year(DATE* p_date)
{
    return (p_date->year); 
}

int set_year(DATE* p_date, int new_year)
{
    if(!is_date_valid(p_date->day, p_date->month, new_year))
        return (E_INV_YEAR); 
    p_date->year = new_year; 
    return (SUCCESS); 
}

void show(DATE* p_date)
{
    printf("%d-%d-%d\n", p_date->day, p_date->month, p_date->year); 
}

void release_date(DATE* p_date)
{
    free(p_date); 
}

static int is_date_valid(int day, int month, int year)
{
    // WRITE LOGIC OF DATE VALIDATION 
    
    return (TRUE); 
}
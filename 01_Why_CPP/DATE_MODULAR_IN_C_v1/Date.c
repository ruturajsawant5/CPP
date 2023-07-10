#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#include "Date.h"

DATE* get_date_instance(int init_day, int init_month, int init_year)
{
    DATE* p_date = NULL; 

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

void set_day(DATE* p_date, int new_day)
{
    p_date->day = new_day; 
}

int get_month(DATE* p_date)
{
    return (p_date->month); 
}

void set_month(DATE* p_date, int new_month)
{
    p_date->month = new_month; 
}

int get_year(DATE* p_date)
{
    return (p_date->year); 
}

void set_year(DATE* p_date, int new_year)
{
    p_date->year = new_year; 
}

void show(DATE* p_date)
{
    printf("%d-%d-%d\n", p_date->day, p_date->month, p_date->year); 
}

void release_date(DATE* p_date)
{
    free(p_date); 
}
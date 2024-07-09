#include <stdio.h> 
#include <stdlib.h> 

#include "wrapper.h"

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date* my_function(char* date_str); 

int main(void)
{
    char* date_str = "1/2/1970"; 
    struct Date* p_date = NULL; 

    register_function(my_function); 
    call_function(date_str); 
    get_return_value(&p_date); 

    return (0); 
}

struct Date* my_function(char* date_str)
{
    struct Date* p_date = (struct Date*)malloc(sizeof(struct Date)); 

    /* use strtok() to parse date_str */
    p_date->day = 1; 
    p_date->month = 2; 
    p_date->year = 1970; 
    /* these values ideally come from date_str */

    return p_date; 
}

/* 
    
    register_function(my_function); 
    call_function(date_str); 
    get_return_value(&p_date); 

    void register_function(struct Date*(*pfn)(char*)); 
    void call_function(char*); 
    void get_return_value(struct Date** pp_date); 

*/
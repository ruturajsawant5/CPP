#include <iostream> 
#include <cstdlib> 

struct Date
{
    int day; 
    int month; 
    int year;
}; 

int main(void)
{
    struct Date* pDate = static_cast<struct Date*>(malloc(sizeof(struct Date))); 
    pDate->day = 1; 
    pDate->month = 10; 
    pDate->year = 1970; 
    std::cout << pDate->day << "-" << pDate->month << "-" << pDate->year << std::endl; 
    delete pDate; 
    pDate = 0; 
    return 0; 
}
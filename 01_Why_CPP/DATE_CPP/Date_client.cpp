#include "Date.hpp"

int main(void)
{
    Date* pDate = new Date(10, 1, 1999); 
    
    pDate->show(); 
    
    pDate->set_day(24); 
    pDate->set_month(2); 
    pDate->set_year(2022); 

    pDate->show();

    delete pDate; 
    pDate = 0; 

    return 0; 
}
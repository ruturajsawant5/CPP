#include <iostream> 
#include "IDate.h"

int main(void)
{
    IDate* p = get_date_instance(1, 1, 1970); 

    p->show(); 

    delete p; 
    return 0; 
}
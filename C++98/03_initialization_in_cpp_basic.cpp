#include <stdio.h> 

class Date
{
    private: 
        int day, month, year; 

    public: 
        void show()
        {
            printf("%d-%d-%d\n", day, month, year); 
        }
}; 

/* 
    struct Date { int day, month, year; }; 

    struct Date* get_date_instance(int dd, int mm, int yy)
    {
        // Dynamic memory allocation + initliazation of members 
        // of structure 
        
    }

*/

int main(void)
{ 
    Date d; 
    d.show(); 
    
    Date* pDate = new Date; 
    pDate->show(); 
    delete pDate; 
    pDate = NULL; 

    return 0; 
}
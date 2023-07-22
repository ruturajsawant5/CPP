#include <stdio.h> 

class Date
{
    private: 
        int day, month, year; 
}; 

class Test
{
    private: 
        int a; 
        char b; 
        double c; 
}; 

int main(void)
{
    printf("sizeof(Date):%llu, sizeof(Test):%llu\n", 
            sizeof(Date), sizeof(Test)); 
    /* How to allocate object? */
    
    /* Method 1: Data definition statement */
    Date d; 
    Test t; 
    printf("sizeof(d):%llu, sizeof(t):%llu\n", 
            sizeof(d), sizeof(t)); 

    /* Method 2: using new operator */
    Date* pDate = new Date;  
    Test* pTest = new Test; 

    delete pDate; 
    pDate = 0; 

    delete pTest; 
    pTest = 0; 

    return 0; 
}

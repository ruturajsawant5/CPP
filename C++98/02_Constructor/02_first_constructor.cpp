#include <stdio.h> 

class Date_1
{
    private: 
        int day, month, year; 

    public: 
        // Callback function
        // Called by: compiler
        // Data sent : new object allocated by compiler and client initialization params 
        // Event of call: Creation of new object either by data definition statement 
        // or by the new operator 
        Date_1()
        {
            printf("I am here\n"); 
            printf("CONSTRUCTOR:this=%p\n", this); 
        }
}; 

class Date_2
{
    private: 
        int day, month, year; 

    public: 
        Date_2(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        }

        void show() 
        {
            printf("%d-%d-%d\n", this->day, this->month, this->year); 
        }
};

int main(void)
{
    Date_1 d1; 
    printf("main:&d1:%p\n", &d1); 

    Date_1* p_date = new Date_1; 
    printf("main:p_date:%p\n", p_date); 
    
    delete p_date; 
    p_date = NULL; 

    Date_2 d2(4, 12, 2022); 
    d2.show(); 
    Date_2* p2 = new Date_2(1, 1, 1970); 
    p2->show(); 

    delete p2; 
    p2 = NULL; 

    return 0; 
}


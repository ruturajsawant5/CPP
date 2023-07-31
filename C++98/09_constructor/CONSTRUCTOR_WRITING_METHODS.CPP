#include <iostream> 
#include <cstring> 

class Date 
{
    private: 
        int day, month, year; 
    public: 
        // CONSTRUCTOR INITIALIZER LIST 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }

        // ASSIGNMENT 
        Date(char* date_str) 
        {
            int dd, mm, yy; 
            dd = atoi(strtok(date_str, "/")); 
            mm = atoi(strtok(NULL, "/")); 
            yy = atoi(strtok(NULL, "/")); 
        }
}; 

//  INITIALIZATION SEMANTICS 
//  ASSIGNMENT SEMANTICS 

int main(void)
{
    // assignment semantics 
    int m; 
    m = 10; 

    // initialization semantics 
    int n = 10; 

    const int k = 100; 
}

class T 
{
    private: 
        const int k;    
        int m; 
        int n; 

    public: 
        T() : k(10), m(20)
        {
            n = 30; 
        } 
}; 

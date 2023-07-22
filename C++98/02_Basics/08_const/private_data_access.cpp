#include <cstdio>

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        Date(int _dd, int _mm, int _yy)
        {
            day = _dd; 
            month = _mm; 
            year = _yy; 
        }
}; 

Date d(10, 8, 1970); 

int main(void)
{
    unsigned long long int i; 
    unsigned char* p; 
    unsigned char n; 

    for(i=0; i<sizeof(d); ++i)
    {
        n = *((char*)&d + i); 
        printf("d[%llu]:%hhu\n", i, n); 
    }

    return (0); 
}

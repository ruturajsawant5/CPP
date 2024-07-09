class Date 
{
    private: 
        int day, month, year;
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {}
}; 

int main(void)
{
    Date d(1, 2, 1970); 

    // private barrier proof: 
    // 3 statements below will generate CTE 
    d.day; 
    d.month; 
    d.year; 

    // private barrier breach using C - style casting 

    *(int*)(((char*)&d) + 0); // d.day 
    *(int*)(((char*)&d) + 4); // d.month 
    *(int*)(((char*)&d) + 8); // d.year 

    // private barrier breach using C++ style casting 

    *reinterpret_cast<int*>(reinterpret_cast<char*>(&d) + 0); // d.day 
    *reinterpret_cast<int*>(reinterpret_cast<char*>(&d) + 4); // d.month 
    *reinterpret_cast<int*>(reinterpret_cast<char*>(&d) + 8); // d.year 

    return 0; 
}

// struct A {}; // ABI 

struct A* pa = NULL; 

(unsigned long long)&(pa->mem); 
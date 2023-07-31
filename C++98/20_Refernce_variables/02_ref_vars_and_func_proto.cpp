class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {} 
}; 

Date getDateInstance_1(); 
Date& getDateInstance_2(); 
Date& getDateInstance_3(); 
Date* getDateInstance_4(); 

int main(void)
{
    Date d1 = getDateInstance_1(); 
    Date& d2 = getDateInstance_2(); 
    Date& d3 = getDateInstance_3(); 
    Date* pDate = getDateInstance_4(); 

    delete &d3; 
    delete pDate; 

    return (0); 
}

Date getDateInstance_1()
{
    Date d(10, 1, 2023); 

    return (d); 
}

Date& getDateInstance_2() 
{
    Date d(2, 3, 2021); 

    return d; 
}

Date& getDateInstance_3()
{
    Date* pDate = new Date(1, 1, 1970);
    return *pDate; 
}

Date* getDateInstance_4()
{
    return new Date(1, 1, 1970); 
}
#include <iostream> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {} 

        friend std::ostream& operator<<(std::ostream&, const Date&); 
}; 

std::ostream& operator<<(std::ostream& os, const Date& D)
{
    os << D.day << "-" << D.month << "-" << D.year << std::endl; 
    return os; 
}

int main(void)
{
    Date exam_date(23, 3, 2023); 
    Date result_date(1, 6, 2023); 

    std::cout << exam_date << result_date;

    return 0; 
}
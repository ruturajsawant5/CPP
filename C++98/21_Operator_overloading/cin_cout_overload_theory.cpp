/* 
// 
// std::cout << X; 
// if X is built in data type object 

// What if X is a user defined data type object?? 

std::cout << objT; 

m1 + m2; 

m1.operator+(m2); 

matrix::operator+(&m1, m2); 

s * 5

str::operator*(&s, 5); 


std::cout << exam_date; 

std::ostream  <<    Date 

std::ostream::operator<<(&std::cout, exam_date); 


namespace std 
{
    class ostream
    {
        ostream& operator<<(const Date&); 
    }; 
}

class Date 
{
    // a function printing all 
    // members of Date object on stdout 
    // must be implemented by programmer 
    // of Date

    // but that function cannot be a 
    // member function of date 

    friend void operator<<(std::ostream& os, const Date& date_object);
}; 

void operator<<(std::ostream& os, const Date& date_object)
{
    os << date_object.day << "-" << date_object.month << "-" << date_object.year 
        << std::endl; 
}

main() 
{
    Date exam_date; 

    std::cout << exam_date; 

    std::cout << exam_date; 
}

*/
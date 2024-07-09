#include <iostream>
#include "list.hpp"

int main(void)
{
    list<char> cList; 
    list<int> iList; 
    list<double> dList; 

    for(int data = 0; data <= 100; data += 10)
        iList.insert_end(data); 

    for(list<int>::iterator iter = iList.begin(); iter != iList.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl; 

    return 0; 
}
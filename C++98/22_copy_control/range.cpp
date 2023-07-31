#include <iostream> 

class range
{
    public: 
        range(int m, int n);

        class iterator 
        {
            public: 
                iterator(); 
                bool operator!=(const iterator& other); 
                iterator operator++(); 
                int operator*(); 
        };  

        iterator begin(); 
        iterator end(); 
}; 

int main(void)
{
    range R(10, 20); 

    for(range::iterator iter = R.begin(); 
        iter != R.end(); 
        ++iter)
        std::cout << "*iter=" << *iter << std::endl; 

    return 0; 
}
#include <iostream> 
#include <cstdlib> 
#include <stdexcept> 

class range 
{
    private: 
        int i_start, i_end; 

    public: 
        range(int _start, int _end) : i_start(_start), i_end(_end)
        { 
            if(_start >= _end)
            {
                i_start = _start; 
                i_end = _start; 
            }
        }

        range(int _end) : i_start(0), i_end(_end) 
        {
            if(_end < 0)
                i_end = 0; 
        } 

        class iterator; 

        iterator begin()
        {
            return iterator(i_start); 
        }

        iterator end()
        {
            return iterator(i_end); 
        }

        class iterator 
        {
            private: 
                int n; 

            public: 
                iterator(int _n=0) : n(_n)
                {

                }

                iterator operator++() 
                {
                    ++n; 
                    return *this; 
                }

                iterator operator--()
                {
                    --n; 
                    return *this; 
                }

                iterator operator++(int)
                {
                    iterator tmp(n); 
                    ++n; 
                    return tmp; 
                }

                iterator operator--(int)
                {
                    iterator tmp(n); 
                    --n; 
                    return tmp; 
                }

                bool operator==(const iterator& other)
                {
                    return n == other.n; 
                }

                bool operator!=(const iterator& other)
                {
                    return n != other.n; 
                }

                int operator*()
                {
                    return n; 
                }
        }; 
}; 

int main(void)
{
    range R1(10, 20); // from client psp: 10 to 19 collection 
    range R2(10); // from client psp : 0 to 9 

    std::cout << "Iterator over R1(10, 20):" << std::endl; 
    for(range::iterator iter = R1.begin(); iter != R1.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl;

    std::cout << "Iterator over R2(10):" << std::endl; 
    for(range::iterator iter = R2.begin(); iter != R2.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl; 

    range R3(10, 10); // from client psp: empty range object 
    range R4(30, 10); // from client psp: empty range object 

    std::cout << "Iterator over R3(10, 10):" << std::endl; 
    for(range::iterator iter = R3.begin(); iter != R3.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl;

    std::cout << "Iterator over R3(30, 10):" << std::endl; 
    for(range::iterator iter = R4.begin(); iter != R4.end(); ++iter)
        std::cout << "*iter = " << *iter << std::endl; 

    return 0; 
}


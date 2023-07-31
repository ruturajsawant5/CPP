#include <iostream> 
#include <stdexcept> 

template <int N> 
void test(void)
{
    std::cout << "N=" << N << std::endl; 
}

template <size_t N> 
class array 
{
    private: 
        int *pa; 

    public: 
        array() : pa(new int[N]) 
        {

        } 

        int get(int index) const 
        {
            if(index < 0 || index >= N)
                throw std::range_error("Out of index"); 
            return pa[index]; 
        }

        void set(int index, int val)
        {
            if(index < 0 || index >= N)
                throw std::range_error("Out of index"); 
            pa[index] = val; 
        }
        
        ~array() 
        {
            delete[] pa; 
        }
}; 

int main(void)
{
    test<10>(); 
    array<8> A; 
    for(int i = 0; i < 8; ++i)
    {
        A.set(i, (i+1) * 100); 
    }

    for(int i = 0; i < 8; ++i)
        std::cout << "Element at index " << i << " = " << A.get(i) << std::endl; 

    return (0); 
}

/* 
    Function_template   Instantiation   Call function 
        test            <10>            (); 

    Class Template      Instantiation   Create Object 
        array               <10>         A 
*/
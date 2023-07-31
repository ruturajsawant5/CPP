#include <iostream> 
#include <stdexcept>

template <typename T, size_t N> 
class array 
{
    private: 
        T* p_arr;
        size_t _N; 
    public: 
        array() : _N(N), p_arr(new T[N]) 
        {   

        }

        ~array()
        {
            delete[] p_arr; 
        }

        T get(size_t index) const 
        {
            if(index >= N)
                throw std::range_error("Index out of range"); 
            return p_arr[index]; 
        }

        void set(size_t index, T element)
        {
            if(index >= N)
                throw std::range_error("Index out of range"); 
            p_arr[index] = element; 
        }

        size_t size() const 
        {
            return _N; 
        }
}; 

int main(void)
{
    const size_t ARRAY_LENGTH=10; 
    array<int, ARRAY_LENGTH> iarr; 
    array<double, ARRAY_LENGTH> darr; 

    for(size_t i=0; i<ARRAY_LENGTH; ++i)
    {
        iarr.set(i, (i+1)*10); 
        darr.set(i, (i+1)*10/4.7); 
    }

    for(size_t i=0; i<ARRAY_LENGTH; ++i)
    {
        std::cout << "iarr[" << i << "]:" << iarr.get(i) << std::endl 
                    << "darr[" << i << "]:" << darr.get(i) << std::endl; 
    }

    return (0); 
}

/* 
    array -> class template 
    array<int, ARRAY_LENGTH> -> class 
    array<int, ARRAY_LENGTH> -> iarr -> OBJECT 

    float f; 

    array<int, ARRAY_LENGTH> iarr; 

    array<int, ARRAY_LENGTH>* p_arr; 

    array<int, ARRAY_LENGTH>& ref = i_arr; 
    array<int, ARRAY_LENGTH>&& rref; 

    int n; 
    int* p; 
    int& ref = n; 
    int&& ref; 
*/
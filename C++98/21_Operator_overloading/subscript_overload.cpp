#include <iostream> 
#include <cstdio> 
#include <cstdlib>
#include <stdexcept> 

class vector
{
    private: 
        int* pa; 
        size_t N; 

    public: 

        vector() : pa(NULL), N(0) {} 

        void push_back(int new_data)
        {
            N += 1;
            pa = (int*)realloc(pa, N * sizeof(int)); 
            if(!pa)
                throw std::bad_alloc(); 
            pa[N-1] = new_data; 

        }

        int& operator[](size_t index)
        {
            if(index < 0 || index >= N)
                throw std::domain_error("Bad index"); 

            return *(pa + index); 
        }
                
        friend std::ostream& operator<<(std::ostream& os, vector& v); 

        ~vector()
        {
            free(pa); 
            pa = NULL; 
        }

        size_t size() const {return N; }
}; 

std::ostream& operator<<(std::ostream& os, vector& v)
{
    for(size_t i = 0; i != v.N; ++i)
        os << "v[]" << i << "]:" << v[i] << std::endl; 

    return os; 
}

int main(void)
{
    vector v; 
    
    for(int i = 0; i <= 100; i+=10)
        v.push_back(i);

    for(size_t i = 0; i != v.size(); ++i) 
        std::cout << "v[" << i << "]:" << v[i] << std::endl; 

    std::cout << v; 

    return (0); 
}
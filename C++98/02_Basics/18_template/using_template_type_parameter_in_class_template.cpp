#include <iostream> 
#include <stdexcept> 

using ssize_t=long long; 

namespace cpa 
{
    template <typename T> 
    class array
    {
        private: 
            T* pa; 
            ssize_t N; 
        
        public: 
            array(ssize_t _N) : N(_N), pa(new T[_N])
            {

            }

            T get(ssize_t i) const 
            {
                if(i < 0 || i >= N)
                    throw std::range_error("Out of index range"); 
                return pa[i]; 
            }

            void set(ssize_t i, T new_val)
            {
                if(i < 0 || i >= N)
                    throw std::range_error("Out of index range");
                pa[i] = new_val;                
            }

            ssize_t size() const 
            {
                return N; 
            }
            
            ~array()
            {
                delete[] pa; 
            }
    }; 
}

int main(void)
{
    cpa::array<int> ia(10);
    cpa::array<double> da(8); 

    for(ssize_t i=0; i != ia.size(); ++i)
        ia.set(i, (i+1)*10); 

    for(ssize_t k=0; k != da.size(); ++k)
        da.set(k, (k+1)*100/7.5); 

    for(ssize_t i=0; i != ia.size(); ++i)
        std::cout << "ia[" << i << "]:" << ia.get(i) << std::endl;

    for(ssize_t i=0; i != da.size(); ++i)
        std::cout << "da[" << i << "]:" << da.get(i) << std::endl; 

    return (0); 
}


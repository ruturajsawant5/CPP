#include <iostream> 
#include <cstdio>
#include <cassert> 

namespace cpa 
{
    namespace dsa 
    {
        template <typename T> 
        class vector 
        {
            private: 
                T* p_arr; 
                size_t N; 

            public: 
                vector() : N(0), p_arr(0)
                {
                }

                void push_back(T element)
                {
                    p_arr = (T*)realloc(p_arr, (N+1)*sizeof(T)); 
                    assert(NULL != p_arr); 
                    N+=1; 
                    p_arr[N-1]=element; 
                }

                void show() const
                {
                    for(size_t i=0; i != N; ++i)
                        std::cout   << "p_arr[" 
                                    << i 
                                    << "]:" 
                                    << p_arr[i] 
                                    << std::endl; 
                }

                ~vector()
                {
                    delete[] p_arr; 
                }
        }; 
    }
}
#include <iostream> 
#include <stdexcept>
#include <cstdio> 
#include <cstring> 

class matrix 
{
    private: 
        double* pm; 
        size_t M, N; 

    public: 
        matrix(size_t _M, size_t _N) : M(_M), N(_N)
        {
            if(!(M && N))
                throw std::domain_error("Dimension cannot be zero"); 
            
            pm = (double*)malloc(M * N * sizeof(double)); 
            if(pm == 0)
                std::bad_alloc(); 

            memset(pm, 0, M * N * sizeof(double)); 
        }

        matrix operator+(const matrix& mt)
        {
            if(!(M == mt.M && N == mt.N))
                std::runtime_error("Incompatible dimensions"); 
            matrix mt_sum(M, N); 
            for(size_t i = 0; i < M; ++i)
                for(size_t j = 0; j < N; ++j)
                {
                    *(mt_sum.pm + i * N + j) =  *(pm + i * N + j) +      // M1[i][j]
                                                *(mt.pm + i * N + j);    // M2[i][j]
                }

            return mt_sum; 
        }

        matrix operator-(const matrix& mt)
        {
            if(!(M == mt.M && N == mt.N))
                std::runtime_error("Incompatible dimensions");        
        }

        matrix operator*(const matrix& mt)
        {
            if(N != mt.M)
                std::runtime_error("Incompatible dimensions"); 
        }

        ~matrix()
        {
            if(pm)
            {
                free(pm); 
                pm = NULL; 
            }
        }
}; 

//  TODO: Complete definitions of subtraction and multiplication 
//  and write Unit Testing Client 
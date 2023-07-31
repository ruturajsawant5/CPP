#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 

class str
{
    private: 
        char* pc; 
        size_t N; 

    public: 
        str(char* p_str) : pc(NULL), N(strlen(p_str))
        {
            if(N > 0)
            {
                pc = (char*)calloc(1, N+1); 
                assert(pc); 
                strncpy(pc, p_str, N); 
            }
        }

        str operator*(size_t M)
        {
            size_t rsN = N * M + 1; 
            str rsS(""); 
            rsS.N = rsN; 
            rsS.pc = (char*)calloc(1, rsS.N); 
            assert(rsS.pc); 
            for(size_t i = 0; i < N*M; i += N)
                strncpy(rsS.pc + i, pc, N); 

            return rsS; 
        }

        void show() const 
        {
            printf("%s\n", pc); 
        }

        ~str()
        {
            free(pc); 
            pc = NULL; 
            N = 0; 
        }

}; 

int main(void)
{
    str s1("Hello"); 
    size_t M = 5; 

    str s2 = s1 * 5; 
    s1.show(); 
    s2.show(); 
    puts("SUCCESS"); 
    return (0); 
}
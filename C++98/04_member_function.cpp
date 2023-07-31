int f(int); 

class Test 
{
    private: 
        int p, q, r; 

    public: 
        // member function 
        int f(int n)
        {

        }
}; 

// GLOBAL OR STANDALONE OR C-LIKE FUNCTION 
int f(int n)
{
    return n * n; 
}

int main(void)
{
    f(10); 

    objTest.f(); 
    pTestObj->f(); 
}

// 1950: COROUTINE(goroutine, async def, async calls) -> SUBROUTINE -> PROCEDURE 
// FUNCTION -> MEMBER FUNCTION (METHOD)
// STATIC MEMBER FUNCTION (STATIC METHOD)
// VIRTUAL MEMBER FUNCTION (VIRTUAL METHOD)
// PURE AND VIRTUAL MEMBER (ABSTRACT METHOD)


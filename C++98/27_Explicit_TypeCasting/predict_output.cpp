#include <cstdio> 
#include <cstdlib> 

class A 
{
    private: 
        float d; 
        int a[5]; 

    public: 
        A() : d(3.14), a{0x100, 0x200, 0x300, 0x400, 0x500} {} 
        void show() 
        {
            printf("d=%.2f\n", d); 
            for(int i = 0; i < 5; ++i)
                printf("a[%d]:%x\n", i, a[i]); 
        }
}; 

class B 
{
    private: 
        long long x; 
        long long y; 
        long long z; 
        long long w;
        long long u; 

    public: 
        long long getx() { return x; }
        long long gety() { return y; }
        long long getz() { return z; }
        void setx() { x = 0x123456; }
        void sety() { y = 0xaabbccdd; }
        void setz() { z = 0x10203040; }
}; 

int main()
{
    A objA; 

    objA.show(); 
    reinterpret_cast<B*>(&objA)->setz(); 
    objA.show(); 

    return 0; 
}

/* 
    type(objA) == A 
    type(&objA) == A* 
    inferred type of &objA == A* 
    casted type == B* 

    memory block will be of class A having 
    24 bytes 

    24 byte memory block -> B* 

    B::setz(): 

    setz: B* this = reinterpret_cast<B*>(&objA)
*/ 

/* 
    pahije tya type cha memory block 
    ghyaycha. 

    tyachya war pahije te operation implement karnar 
    ek function eka class madhye liha 

    memory block -> function asnarya type madhye 
    reinterpret_cast 

*/

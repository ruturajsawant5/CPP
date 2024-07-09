#include <iostream> 
#include <typeinfo> 

char c; 
unsigned char uc; 
short s; 
unsigned short us; 
int i; 
unsigned int u; 
long L; 
unsigned long uL; 
long long LL; 
unsigned long long uLL; 

float f; 
double d; 
long double dd; 

int* p_int; 
double* p_double; 

struct Date 
{
    int day, month, year; 
}myDate; 


class node
{
    private: 
        int data; 
        node* prev, *next;
}N;

int a[5]; 
struct Date aDate[10]; 
node aNode[7]; 

class B 
{
    public: 
        void f() {} 
        virtual void g() {} 
}objB; 

class D : public B
{
    public: 
        void g() {} 
        void h() {} 
}objD; 

class I 
{
    public: 
        virtual void f1() = 0; 
        virtual void f2() = 0; 
        virtual void f3() = 0;
}; 

class Component : public I 
{
    public: 
        void f1() {} 
        void f2() {} 
        void f3() {}
}objComponent; 

template <typename T> 
class X 
{
    private: 
        T v; 
}; 

X<int> iX; 
X<float> fX; 

int main(void)
{
    std::cout << "type(c) = " << typeid(c).name() << std::endl; 
    return 0; 
}
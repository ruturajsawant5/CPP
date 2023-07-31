#include <iostream> 
#include <cstdlib> 

void test(int* p, int& ref); 

int main(void)
{
    int n = 100; 
    int* p = &n; 

    *p = 200; 
    int k = *p; 

    int& ref = n;

    ref = 500; 
    k = ref; 

    std::cout << "BEFORE:ref:" << ref << std::endl; 
    n = 1000; 
    std::cout << "AFTER:ref:" << ref << std::endl; 

    /* 
        int& ref;   // not allowed, error 
        ref = n;     
    */ 
   test(&n, n); 

}

void test(int* p, int& ref)
{
    *p = 2000; 
    ref = 3000; 
}

void test_swap()
{
    int p=100, q=200; 
    swap(p, q); 
}

void swap(int& ref1, int& ref2)
{
    int tmp; 

    tmp = ref1; 
    ref1 = ref2; 
    ref2 = tmp; 
}


/* 
    class X 
    {
        public static void test_1()
        {
            T ref = new T(data); 
            test_2(ref); 
        }

        public static void teset_2(T input_ref)
        {

        }

}
*/

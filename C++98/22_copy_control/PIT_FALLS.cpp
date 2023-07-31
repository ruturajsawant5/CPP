#include <iostream> 

class HasPtr
{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m)) 
        {

        }

        int get_ptr_data() const 
        {
            return *ptr; 
        }

        void set_ptr_data(int new_data)
        {
            *ptr = new_data; 
        }

        void invalidate_ptr() 
        {
            delete ptr; 
        }

        ~HasPtr()
        {
            delete ptr; 
        }

        /* 
            COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD 
            WILL BE SYNTHESIZED (THEREFORE TYPED IN COMMENTS)
        */

       /* 
            HasPtr(const HasPtr& other) : n(other.n), ptr(other.ptr)
            {

            }
       */

      /* 
            HasPtr& operator=(const HasPtr& other)
            {
                n = other.n; 
                ptr = other.ptr; 

            }
      */


}; 

int main(void)
{
    HasPtr hp1(100, 200); 
    HasPtr hp2(hp1); 
    HasPtr hp3(400, 500); 

    /* 
        Pitfall 1:  Ptr in hp1 and hp2 contain same address. 
                    If you are aware of it then its not a pitfall. 
                    Otherwise it is. 

        int n = hp2.get_ptr_data(); 
        hp1.set_ptr_data(5000); 
        int m = hp2.get_ptr_data(); 

        m != n will be true. change made in pointee of ptr through 
        one HasPtr object will be visible in other
    */

   /* 
        Pitfall 2: 
            hp2.invalidate_ptr(); // ptr of hp1 is also invalidated. 
            int m = hp1.get_ptr_data(); // seg fault
   */

    /* 
        Pitfall 3: 
            Both hp1 and hp2 will be passed through destructor. 
            While executing delete ptr statement for second destrutor, 
            segmentation fault will occur. 
    */

   /* 
        Pitfall 4: 
            hp1 = hp3; 
        Both hp1 and hp3 are constructed objects at this point. 
        Therefore, hp1.ptr = hp3.ptr will result into a memory leak. 
   */

    return (0); 

}
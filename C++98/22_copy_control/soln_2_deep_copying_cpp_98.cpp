class HasPtr 
{
    private: 
        int n; 
        int* ptr; 

    public: 
        /* 
            You write 
                1) Copy constructor 
                2) Overload assignment operator 
            so as to ensure a separate address in ptr 
            for every distinct object. 

            Mathematically, 

            Let 
            
            type(hp1) == type(hp2) == HasPtr AND &hp1 != &hp2  // PREMISE 

            hp1.ptr != hp2.ptr;  // CONCLUSION

        */

       HasPtr(int _n, int _m) : n(_n), ptr(new int(_m))
       {

       }

       HasPtr(const HasPtr& other) : n(other.n), ptr(new int(*other.ptr))
       {
            
       }

       HasPtr& operator=(const HasPtr& other)
       {
            n = other.n; 
            *ptr = *other.ptr; 
            return *this; 
       }
}; 


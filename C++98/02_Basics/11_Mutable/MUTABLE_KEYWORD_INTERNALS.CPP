class Test 
{
    private: 
        int n; 
        int m; 
    public: 
        Test() : n(0), m(0) {} 

        int get() const 
        {
            // m = m + 1; // CTE 
            // this->m = this->m + 1; 
            // type(this) == const Test* this 

            const_cast<Test*>(this)->m = m + 1; 
            // mutable keyword allows us not to write 
            // const_cast<Test*>(this) 
            // fore modifying in 'm' in a const member function 
            return n; 
        } 

        int set(int new_n)
        {
            n = new_n; 
        }
}; 
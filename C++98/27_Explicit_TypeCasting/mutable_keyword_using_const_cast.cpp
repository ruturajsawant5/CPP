class A 
{
    private: 
        int m; 
        mutable int n; 

    public: 
        int getm() const 
        {
            // const A* this; 
            // this->m = rhs; // error 
            // this->n = rhs; // error 
            n = 500; 
             const_cast<A*>(this)->n = 500; 
            return m; 
        }
};
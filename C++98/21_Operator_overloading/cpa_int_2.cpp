class cpa_int
{
    private: 
        int n; 
    public: 
        cpa_int(int _n) : n(_n)
        {

        }

        cpa_int operator++()
        {
            ++n; 
            return *this; 
        }

        // HIGH LEVEL JUGAD 
        cpa_int operator++(int)
        {
            cpa_int tmp(n); 
            n++; 
            return tmp; 
        }

        cpa_int operator--()
        {
            --n; 
            return *this; 
        }

        // HIGH LEVEL JUGAD 
        cpa_int operator--(int)
        {
            cpa_int tmp(n); 
            n--; 
            return tmp;    
        }

        /*
        !objT;    // logical not 
        ~objT;    // bitwise not 
        ++objT;     // pre-increment 
        --objT;     // pre-decrement   
        objT++;     // post-increment
        objT--;     // post-decrement 
        */ 
}; 

/////////////////////////////////////////////////////




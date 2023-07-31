template <typename T> 
class Greater
{
    private: 
        bool (*pfn) (const T&, const T&); 
    
    public: 
        bool operator()(const T& r1, const T& r2)
        {
            return pfn(r1, r2); 
        }
}; 

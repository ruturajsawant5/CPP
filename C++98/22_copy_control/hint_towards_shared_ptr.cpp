template <typename T> 
class shared_ptr
{
    private: 
        T* ptr; 
        size_t ref_count; 
}; 

int main(void)
{
    shared_ptr<int> p_shared_int(); 
}


class HasPtr
{
    private: 
        int n; 
        shared_ptr<int> p_shared_int; 
}; 
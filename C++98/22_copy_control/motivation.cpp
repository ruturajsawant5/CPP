/* 
    shared_ptr<T>
    unique_ptr<T> 
    weak_ptr<T> 
/////////////////////////
    move semantics 
    T obj(std::move(obj1)); 
    obj1 = std::move(obj2); 
*/

class HasPtr
{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m))
        {

        }

    
}; 

int main(void)
{
    HasPtr hp1(100, 200); 
    // HasPtr::HasPtr(const HasPtr& ref)
    // HasPtr::HasPtr(&hp2, hp1)
    HasPtr hp2(hp1); 
    HasPtr hp3(300, 400); 

    hp3 = hp2; 

    return 0; 
}

// CATEGORY I: 
//  Default constructor 
//  Parameterised constructor 

// T() {}

// CATEGORY II : 
//  COPY CONSTRUCTOR 


// Let T be a data type and let * be a binary operator 
// which expects both operands of type T and is infix. 

class T 
{
    private: 
        // data layout 

    public: 
        T() {} 
        // optional paraterised constructor 

        // header of call back function to implement 
        // binary infix operator * which accepts 
        // both objects of type T and return new object 
        // of type T by value 

        T operator*(const T& other)
        {
            T objT; 

            // populate all members of objT 
            // using members of this and other. 
            // objT.mem can be set using this->mem and other.mem 
            // to set objT.mem other members of T such this->mem1 
            // other.mem2 may also be used! 

            return objT; 
        }
}; 

// Client 
int main(void)
{
    T obj1; // optional initialisation data for using parameterised constructor 
    T obj2; // optional initialisation data for using parameterised constructor 
    T obj3; 

    obj3 = obj1 * obj2; 
    // obj1 * obj2 
    // == 
    // obj3 = T::operator*(&obj1, obj2); 
    // parameter passing 
    // formal param 1 of T::operator* --> T* this = &obj1 
    // formal param 2 of T::operator* --> const T& other = obj2 
    // local variable objT will be constructed by data manip statements in 
    // T::operator* 
    // return value works as follows 
    // obj3 = objT; // memberwise assignment of obj3 and objT 
    // after assignment objT is removed as stack frame of T::operator* is removed 
}

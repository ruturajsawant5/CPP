/* 
    class T{} 

    objT -> object of class T 

    *objT; 

    * is a unary operator 

    class T 
    {
        // RET = return type of programmers choice 
        // or void 
        RET operator*()
        {
            // meaning of unary prefix or postfix operator * 
            // in the contex of type T 
        }
    }; 

    examples 

    UNARY PREFIX
    !objT;    // logical not 
    ~objT;    // bitwise not 
    *objT     // de-reference operator 
    ++objT;     // pre-increment 
    --objT;     // pre-decrement   

    UNARY POSTFIX
    objT++;     // post-increment
    objT--;     // post-decrement   

    ADVANCED UNARY OPERATOR (UNARY POSTFIX)
    objT[i];    // subscript 
    objT();     // call operator 
*/
/* 
    lhs = rhs 
    RHS evaluate -> Assembly instruction 

    rhs -> operands and operator -> rhs expression type infer 
    lhs -> expr -> lvalue -> type infer 

    type(lhs_expr) = type(rhs_expr)

    -------------------------------------------

    if type(lhs_expr) != type(rhs_expr)

    COMPILER TRIES TO TYPE CAST 
    RHS_EXPR into LHS_EXPR 

    assignment operator will be 
    evaluated in the context of 
    LHS type but will be applied on 
    RHS type. 

    e.g. 

    int n = 10; 
    int m; 

    m = n; 

    type(m) == type(n)
    m is an lvalue expr. 

    movl    n, %eax
    movl    %eax, m 

    float f; 
    int n = 100; 

    f = n; 

    1) type(f) != type(n)
    f = (float)n; 

    float f1, f2; 

    f1 = f2; 

    flds f2 
    fsts f1 

    class B1 {}; 
    class B2 {}; 
    class B3 {}; 

    class D : public B1, public B2, public B3 
    {

    }; 

    B3* pB3 = new D; 
    B2* pB2 = new D; 
    B1* pB1 = new D; 

    [       ] D non-static data 
    [       ] B3 object     N3 
    [       ] B2 object     N2 
    [       ] B1 object     N1 
    pD

    B3* pB3 = new D; 

    type(pB3) = B3* 
    type(new D) = D* 

    type(lhs) != type(rhs)
    type cast rhs into lhs 

    pB3 = new D; 

    lhs = rhs; 

    PROMOTIONS: 
    char->unsigned char->short->unsigned short->int->unsigned int->long->unsigned long
    ->long long ->unsigned long long 

    char->unsigned char->short->unsigned short->int->unsigned int->float->double

    char->unsigned char->short->unsigned short->int->unsigned int->long int
    unsigned long -> long long -> unsigned long long -> double 

    GENERIC POINTER: 

    C Programming Language. 
    lhs = rhs; 

    type(lhs) = void* 
    type(rhs) can any T* (where T is ANY DATA TYPE DEFINED IN CODE)

    lhs = rhs; 

    type(lhs) = T* 
    type(rhs) = void* 

    T* -> void* 
    void* -> T* 
    implicit conversions C compiler rule set madhye ahet 

    T* -> void* is allowed 

    void* p = pT; where pT is pointer type T, where T is any type 

    T* ptr = p;  where p is void*, pT is pointer to any other non-void type 
    iS NOT ALLOWED 

    Implicit Type Conversion Category 3: 
    Derived* -> Base* 

    T1* pT1 = expr;     (type(expr) == T2* and T1 ! T2)
    then T2 must be a direct or indirect sub-class of T1. 

    Base objB = objD; 
    Base::operator=(&objB, object B in objD);

    Base* pB = pD; // allowed D*->B* 
    Derived* pD = pB; // not allowed, B* -> D* 
    

*/



void f(void)
{
    int num; 
}

// num: time of allocation: dynamic
// allocation policy : per function call 
// storage class: auto 
// storage section: stack frame of function 
// lifetime = lifetime of function 

void f(void)
{
    static int num; 
}

// num: time of allocation: static 
// allocation policy : one time  
// storage section: data or bss 
// lifetime = lifetime of process 
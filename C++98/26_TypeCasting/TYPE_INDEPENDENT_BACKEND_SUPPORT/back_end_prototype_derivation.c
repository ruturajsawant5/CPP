/* 
    CLIENT I expectation: 
    void register_funcion(int*(*pfn)(struct array*)); 
    void call_function(struct array*); 
    void get_return_value(int** pp_ret); 

    CLIENT II expectation: 

    void register_function(struct Date*(*pfn)(char*)); 
    void call_function(char*); 
    void get_return_value(struct Date** pp_date); 

    void register_function(void*(*pfn)(void*)); 
    void call_function(void* arg); 
    void get_return_value(void** pp); 

*/

void* (*g_pfn)(void*); 
void* ret; 

void register_function(void*(*pfn)(void*)); 
void call_function(void* arg); 
void get_return_value(void** pp); 


void register_function(void*(*pfn)(void*))
{
    g_pfn = pfn; 
}

void call_function(void* arg)
{
    ret = g_pfn(arg); 
}

void get_return_value(void** pp)
{
    *pp = ret; 
}
/* 
void* thread_entry_func(void*); 

int* thread_entry_1(double*); 

struct Date* thread_entry_2(char*); 

float* thread_entry_3(float*); 

void* p = expr with T*; 

void* fn(void*); 

pthread_create(, , (void*)(*)(void*),); 
pthread_join(pthread_t thread_id, void** pp_return); 

int* p = NULL; 

pthread_join(th1, (void**)&p); 

struct Date* pDate = NULL; 
pthread_join(th2, (void**)&pDate); 

float* pFloat = NULL; 
pthread_join(th3, (void**)&pFloat)

void caller()
{
    int* p_int; 
    float* p_float; 
    struct Date* pDate; 
    f(&p_int); 
    g(&p_float); 
    h(&p_date); 
}

void f(int** pp_int); 
void g(float** p); 
void h(struct Date** ppDate); 

*/
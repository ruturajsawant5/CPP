#ifndef WRAPPER_H 
#define WRAPPER_H 

void register_function(void*(*pfn)(void*)); 
void call_function(void* arg); 
void get_return_value(void** pp); 

#endif 
int pthread_create(pthread_t*, pthread_attr_t*, void*(*pfn)(void*), void* args); 

int pthread_join(pthread_t, void**); 
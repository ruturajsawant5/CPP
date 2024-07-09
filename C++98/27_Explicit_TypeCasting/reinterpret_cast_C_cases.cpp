#define OFFSET_OF(type,mem)     (reinterpret_cast(unsigned long long)(&reinterpret_cast<type*>(0)->mem))
#define CONTAINER_OF(addr, type, mem)   (reinterpret_cast<type*>(reinterpret_cast<char*>(addr) - OFFSET_OF(type, mem)))

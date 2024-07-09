const int num = 100; // 1. global const 

int main(void)
{
    static const int x = 100; // 2. local static + const 
}

// Under Linux O.S. = All literal strings are const
// except those which are assigned to character array 

// Under linux 
// 1. puts("Hello");        // "Hello"->rodata 
// 2. char* p = "Hello";    // "Hello"->rodata 
                            // irrespective of char* p 
                            // scope (global or local)
// 3. char msg[] = "Hello"; // "Hello" -> read write data section if global 
                            // goes to stack if local 

// On Windows: all these strings are read write 

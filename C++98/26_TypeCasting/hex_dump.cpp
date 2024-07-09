#include <stdio.h> 
#include <stdlib.h> 

void hex_dump_of_block(void* p, size_t N, const char* msg); 

unsigned char uc = 0x3f; 
short s = -1; // 0xff ff 
int n = 0xa0b0c0d0; 
unsigned long long int y = 0x10203040a0b0c0d0; 

class Date 
{
    private: 
        int day, month, year; 
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }
}; 

Date D(1, 1, 1970); 

int main(void)
{
    hex_dump_of_block((void*)&uc, sizeof(uc), "hex dump(uc):"); 
    hex_dump_of_block((void*)&s, sizeof(s), "hex dump(s):"); 
    hex_dump_of_block((void*)&n, sizeof(n), "hex dump(n):"); 
    hex_dump_of_block((void*)&y, sizeof(y), "hex dump(y):"); 
    hex_dump_of_block((void*)&D, sizeof(D), "hex dump(D):"); 

    return (0); 
}

void hex_dump_of_block(void* p, size_t N, const char* msg)
{
    size_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("BYTE(%llu)\t=\t%hhx\n", i, *(unsigned char*)((unsigned char*)p + i)); 
}


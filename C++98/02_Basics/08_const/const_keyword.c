#include <stdio.h> 
#include <stdlib.h> 

/* non pointer DDS */
const int num = 10;

struct Date { int dd, mm, yy}; 

const struct Date d = {1, 1, 1970}; 

const int arr[5] = {100, 200, 300, 400, 500};

int main(void)
{
    int* p = NULL; 

    p = &num; 

    *p = 100; 
}


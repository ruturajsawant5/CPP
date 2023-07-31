#include <stdio.h> 
#include <stdlib.h> 

const int num = 100; /* read only data section . protected by h/w and OS */

int main(void)
{
    const int cn = 200; /* STACK. not protected by h/w and OS */
    static const int x = 400; /* read only data section. protected by hw & OS*/
    int* p; 

   // p = &num;   // rhs type == const int* 
                // lhs type  == int* 
    // *p = 200;   // segmentation fault 

   // p = &cn; 
    *p = -300;  // this backdoor will work 

   // p = &x; 
    // *p = 6000;  // segmentation fault 

}
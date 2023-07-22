const int gn = 200; 

int main(void)
{
    const int n = 100; 
    int* p=0; 

    p = &n; 

    *const_cast<int*>(&n) = 200; 

    // int* 
    // const int* 

    return (0); 
}
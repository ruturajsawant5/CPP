#include <stdio.h> 
#include <stdlib.h> 

class cpa_int
{
    private: 
        int n; 
    public: 
        cpa_int(int _n = 0) : n(_n)
        {
        }

        cpa_int operator+(const cpa_int& other); 
        cpa_int operator-(const cpa_int& other); 
        cpa_int operator*(const cpa_int& other); 
        cpa_int operator/(const cpa_int& other); 
        cpa_int operator%(const cpa_int& other); 
        cpa_int operator<<(int shift_bits); 
        cpa_int operator>>(int shift_bits); 

        bool operator<(const cpa_int& other); 
        bool operator<=(const cpa_int& other); 
        bool operator>(const cpa_int& other); 
        bool operator>=(const cpa_int& other); 
        bool operator==(const cpa_int& other); 
        bool operator!=(const cpa_int& other); 

        bool operator&&(const cpa_int& other); 
        bool operator||(const cpa_int& other); 

        cpa_int operator&(const cpa_int& other); 
        cpa_int operator|(const cpa_int& other); 
        cpa_int operator^(const cpa_int& other); 

        cpa_int operator~(); 
        bool operator!(); 
        cpa_int operator-(); 

        cpa_int operator++(); 
        cpa_int operator++(int); 

        cpa_int operator--(); 
        cpa_int operator--(int); 

        void show(const char* msg = NULL)
        {
            if(msg)
                printf("%s:%x\n", msg, n); 
            else 
                printf("%x\n", n); 
        }
}; 

cpa_int cpa_int::operator+(const cpa_int& other)
{
    cpa_int tmp; 
    tmp.n = this->n + other.n; 
    return tmp; 
}

cpa_int cpa_int::operator-(const cpa_int& other)
{
    return cpa_int(this->n - other.n); 
}

cpa_int cpa_int::operator*(const cpa_int& other)
{
    return cpa_int(this->n * other.n); 
}

cpa_int cpa_int::operator/(const cpa_int& other)
{
    return cpa_int(this->n / other.n); 
}

cpa_int cpa_int::operator%(const cpa_int& other)
{
    return cpa_int(this->n % other.n); 
} 

cpa_int cpa_int::operator<<(int shift_bits)
{
    return cpa_int(this->n << shift_bits); 
}

cpa_int cpa_int::operator>>(int shift_bits)
{
    return cpa_int(this->n >> shift_bits); 
}

bool cpa_int::operator<(const cpa_int& other)
{
    return (this->n < other.n);  
}

bool cpa_int::operator<=(const cpa_int& other)
{
    return (this->n <= other.n); 
}

bool cpa_int::operator>(const cpa_int& other)
{
    return this->n > other.n; 
}

bool cpa_int::operator>=(const cpa_int& other)
{
    return (this->n >= other.n); 
}

bool cpa_int::operator==(const cpa_int& other)
{
    return (this->n == other.n); 
}

bool cpa_int::operator!=(const cpa_int& other)
{
    return (this->n != other.n); 
}

bool cpa_int::operator&&(const cpa_int& other)
{
    return (this->n && other.n); 
}

bool cpa_int::operator||(const cpa_int& other)
{
    return (this->n || other.n); 
}

cpa_int cpa_int::operator&(const cpa_int& other)
{
    return cpa_int(this->n & other.n); 
}

cpa_int cpa_int::operator|(const cpa_int& other)
{
    return cpa_int(this->n | other.n); 
}

cpa_int cpa_int::operator^(const cpa_int& other)
{
    return cpa_int(this->n ^ other.n); 
}

cpa_int cpa_int::operator~()
{
    return cpa_int(~n); 
}

bool cpa_int::operator!()
{
    return !n; 
}

cpa_int cpa_int::operator-()
{
    return cpa_int(-n); 
}

cpa_int cpa_int::operator++()
{
    ++n; 
    return *this; 
}

cpa_int cpa_int::operator++(int)
{
    cpa_int tmp(n); 
    n++; 
    return tmp; 
}

cpa_int cpa_int::operator--()
{
    --n; 
    return *this; 
}

cpa_int cpa_int::operator--(int)
{
    cpa_int tmp(n); 
    n--; 
    return tmp;
}

int main(void)
{
    cpa_int N1(0xf0f0f0); 
    cpa_int N2(0x0f0f0f); 
    cpa_int rs; 

    rs = N1 + N2; 
    rs.show("Add"); 

    rs = N1 - N2; 
    rs.show("Subtract"); 

    rs = N1 * N2; 
    rs.show("Mul:"); 

    rs = N1 / N2; 
    rs.show("Div"); 

    rs = N1 % N2; 
    rs.show("Mod"); 

    rs = N1 << 4; 
    rs.show("Left shift 4"); 

    rs = N2 >> 4; 
    rs.show("Right shift 4"); 

    if(N1 < N2)
        puts("N1 < N2"); 
    
    if(N1 <= N2)
        puts("N1 <= N2"); 
    
    if(N1 > N2)
        puts("N1 > N2"); 
    
    if(N1 >= N2)
        puts("N1 >= N2"); 

    if(N1 == N2)
        puts("N1 == N2"); 
    
    if(N1 != N2)
        puts("N1 != N2"); 

    if(N1 && N2)
        puts("N1 && N2 is True"); 
    else 
        puts("N1 && N2 is False"); 

    if(N1 || N2)
        puts("N1 || N2 is True"); 
    else 
        puts("N1 || N2 is False"); 

    rs = N1 & N2; 
    rs.show("Bitwise and"); 

    rs = N1 | N2; 
    rs.show("Bitwise or"); 

    rs = N1 ^ N2; 
    rs.show("Bitwise xor"); 

    rs = -N1; 
    rs.show("negate"); 

    printf("!N1 = %d\n", !N1); 

    rs = ~N2; 
    rs.show("Bitwise ~"); 

    cpa_int N(10); 

    rs = ++N; 
    rs.show("rs after Pre-increment"); // rs should be 11. decimal(11)==hex(B)
    N.show("N after pre-increment"); // N == hex(b)

    cpa_int rs1 = N++; // rs1 == hex(b), N==hex(c)
    rs1.show("rs after post increment"); 
    N.show("N after post-increment"); 

    return 0; 
}

/* 
    int rs; 
    int n = 10; 

    rs = ++n;   // n is increment first and then assigned 
                // both n and rs are 11 

    rs = n++;   // n is assigned first and then incremented 
                // rs is 11 and n is 12 
*/ 
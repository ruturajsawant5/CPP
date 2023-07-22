#include "list.hpp"
#include "vector.hpp" 

int main(void)
{
    cpa::dsa::list<int> lst_int; 
    cpa::dsa::list<double> lst_dbl; 
    cpa::dsa::vector<int> ivec; 
    cpa::dsa::vector<double> dvec; 

    for(int i=0; i < 10; ++i)
    {
        lst_int.insert_end((i+1)*100); 
        ivec.push_back((i+1)*100);
        lst_dbl.insert_end((i+1)*5.67); 
        dvec.push_back((i+1)*5.67); 
    }

    lst_int.show(); 
    lst_dbl.show(); 
    ivec.show(); 
    dvec.show(); 
    
    return 0; 
}   
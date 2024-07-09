#include "IList.hpp"

int main(void)
{
    IList* p_lst_1 = IList::get_instance(); 
    IList* p_lst_2 = IList::get_instance(); 
    IList* p_cat = NULL; 

    for(int data = 0; data <= 10; ++data)
    {
        p_lst_1->insert_end(data * 5); 
        p_lst_2->insert_end(data * 10); 
    }

    p_lst_1->concat(p_lst_2, &p_cat); 

    p_lst_1->show(); 
    p_lst_2->show(); 
    p_cat->show(); 

    delete p_lst_1; 
    p_lst_1 = 0; 

    delete p_lst_2; 
    p_lst_2 = 0; 

    delete p_cat; 
    p_cat = 0; 

    return 0; 
}
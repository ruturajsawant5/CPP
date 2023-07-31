#include <stdio.h> 
#include <assert.h> 
#include "list.h"

int main(void)
{
    list* p_list = 0; 
    data_t data; 
    status_t status; 

    p_list = new list; 
    p_list->show(); 
    printf("p_list->len():%d\n", p_list->len()); 

    assert(p_list->get_start(&data) == LIST_EMPTY); 
    assert(p_list->get_end(&data) == LIST_EMPTY);
    assert(p_list->pop_start(&data) == LIST_EMPTY);
    assert(p_list->pop_end(&data) == LIST_EMPTY);
    assert(p_list->remove_start() == LIST_EMPTY);
    assert(p_list->remove_end() == LIST_EMPTY);

    for(data = 0; data < 5; ++data)
        assert(p_list->insert_start(data) == SUCCESS); 
    p_list->show(); 

    for(data = 5; data < 10; ++data)
        assert(p_list->insert_end(data) == SUCCESS); 
    p_list->show(); 

    assert(p_list->insert_after(-10, 100) == LIST_DATA_NOT_FOUND); 
    assert(p_list->insert_before(-10, 200) == LIST_DATA_NOT_FOUND);

    assert(p_list->insert_after(0, 100) == SUCCESS); 
    assert(p_list->insert_before(0, 200) == SUCCESS);
    p_list->show(); 
    
    assert(p_list->get_start(&data) == SUCCESS); 
    printf("Start Data:%d\n", data); 
    p_list->show(); 

    assert(p_list->get_end(&data) == SUCCESS); 
    printf("End Data:%d\n", data); 
    p_list->show(); 

    assert(p_list->pop_start(&data) == SUCCESS); 
    printf("Start Data(removed):%d\n", data); 
    p_list->show(); 

    assert(p_list->pop_end(&data) == SUCCESS); 
    printf("End Data(removed):%d\n", data); 
    p_list->show(); 

    assert(p_list->remove_start() == SUCCESS);
    p_list->show();  

    assert(p_list->remove_end() == SUCCESS);
    p_list->show();  

    assert(p_list->remove_data(-10) == LIST_DATA_NOT_FOUND); 
    assert(p_list->remove_data(0) == SUCCESS); 
    p_list->show(); 

    assert(p_list->is_empty() == false); 
    puts("List is not empty"); 

    printf("Length:%d\n", p_list->len()); 

    delete p_list; 
    p_list = 0; 

    return 0; 
}
#include <stdio.h> 
#include "list.h"

node::node(data_t new_data) : data(new_data), prev(0), next(0) 
{
}

list::list()
{
    p_head_node = new node(0); 
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 
}

status_t list::insert_start(data_t new_data)
{
    generic_insert(p_head_node, new node(new_data), p_head_node->next); 
    return (SUCCESS); 
}

status_t list::insert_end(data_t new_data)
{
    generic_insert(p_head_node->prev, new node(new_data), p_head_node); 
    return (SUCCESS); 
}

status_t list::insert_after(data_t e_data, data_t new_data)
{
    node* e_node = 0; 

    e_node = this->search_node(e_data); // list::search_node(this, e_data)
    if(e_node == 0)
        return LIST_DATA_NOT_FOUND; 
    generic_insert(e_node, new node(new_data), e_node->next); 
    return (SUCCESS); 
}

status_t list::insert_before(data_t e_data, data_t new_data)
{
    node* e_node = 0; 

    e_node = this->search_node(e_data); // list::search_node(this, e_data)
    if(e_node == 0)
        return LIST_DATA_NOT_FOUND; 
    generic_insert(e_node->prev, new node(new_data), e_node); 
    return (SUCCESS); 
}

status_t list::get_start(data_t* p_start_data) 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    *p_start_data = this->p_head_node->next->data; 
    return SUCCESS; 
}

status_t list::get_end(data_t* p_end_data) 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    *p_end_data = this->p_head_node->prev->data; 
    return SUCCESS; 
}

status_t list::pop_start(data_t* p_start_data) 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    *p_start_data = this->p_head_node->next->data; 
    this->generic_delete(this->p_head_node->next); 
    return SUCCESS; 
}

status_t list::pop_end(data_t* p_end_data) 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    *p_end_data = this->p_head_node->prev->data; 
    this->generic_delete(this->p_head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_start() 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    this->generic_delete(this->p_head_node->next); 
    return SUCCESS; 
}

status_t list::remove_end() 
{
    if(this->is_empty() == true)
        return LIST_EMPTY; 
    this->generic_delete(this->p_head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_data(data_t r_data)
{
    node* p_delete_node = 0; 

    p_delete_node = this->search_node(r_data); 
    if(p_delete_node == 0)
        return LIST_DATA_NOT_FOUND; 
    generic_delete(p_delete_node); 

    return SUCCESS; 
}

bool list::is_empty() const 
{
    return ((this->p_head_node->next == this->p_head_node) && 
            (this->p_head_node->prev == this->p_head_node)
            );
}

bool list::find(data_t f_data) const
{
    return ((const_cast<list*>(this)->search_node(f_data)) != 0); 
}

len_t list::len() const 
{
    len_t length = 0; 
    for(node* p_run = this->p_head_node->next; 
        p_run != this->p_head_node; 
        p_run = p_run->next)
        ++length; 
    return (length); 
}

void list::show() const 
{
    printf("[START]<->"); 
    for(node* p_run = this->p_head_node->next; 
        p_run != this->p_head_node; 
        p_run = p_run->next)
        printf("[%d]<->", p_run->data); 
    puts("[END]"); 
}

list::~list()
{
    node* p_run, *p_run_next; 
    for(p_run = this->p_head_node->next; 
        p_run != this->p_head_node; 
        p_run = p_run_next)
        {
            p_run_next = p_run->next; 
            delete p_run; 
        }
    delete this->p_head_node;
    this->p_head_node = 0; 
}

// private member functions (static + non-static)

void list::generic_insert(node* p_beg, node* p_mid, node* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void list::generic_delete(node* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
    p_delete_node = 0; 
}

node* list::search_node(data_t s_data)
{
    for(node* p_run = this->p_head_node->next; 
        p_run != this->p_head_node; 
        p_run = p_run->next)
            if(p_run->data == s_data)
                return p_run; 
    return 0; 
}

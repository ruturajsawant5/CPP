#ifndef _LIST_H 
#define _LIST_H 

const int SUCCESS = 1; 
const int TRUE = 1; 
const int FALSE = 0; 

const int LIST_DATA_NOT_FOUND = 2; 
const int LIST_EMPTY = 3; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

class node
{
    friend class list; 
    private: 
        data_t data;
        node* prev; 
        node* next; 
        node(data_t new_data);  
}; 

class list 
{
    private: 
        node* p_head_node; 
        static void generic_insert(node* p_beg, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(data_t s_data); 

    public: 
        // default constructor:replaces create_list() 
        list(); 

        status_t insert_start(data_t new_data); 
        status_t insert_end(data_t new_data); 
        status_t insert_after(data_t e_data, data_t new_data); 
        status_t insert_before(data_t e_data, data_t new_data); 

        status_t get_start(data_t* p_start_data); 
        status_t get_end(data_t* p_end_data); 
        
        status_t pop_start(data_t* p_poped_data); 
        status_t pop_end(data_t* p_poped_data); 

        status_t remove_start(); 
        status_t remove_end(); 
        status_t remove_data(data_t r_data); 

        bool is_empty() const;
        len_t len() const; 
        bool find(data_t f_data) const; 
        void show() const; 

        // destructor -> replaces destroy_list()
        ~list(); 
}; 

#endif /* _LIST_H */ 
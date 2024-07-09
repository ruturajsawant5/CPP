#pragma once 

#include "IList.hpp"

class list_node
{
    friend class CList; 
    private: 
        int data; 
        list_node* prev, *next; 
        list_node(int data); 
}; 

class CList : public IList 
{
    private: 
        list_node* head_node; 
        static void generic_insert(list_node*, list_node*, list_node*); 
        static void generic_delete(list_node*); 
        list_node* search_node(int s_data); 
    public: 
        CList(); 
        ~CList(); 
        void insert_start(int d); 
        void insert_end(int d); 
        void insert_after(int ed, int d); 
        void insert_before(int ed, int d); 
        void get_start(int* p); 
        void get_end(int* p); 
        void pop_start(int* p); 
        void pop_end(int* p); 
        void remove_start(); 
        void remove_end(); 
        void remove_data(int d); 
        void show() const; 
        std::size_t len() const; 
        bool find(int d); 
        void concat(IList* other, IList** pp_cat_list); 
        void merge(IList* other, IList** pp_merged_list); 
        void get_reversed(IList** pp_reversed_list);
        void reverse(); 
}; 
 
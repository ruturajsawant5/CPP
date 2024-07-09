// List using class template with iterator 

#include <iostream>
#include <cstdlib> 

template <typename T> 
class node 
{
    public: 
        T data; 
        node* prev; 
        node* next; 
    
        node(T new_data) : data(new_data), prev(0), next(0)
        {

        }

        node(){}
}; 

template <typename T> 
class list 
{
    private: 
        node<T>* head_node; 

        static void g_insert(node<T>* beg, node<T>* mid, node<T>* end)
        {
            mid->next = end; 
            mid->prev = beg; 
            beg->next = mid; 
            end->prev = mid; 
        }

        static void g_delete(node<T>* p_delete_node)
        {
            p_delete_node->prev->next = p_delete_node->next; 
            p_delete_node->next->prev = p_delete_node->prev; 
            delete p_delete_node; 
        }

        node<T>* search_node(T s_data)
        {
            for(node<T>* run = head_node->next; run != head_node; run = run->next)
                if(run->data == s_data)
                    return run; 
            return NULL; 
        }

    public: 
        list() : head_node(new node<T>)
        {
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list()
        {
            node<T>* run, *run_next; 

            for(run = head_node->next; run != head_node; run = run_next)
            {
                run_next = run->next; 
                delete run; 
            }

            head_node = NULL; 
        }

        void insert_end(T new_data)
        {
            g_insert(head_node->prev, new node<T>(new_data), head_node); 
        }

        class iterator; 

        iterator begin()
        {
            return iterator(head_node->next); 
        }

        iterator end() 
        {
            return iterator(head_node); 
        }

        class iterator 
        {
            private: 
                node<T>* p_node; 

            public: 
                iterator(node<T>* _p_node = NULL) : p_node(_p_node) {} 

                iterator operator++()
                {
                    p_node = p_node->next; 
                    return *this; 
                }

                iterator operator--()
                {
                    p_node = p_node->prev; 
                    return *this; 
                }

                iterator operator++(int)
                {
                    iterator tmp(p_node)
                    p_node = p_node->next; 
                    return tmp; 
                }

                iterator operator--(int)
                {
                    iterator tmp(p_node); 
                    p_node = p_node->prev; 
                    return tmp; 
                }

                T operator*()
                {
                    return p_node->data;
                }

                bool operator==(const iterator& other)
                {
                    return p_node == other.p_node; 
                }

                bool operator!=(const iterator& other)
                {
                    return p_node != other.p_node; 
                }
        }; 
}; 


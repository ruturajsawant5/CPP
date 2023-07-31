#include <iostream> 

using status_t=int; 

namespace cpa 
{
    namespace dsa 
    {
        const int SUCCESS=1; 

        template <typename T> 
        class list; 

        template <typename T> 
        class node 
        {
            friend class list<T>; 
            private: 
                T data; 
                node* prev; 
                node* next; 
                node() : prev(0), next(0) 
                {

                } 

                node(T _data) : data(_data), prev(0), next(0) 
                {

                }
        }; 

        template <typename T> 
        class list 
        {
            private: 
                node<T>* p_head_node; 

                static void generic_insert( 
                                            node<T>* p_beg, 
                                            node<T>* p_mid, 
                                            node<T>* p_end
                                        )
                {
                    p_mid->next = p_end; 
                    p_mid->prev = p_beg; 
                    p_beg->next = p_mid; 
                    p_end->prev = p_mid; 
                }

                static void generic_delete( 
                                            node<T>* p_delete_node 
                                        )
                {
                    p_delete_node->prev->next = p_delete_node->next; 
                    p_delete_node->next->prev = p_delete_node->prev; 
                    delete p_delete_node; 
                } 
                
                node<T>* search_node(T s_data)
                {
                    for(node<T>* p_run = p_head_node->next; 
                        p_run != p_head_node; 
                        p_run = p_run->next)
                        if(p_run->data == s_data)
                            return (p_run); 

                    return 0; 
                }

            public: 
                list()
                {
                    p_head_node = new node<T>; 
                    p_head_node->prev = p_head_node; 
                    p_head_node->next = p_head_node; 
                } 

                ~list()
                {
                    node<T>* p_run; 
                    node<T>* p_run_next; 

                    for(p_run = p_head_node->next; 
                        p_run != p_head_node; 
                        p_run = p_run_next)
                    {
                        p_run_next = p_run->next; 
                        delete p_run; 
                    }

                    delete p_head_node; 
                    p_head_node = 0; 
                }

                status_t insert_end(T new_data)
                {
                    generic_insert(p_head_node->prev, 
                                    new node<T>(new_data), 
                                    p_head_node); 
                    return SUCCESS; 
                }

                void show() const
                {
                    std::cout << "[START]<->"; 
                    for(node<T>* p_run = p_head_node->next; 
                        p_run != p_head_node; 
                        p_run = p_run->next)
                        std::cout << "[" << p_run->data << "]<->"; 
                    std::cout << "[END]" << std::endl; 
                }
        };   
    }
}

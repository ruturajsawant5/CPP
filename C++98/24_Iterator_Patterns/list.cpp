#include <iostream> 
#include <cstdlib>

class node 
{
    friend class list; 
    // friend class list::iterator; 
    private: 
        int data; 
        node* prev, * next; 
        node(int _data) : data(_data), prev(0), next(0) {} 
}; 

class list 
{
    private: 
        node* head_node; 

        static void g_insert(node* beg, node* mid, node* end)
        {
            mid->next = end; 
            mid->prev = beg; 
            beg->next = mid; 
            end->prev = mid; 
        }

        static void g_delete(node* d_node) 
        {
            d_node->prev->next = d_node->next; 
            d_node->next->prev = d_node->prev; 
            delete d_node; 
        }

        node* search_node(int data)
        {
            for(node* run = head_node->next; 
                run != head_node; 
                run = run->next)
                if(run->data == data)
                    return run; 
            return 0; 
        }
    
    public: 
        list() : head_node(new node(-1))
        {
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list()
        {
            node* run, *run_next; 
            for(run = head_node->next; run != head_node; run = run_next)
            {
                run_next = run->next; 
                delete run; 
            }
        }

        void insert_end(int new_data)
        {
            g_insert(head_node->prev, new node(new_data), head_node); 
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
                node* p_node; 

            public: 
                iterator(node* _node = 0) : p_node(_node) {} 

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
                    iterator tmp(p_node); 
                    p_node = p_node->next; 
                    return tmp; 
                }

                iterator operator--(int)
                {
                    iterator tmp(p_node); 
                    p_node = p_node->prev; 
                    return tmp; 
                }

                int operator*()
                {
                    return this->p_node->data; 
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

int main(void) 
{
    list L;

    for(int data = 10; data <= 100; data += 10)
        L.insert_end(data); 

    for(list::iterator iter = L.begin(); iter != L.end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    return 0; 
}

/* 
class T 
{
    // some class 
}; 

int main()
{
    T ret = some_func(); 
}

T some_func()
{
    T local_obj(some_data); 

    return local_obj; 
}

*/
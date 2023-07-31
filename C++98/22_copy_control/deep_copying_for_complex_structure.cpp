#include <iostream> 
#include <stdexcept> 

class node 
{
    friend class list; 
    friend std::ostream& operator<<(std::ostream &os, const list& L); 
    private: 
        int data; 
        node* prev; 
        node* next; 

        node(int new_data) : data(new_data), prev(0), next(0) 
        {

        }
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

        static void g_delete(node* p)
        {
            p->prev->next = p->next; 
            p->next->prev = p->prev; 
            delete p; 
        }

        node* search_node(int s_data)
        {
            node* run; 

            for(run = head_node->next; run != head_node; run = run->next)
                if(run->data == s_data)
                    return run; 
            return 0; 
        }

        static void clone(node** pp_head_node, node* head_node)
        {
            node* clone_head = new node(-1); 

            clone_head->prev = clone_head; 
            clone_head->next = clone_head; 

            for(node* run = head_node->next; run != head_node; run = run->next)
                g_insert(clone_head->prev, new node(run->data), clone_head); 

            *pp_head_node = clone_head; 
        }

        static void destroy_list(node** pp_head_node)
        {
            node* head_node = *pp_head_node; 
            node* run, *run_next; 

            for(run = head_node->next; run != head_node; run = run_next)
            {
                run_next = run->next; 
                delete run; 
            }
        }

    public: 
        list()
        {
            head_node = new node(-1); 
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list() 
        {
            destroy_list(&head_node); 
        }

        void insert_start(int new_data)
        {
            g_insert(head_node, new node(new_data), head_node->next); 
        }

        void insert_end(int new_data)
        {
            g_insert(head_node->prev, new node(new_data), head_node); 
        }

        // deep copying
        list(const list& other)
        {
            clone(&this->head_node, other.head_node); 
        }

        // deep copying 
        list& operator=(const list& other) 
        {
            destroy_list(&this->head_node); 
            clone(&this->head_node, other.head_node); 
            return *this; 
        }

        friend std::ostream& operator<<(std::ostream &os, const list& L); 
}; 

std::ostream& operator<<(std::ostream &os, const list& L)
{
    node* run; 
    os << "[START]<->"; 
    for(run = L.head_node->next; run != L.head_node; run = run->next)
        os << "[" << run->data << "]<->"; 
    os << "[END]" << std::endl; 
    return os; 
}

int main(void)
{
    list L1; 

    for(int data = 5; data <= 95; data += 10)
        L1.insert_end(data); 

    std::cout << "BEFORE" << std::endl; 
    std::cout << "L1" << L1; 
    list L2(L1); 
    std::cout << "AFTER" << std::endl; 
    std::cout << "L1" << L1; 
    std::cout << "L2" << L2; 

    L1.insert_start(500); 
    L2.insert_start(1000); 

    std::cout << "DEEP COPYING PROOF" << std::endl; 
    std::cout << "L1" << L1; 
    std::cout << "L2" << L2; 

    list L3; 
    for(int data = 10; data <= 100; data += 10)
        L3.insert_end(data);   

    std::cout << "BEFORE" << std::endl; 
    std::cout << "L1" << L1; 
    std::cout << "L3" << L3;
    L1 = L3;  
    std::cout << "AFTER" << std::endl; 
    std::cout << "L1" << L1; 
    std::cout << "L3" << L3;

    L1.insert_start(-1000); 
    L3.insert_start(-5000); 

    std::cout << "DEEP COPYING PROOF" << std::endl; 
    std::cout << "L1" << L1; 
    std::cout << "L3" << L3;

    return 0; 
}

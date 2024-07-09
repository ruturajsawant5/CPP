// NM dsa -> NM ds -> namespace list -> C node, C list -> under C list -> C iterator 
// declare methods in class but defined them outside class 

#include <iostream>

// header file 
namespace dsa 
{
    namespace ds 
    {
        namespace list
        {
            class node 
            {
                friend class list; 
                private: 
                    int data; 
                    node* prev; 
                    node* next; 
                    node(int new_data=0); 
            };  

            class list 
            {
                private: 
                    node* p_head_node; 
                    static void g_insert(node* beg, node* mid, node* next); 
                    static void g_delete(node* p_delete_node); 
                    node* search_node(int s_data); 
                public: 
                    list(); 
                    ~list();
                    void insert_start(int data); 
                    void insert_end(int data); 
                    void insert_after(int e_data, int data); 
                    void insert_before(int e_data, int data); 
                    void get_start(int* p_data); 
                    void get_end(int* p_data); 
                    void pop_start(int* p_data); 
                    void pop_end(int* p_data); 
                    void remove_start(); 
                    void remove_end(); 
                    void remove_data(int data); 
                    int get_length() const ;
                    friend std::ostream& operator<<(std::ostream&, const list& lst);  
                    list operator+(const list& other);
                    class iterator; 
                    iterator begin(); 
                    iterator end(); 
                    class iterator 
                    {
                        private: 
                            node* p_node; 
                        public: 
                            iterator(node* p_node = 0); 
                            iterator operator++(); 
                            iterator operator--(); 
                            iterator operator++(int); 
                            iterator operator--(int); 
                            bool operator==(const iterator& other); 
                            bool operator!=(const iterator& other); 
                            int operator*(); 
                    }; 
            }; 
        }
    }
}

// In cpp file 
// include header file 
// node constructor 
dsa::ds::list::node::node(int new_data)
{

}

// private and static member functions of class list 

void dsa::ds::list::list::g_insert(
                                dsa::ds::list::node* beg, 
                                dsa::ds::list::node* mid, 
                                dsa::ds::list::node* end
                            )
{

}

void dsa::ds::list::list::g_delete(dsa::ds::list::node* p_delete_node)
{

}

// private and non-static member functions 
dsa::ds::list::node* dsa::ds::list::list::search_node(int s_data)
{

}

// nonstatic and public members 

// constructor -> list
dsa::ds::list::list::list() 
{

}

// destructor 
dsa::ds::list::list::~list() 
{

}

void dsa::ds::list::list::insert_start(int new_data)
{

}

void dsa::ds::list::list::insert_end(int new_data)
{

}

void dsa::ds::list::list::insert_after(int e_data, int new_data)
{

}

void dsa::ds::list::list::insert_before(int e_data, int new_data)
{

}

void dsa::ds::list::list::get_start(int* p_data)
{

}

void dsa::ds::list::list::get_end(int* p_data)
{

}

void dsa::ds::list::list::pop_start(int* p_data)
{

}

void dsa::ds::list::list::pop_end(int* p_data)
{

}

void dsa::ds::list::list::remove_start()
{

}

void dsa::ds::list::list::remove_end() 
{

}

void dsa::ds::list::list::remove_data(int r_data)
{

}

int dsa::ds::list::list::get_length() const 
{

}

dsa::ds::list::list dsa::ds::list::list::operator+(const dsa::ds::list::list& other)
{

}

std::ostream& operator<<(std::ostream& os, const dsa::ds::list::list& other)
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::begin() 
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::end() 
{

}

// iterator members 
// constructor 

dsa::ds::list::list::iterator::iterator(node* p_node) 
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::iterator::operator++()
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::iterator::operator--()
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::iterator::operator++(int)
{

}

dsa::ds::list::list::iterator dsa::ds::list::list::iterator::operator--(int)
{

}

int dsa::ds::list::list::iterator::operator*()
{

}

bool dsa::ds::list::list::iterator::operator==(const dsa::ds::list::list::iterator& other)
{

}

bool dsa::ds::list::list::iterator::operator!=(const dsa::ds::list::list::iterator& other)
{

}

void test_1(void)
{
    dsa::ds::list::list L; 

  
}

void test_2(void)
{
    using dsa::ds::list::list; 

    list L1; 
    list L2; 
}

void test_3(void)
{
    using namespace dsa; 

    ds::list::list L1; 
}

void test_4(void)
{
    using namespace dsa::ds::list; 

    list L1; 
    list L2; 
}

// Unqualified Name Lookup 
// Absolutely qualified name lookup 
// Partially qualified name lookup 

// abc.txt 

// /home/yogeshwar/root/src/cpa/cpp/batch_21/sesion_35/abc.txt 

// cpa/cpp/batch_21/session_35/abc.txt
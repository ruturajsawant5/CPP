class bst_node
{
    friend class bst; 
    private: 
        int data; 
        bst_node* left; 
        bst_node* right; 
        bst_node* parent; 
}; 

class bst 
{
    private: 
        bst_node* root_node; 
        int nr_elements; 
    public: 
        void insert(int new_data); 
        void remove(int e_data); 
        bool find(int s_data); 
        void inorder(); 
        void preorder(); 
        void postorder(); 
}; 

////////////////////////////////////////////////

typedef enum color { RED=0, BLACK }; 

class rb_node
{
    friend class rb_tree; 
    private: 
        int data; 
        color c; 

        rb_node* left; 
        rb_node* right; 
        rb_node* parent; 
}; 

class rb_tree
{
    private: 
        rb_node* root_node; 
        rb_node* nil; 
        int nr_elements; 

    public: 
        void insert(int new_data); 
        void remove(int e_data); 

        bool find(int s_data); 
        void inorder(); 
        void preorder(); 
        void postorder();

}; 

////////////////////////////////////////////////////

class bst_node
{
    friend class bst; 
    private: 
        int data; 
        bst_node* left; 
        bst_node* right; 
        bst_node* parent; 
}; 


class bst 
{
    private: 
        bst_node* root_node; 
        int nr_elements; 
    public: 
        virtual void insert(int new_data); 
        virtual void remove(int e_data); 
        bool find(int s_data); 
        void inorder(); 
        void preorder(); 
        void postorder(); 
}; 

class rb_tree : public bst
{

    public: 
        void insert(int new_data); 
        void remove(int e_data); 
  
}; 

///////////////////////////////////////////////////////////

class bst_node
{
    friend class bst; 
    friend class rb_tree; 
    protected: 
        int data; 
        bst_node* left; 
        bst_node* right; 
        bst_node* parent; 
}; 

class rb_node : protected bst_node 
{
    friend class rb_tree; 
    protected: 
        color c; 
        rb_node(int new_data); 
}; 

class bst 
{
    private: 
        bst_node* root_node; 
        int nr_elements; 
    public: 
        virtual void insert(int new_data); 
        virtual void remove(int e_data); 
        bool find(int s_data); 
        void inorder(); 
        void preorder(); 
        void postorder(); 
}; 

class rb_tree : public bst
{
    protected: 
        rb_node* rb_root_node; 
        rb_node* nil; 
    public: 
        void insert(int new_data); 
        void remove(int e_data); 
  
}; 
/* BST */

struct bst_node
{
    int data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    int nr_elements; 
}; 

/////////////////////////////////////////////

/* RB TREE */

typedef enum { RED=0, BLACK} color_t; 

struct rb_node
{
    int data; 
    color_t color; 

    struct rb_node* left; 
    struct rb_node* right; 
    struct rb_node* parent; 
}; 

struct rb_tree
{
    struct rb_node* p_root_node; 
    struct rb_node* nil; 
    int nr_mem; 
}; 
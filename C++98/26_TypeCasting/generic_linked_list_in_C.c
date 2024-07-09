#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(Type, Mem)    ((unsigned long long int)(&((Type*)0)->Mem)) 
#define CONTAINER_OF(addr, Type, Mem)   ((Type*)((char*)addr - OFFSET_OF(Type, Mem)))

struct list_head 
{
    struct list_head* prev; 
    struct list_head* next; 
}; 

struct int_node
{
    int data; 
    struct list_head links; 
}; 

struct Date_node
{
    int day; 
    int month; 
    int year; 

    struct list_head links; 
}; 

void generic_insert(struct list_head* beg, struct list_head* mid, 
                    struct list_head* end)
{
    mid->next = end;
    mid->prev = beg; 
    beg->next = mid; 
    end->prev = mid; 
}

void insert_end(struct list_head* p_head_node, struct list_head* new_node)
{
    generic_insert(p_head_node->prev, new_node, p_head_node);
}

#define LIST_HEAD(v)    struct list_head v = {&v, &v}; 

int main(void)
{
    LIST_HEAD(int_LL_head); 
    LIST_HEAD(date_LL_head); 

    struct list_head* p_run; 
    struct int_node* p_int_node; 
    struct Date_node* p_date_node; 

    struct int_node I1 = {10, {NULL, NULL}}; 
    struct int_node I2 = {20, {NULL, NULL}}; 
    struct int_node I3 = {30, {NULL, NULL}}; 
    struct int_node I4 = {40, {NULL, NULL}}; 

    insert_end(&int_LL_head, &I1.links); 
    insert_end(&int_LL_head, &I2.links); 
    insert_end(&int_LL_head, &I3.links); 
    insert_end(&int_LL_head, &I4.links); 

    for(p_run = int_LL_head.next; p_run != &int_LL_head; p_run = p_run->next)
    {
        p_int_node = CONTAINER_OF(p_run, struct int_node, links); 
        printf("p_int_node->data = %d\n", p_int_node->data); 
    }

    struct Date_node DN1 = {1, 2, 1970, {NULL, NULL}}; 
    struct Date_node DN2 = {2, 3, 1971, {NULL, NULL}}; 
    struct Date_node DN3 = {3, 4, 1972, {NULL, NULL}}; 
    struct Date_node DN4 = {4, 5, 1973, {NULL, NULL}}; 

    insert_end(&date_LL_head, &DN1.links); 
    insert_end(&date_LL_head, &DN2.links); 
    insert_end(&date_LL_head, &DN3.links); 
    insert_end(&date_LL_head, &DN4.links); 

    for(p_run = date_LL_head.next; p_run != &date_LL_head; p_run = p_run->next)
    {
        p_date_node = CONTAINER_OF(p_run, struct Date_node, links); 
        printf("%d-%d-%d\n", p_date_node->day, p_date_node->month, p_date_node->year); 
    }

    return (0); 
} 
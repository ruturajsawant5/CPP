#include <iostream> 
#include <stdexcept> 

#include "list.hpp"

template <typename T> 
cpa::dsa::node<T>::node() : prev(0), next(0) 
{

}


template <typename T> 
cpa::dsa::node<T>::node(T _data) : data(_data), prev(0), next(0) 
{

}

template <typename T> 
cpa::dsa::list<T>::list() 
{
    p_head_node = new node<T>; 
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 
}

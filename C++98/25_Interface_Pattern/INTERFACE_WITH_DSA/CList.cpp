#include <iostream>
#include <cstdio> 
#include "IList.hpp"
#include "CList.hpp"

IList* IList::get_instance() 
{
    return new CList; 
}

CList::CList()
{
    
}

CList::~CList()
{

}

void CList::insert_start(int d)
{

}

void CList::insert_end(int d)
{

}

void CList::insert_after(int ed, int d)
{

}

void CList::insert_before(int ed, int d)
{

}

void CList::get_start(int* p)
{

}

void CList::get_end(int* p)
{

}

void CList::pop_start(int* p)
{

}

void CList::pop_end(int* p)
{

}

void CList::remove_start()
{

}

void CList::remove_end()
{

}

void CList::remove_data(int d)
{

}

void CList::show() const
{

}

std::size_t CList::len() const
{

}

bool CList::find(int d)
{

}

void CList::concat(IList* other, IList** pp_cat_list)
{

}

void CList::merge(IList* other, IList** pp_merged_list)
{

}

void CList::get_reversed(IList** pp_reversed_list)
{

}

void CList::reverse()
{

}

void generic_insert(list_node* beg, list_node* mid, list_node* end)
{

}

void generic_delete(list_node* p_delete_node)
{

} 

list_node* search_node(int s_data)
{

}
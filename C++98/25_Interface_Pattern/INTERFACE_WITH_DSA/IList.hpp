#pragma once 

#include <iostream>

class IList 
{
    public: 
        virtual void insert_start(int d) = 0; 
        virtual void insert_end(int d) = 0; 
        virtual void insert_after(int ed, int d) = 0; 
        virtual void insert_before(int ed, int d) = 0; 
        virtual void get_start(int* p) = 0; 
        virtual void get_end(int* p) = 0; 
        virtual void pop_start(int* p) = 0; 
        virtual void pop_end(int* p) = 0; 
        virtual void remove_start() = 0; 
        virtual void remove_end() = 0; 
        virtual void remove_data(int d) = 0; 
        virtual void show() const = 0; 
        virtual std::size_t len() const = 0; 
        virtual bool find(int d) = 0; 
        virtual void concat(IList* other, IList** pp_cat_list) = 0; 
        virtual void merge(IList* other, IList** pp_merged_list) = 0; 
        virtual void get_reversed(IList** pp_reversed_list) = 0;
        virtual void reverse() = 0; 
        virtual ~IList() {} 
        static IList* get_instance(); 
}; 

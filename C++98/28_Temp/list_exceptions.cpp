#include <stdexcept> 

class list_empty : public std::runtime_error{
    public: 
        list_empty(const char* msg) : std::runtime_error(msg){
        }
}; 

class list_data_not_found : public std::runtime_error{
    public: 
        list_data_not_found(const char* msg) : std::runtime_error(msg){
        }
}; 
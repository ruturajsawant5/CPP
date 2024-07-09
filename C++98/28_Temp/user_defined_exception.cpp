#include <iostream>
#include <stdexcept> 

class usage_error : public std::invalid_argument {
    public: 
        usage_error(const char* msg) : std::invalid_argument(msg){
        }
}; 

int main(int argc, char* argv[])
{
    try{ 
        if(argc != 2)
            throw usage_error("Invalid command line"); 
    }catch(usage_error& e){
        std::cout << e.what() << std::endl; 
        exit(EXIT_FAILURE); 
    }

    std::cout << "argv[1]:" << argv[1] << std::endl; 

    return 0; 
}
#include <iostream>
#include <stdexcept> 

#define MAX_ARGS 255

class usage_error : public std::invalid_argument {
    private: 
        const char* img_name; 
        bool is_fixed; 
        int nr_expected_arguments; 
        int nr_min_args; 
        int nr_max_args; 
    public: 
        usage_error(const char* exe_name, const char* msg, int _nr_expected_arguments, 
                    bool _is_fixed=true, int min_args=1, int max_args=MAX_ARGS) :    
                                                                std::invalid_argument(msg), 
                                                                img_name(exe_name), 
                                                                is_fixed(_is_fixed), 
                                                                nr_expected_arguments(_nr_expected_arguments),
                                                                nr_min_args(min_args), 
                                                                nr_max_args(max_args){
        }

        char* what()
        {
            std::cout << this->std::invalid_argument::what() << std::endl; 
            std::cout << "exe name:" << get_exe_name() << std::endl; 
            if(is_nr_cmd_args_fixed())
            {
                std::cout << "exe takes fixed number of arguments" << std::endl; 
                std::cout << "#arguments:" << get_nr_expected_arguments() << std::endl; 
            } 
            else 
            {
                std::cout << "Number of arguments are not rigidly fixed" << std::endl; 
                std::cout << "Min arguments:" << get_nr_min_args() << std::endl; 
                std::cout << "Max arguments:" << get_nr_max_args() << std::endl; 
            }

            return ""; 
        }

        bool is_nr_cmd_args_fixed() const{
            return is_fixed; 
        }

        int get_nr_expected_arguments() const {
            return nr_expected_arguments; 
        }

        int get_nr_min_args() const {
            return nr_min_args; 
        }

        int get_nr_max_args() const {
            return nr_max_args; 
        } 

        const char* get_exe_name() const{
            return img_name; 
        }
}; 

int main(int argc, char* argv[])
{
    try{ 
        if(argc != 2)
            throw usage_error(argv[0], "Invalid command line", 0, false, 3, MAX_ARGS); 
    }catch(usage_error& e){
        std::cout << e.what() << std::endl; 
        exit(EXIT_FAILURE); 
    }

    std::cout << "argv[1]:" << argv[1] << std::endl; 

    return 0; 
}


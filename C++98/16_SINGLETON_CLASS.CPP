#include <iostream> 
#include <stdexcept> 

class Singleton
{
    private: 
        static int counter; 
        // Private Data Members 
        Singleton(/* some initialisation data */) /* : initialiser list */ 
        {
            /* some assignment statements */
        } 

        ~Singleton()
        {
            if(counter == 1)
                counter = 0; 
            else 
                throw std::runtime_error("I sense disturbance in the force!"); 
        }

    public: 
        static Singleton* get_singleton_object(/* initialisation data*/); 
        static void release_singleton(Singleton* pSingleton); 
}; 

int Singleton::counter = 0; 

Singleton* Singleton::get_singleton_object(/* initialisation data*/)
{
    if(counter == 0)
    {
        counter = 1; 
        return new Singleton(/* initialisation data*/); 
    }
    else 
    {
        throw std::runtime_error("Second object of Singleton Class Cannot be created"); 
    }
}

void Singleton::release_singleton(Singleton* pSingleton)
{
    delete pSingleton; 
}

/* 
    Design pattern : Gang of four 
        Gamma, Ulrich, Helms, Vissidess 

    Heads First Design Pattern 
*/
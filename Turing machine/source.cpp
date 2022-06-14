#include <iostream>
#include "turing_machine.h"

int main()
{
    std::string input_file = "conf.txt";
    std::string input_line = "12331122211331";
    TuringMachine machine(input_file);
    try
    {
        machine.run_turing_machine(input_line);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    std::cout<<input_line<<std::endl;


    return (0);
}

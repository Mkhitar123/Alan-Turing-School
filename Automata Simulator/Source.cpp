#include "Automata.h"

int main(int argc, char * argv[]){

    try{

        // cheaking parametr 
        if( argc < 2){
            throw "Error : Pass configuration file name as parametr. \nUsage : Automata fileName \nUse - h to show configuration file template.";
        }
        else if(argc == 2 ){
            std:: string argv_1 = argv[1];
            if(argv_1== "-h" || argv_1 == "--help"){
                std :: cout<< "\nconfiguration file template.\n"<< std:: endl;
                std :: cout<< "a1, a2, a3, a4 \nb1, b2\nq0, q1\n"<< std:: endl;
                std :: cout<< "b1,q1 | b2,q2 | b1,q0 | b2,q1 |\nb1,q1 | b2,q2 | b1,q0 | b2,q1 |\n\na1, a2, a1, a3\n"<< std:: endl;
                throw "Please fill configuration file as givn in template.";
            }
            else{
                // opening configuration file.
                std :: string file_name = argv[1]; 
                std :: fstream conf_file;
                conf_file.open(file_name, std :: ios :: in);
                if(!conf_file){
                    std :: cerr << file_name << std:: endl;
                    throw "Error : Can not open file, no such file.";
                }
                // create and test Automata object.
                Automata a_o(conf_file);
                conf_file.close();
                a_o.print_out_config_table();
                a_o.complite_automata();
            }
        }
        else if(argc > 2){
            throw "Too meny arguments need only one.";
        }
    }
    catch(char const * err){
        std :: cerr << err << std :: endl;
        return 1;
    }
    return 0;
}
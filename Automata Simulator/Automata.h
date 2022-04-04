#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

// defining as new data type.
typedef std::pair<std::string, std::string> pair_str;

class Automata {

    public:
        Automata(std:: fstream & config);
        void complite_automata(); // function for complite automate 
        void print_out_config_table(); // function for printing out config table.
    private:

    std:: vector<std :: string> A; // input alphabet
    std:: vector<std :: string> B; // output alphabet
    std:: vector<std :: string> Q; // set of states
    std:: vector<std :: string> C; // Automate input line
    void parse_line(std:: string str, std ::vector<std::string> *set); // one line parsing function.
    pair_str str_to_pair(std :: string str);  // creating pair from string. 
    std :: map<pair_str, pair_str>  table; // config table. 
    std ::string  current_state; // holding current state of automata.
};

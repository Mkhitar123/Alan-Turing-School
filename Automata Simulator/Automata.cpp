#include "Automata.h"

Automata :: Automata(std:: fstream & config){

    // parsing input alphabet
    std :: string temp_str;
    std::getline(config, temp_str);
    if(temp_str.empty()){
        throw "Error : Input alphabet not exist in this configuration file.";
    }
    parse_line(temp_str, &A);
    temp_str.erase();

    // // parsing output alphabet
    std::getline(config, temp_str);
        if(temp_str.empty()){
        throw "Error : Output alphabet not exist in this configuration file.";
    }
    parse_line(temp_str, &B);
    temp_str.erase();

    // // parsing set of states
    std::getline(config, temp_str);
        if(temp_str.empty()){
        throw "Error : Set of states not exist in this configuration file.";
    }
    parse_line(temp_str, &Q);
    temp_str.erase();
    
    current_state = Q[0]; // init current stste.
    while (std::getline(config, temp_str) && !config.eof()){
        
        if(temp_str == ""){
            continue;
        }
        break;
    }

    if(temp_str.empty()){
        throw "Error : Configuration file is not contain automata tabel.";
    }

    std :: string v_bar = "|";
    std :: string temp_str_2 = "";
    unsigned int pos = 0;
    for(unsigned int i = 0; i < Q.size(); i++ ){

        for(unsigned int j = 0; j < A.size(); j++){

            pos = temp_str.find(v_bar);
            temp_str_2 = temp_str.substr(0,pos -1);
            pair_str temp_pair_1 = str_to_pair(temp_str_2);
            pair_str temp_pair_2 = std::make_pair(A[j],Q[i]);
            table.insert( std::make_pair(temp_pair_2 , temp_pair_1));
            temp_str.erase(0, pos + 1);
        }
        std::getline(config, temp_str);
        if(temp_str.empty()&& i <Q.size()-1){
            throw "Error : Configuration file is not complite.";
        }
    } 

    while (std::getline(config, temp_str) && !config.eof()){
        
        if(temp_str == ""){
            continue;
        }
        break;
    }

    if(temp_str.empty()){
        throw "Error : Configuration file is not contain Automata input line.";
    }
    parse_line(temp_str, &C);
    temp_str.erase();
    std:: cout << "----Automata is configured----"<< std:: endl;
}

void Automata :: parse_line(std:: string str, std ::vector<std::string> *set){
    
    std ::string text = str;
    std :: string  space = " ";
    unsigned int pos = text.find(space); 
    while (!text.empty()) {
        set->push_back(text.substr(0, pos-1));
        text.erase(0, pos + 1);
    }
}

pair_str Automata :: str_to_pair(std:: string str){

    std :: string s1;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());  
    unsigned int pos = 0;
    pos = str.find(',');
    s1= str.substr(0,pos);
    str.erase(0, pos+1);
    return std::make_pair(s1,str);
}

void Automata :: complite_automata(){

    std :: cout << "----Runnig automata----" << std :: endl; 
    std :: string temp; 
    while (!A.empty()){
        
        temp = A.front();
        for(auto it = table.cbegin(); it != table.cend(); ++it){
            if(it->first.first == temp && it->first.second == current_state){
                current_state = it->second.second;
                std :: cout << it->second.first << " "; 
            }
        }
        A.erase(A.begin());
    }
    std :: cout <<"\nDone..."<< std:: endl;
}

void Automata :: print_out_config_table(){

    for(auto it = table.cbegin(); it != table.cend(); ++it){
        std::cout << it->first.first << "," << it->first.second << " --> " << it->second.first<<","<< it->second.second << "\n";
    }
}
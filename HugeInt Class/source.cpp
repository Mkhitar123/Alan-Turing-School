#include "hugeint.h"


int main(int argc, char *argv[]){
    std::cout<<"________________TESTING INTEGER_______________________"<<std::endl;
    //int value constructor
    HugeInt a(123456789);
    HugeInt b(123456789);
    // multiplay a and b 
    HugeInt c = a*b;
    // sum a and b 
    HugeInt d = a+b;
    // print a*b and a+b
    c.print_hint();
    std::cout<<"-----------------------------------------------------"<<std::endl;
    d.print_hint();
    std::cout<<"________________TESTING STRING_______________________"<<std::endl;
    //string value constructor
    HugeInt e("33000000000000000000000000000000000000000000000000000");
    HugeInt f("36000000000000000000000000000000000000000100000002000");
    HugeInt g = e * f;
    g.print_hint();
    g = e+f;
    std::cout<<"-----------------------------------------------------"<<std::endl;
    g.print_hint();
    return 0;
}
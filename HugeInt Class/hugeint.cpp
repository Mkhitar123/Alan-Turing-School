#include "hugeint.h"

//constructor by integer value 
//each digit of number seperate and append to vector contenier.
HugeInt:: HugeInt(int value){
    unsigned short mod = 0;
    int dev = value;
    while (dev){
        mod = dev%10;
        huge_int.insert(huge_int.begin(), mod);
        dev /=10; 
    }
}

//constructor by string value 
//take each character of string from the back convert to unsigned short data type
// and append to vector contenier. 
HugeInt:: HugeInt(std::string value){
    while (!value.empty()){
        unsigned short a = value.back() - '0';
        huge_int.insert(huge_int.begin(),a);
        value.pop_back();
    }
}

// huge int print function 
void HugeInt:: print_hint(){

    for(int i =0; i< huge_int.size(); i++ ){
        std:: cout<< huge_int[i];
    }
    std::cout<<std::endl;
}

HugeInt HugeInt :: operator + (const HugeInt & arg) const {

    HugeInt res(0);
    res.huge_int = add_vector(huge_int, arg.huge_int);
    return res;
}

HugeInt HugeInt :: operator * (const HugeInt & arg) const {
    HugeInt res(0);
    unsigned int cerry = 0;
    uint_vector v1 = huge_int;
    uint_vector v2 = arg.huge_int;
    uint_vector v3;
    if(v2.size()<v1.size()){
        v3 = v1;
        v1 = v2;
        v2 = v3;
        v3.clear();
    }
    unsigned int tmp, mul, cnt = 0;
    while (v1.size()){

        for(int i = 0; i< cnt;++i){
            v3.insert(v3.begin(), 0);
        }
        mul= v1.back();
        tmp = 0;
        for(auto it = v2.end()-1; it >= v2.begin(); --it){

            tmp = mul*(*it) + cerry;
            if(tmp >=10){
                v3.insert(v3.begin(), tmp%10 );
                cerry=tmp/10;
            }
            else{
                v3.insert(v3.begin(), tmp);
                cerry = 0;
            }
        }
        if(cerry){
            v3.insert(v3.begin(), cerry);
            cerry = 0;
        }
        res.huge_int = add_vector(res.huge_int, v3);
        v1.pop_back();
        v3.clear();
        cnt++;
    }

    return res;
}

HugeInt HugeInt :: operator = (const HugeInt & arg) {

    huge_int = arg.huge_int;
    return *this;
}

// implementation of vector sum function.
uint_vector add_vector(const uint_vector & a, const uint_vector & b){

    unsigned int cerry = 0;
    uint_vector v1 = a;
    uint_vector v2 = b;
    uint_vector v3;
    unsigned int tmp ;
    while (v1.size() || v2.size()){

        tmp = 0;
        if(v1.size()&& v2.size()){

            tmp = v1.back()+v2.back() + cerry;
            if(tmp >=10){
                v3.insert(v3.begin(), tmp%10 );
                cerry=1;
            }
            else{
                v3.insert(v3.begin(), tmp);
                cerry=0;
            }
            v1.pop_back();
            v2.pop_back();
        }
        else{
            
            if(v1.size()){

                tmp = v1.back()+cerry;
                v3.insert(v3.begin(), tmp);
                v1.pop_back();
                cerry = 0;
            }
            else{
            
              tmp = v2.back()+cerry;
              v3.insert(v3.begin(), tmp);  
              v2.pop_back(); 
              cerry = 0;
            }
        }
    }
    if(cerry){
        v3.insert(v3.begin(), cerry);
    }
    return v3;
}
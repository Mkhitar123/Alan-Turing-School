#include <iostream>
#include <vector>
#include <string>

// define new data type 
typedef std::vector<unsigned short>  uint_vector;

//functions defination...

//sum two unsigned short vector
 uint_vector add_vector(const uint_vector & a, const uint_vector & b);

class HugeInt{
public:
     HugeInt(std::string value);
     HugeInt(int value);
     void print_hint(); // added print method for dis class
     HugeInt operator + (const HugeInt & arg) const;
     HugeInt operator * (const HugeInt & arg) const; 
     HugeInt operator = (const HugeInt & arg);  // added = operator 
private:
    uint_vector huge_int;
};

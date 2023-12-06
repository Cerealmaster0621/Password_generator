#include "engine.h"
#include <iostream>
#include <string>

int main(void){
    std::string password = "";
    std::string r_s="muchmuch";
    uint8_t length = 13;
    bool must_uppercase = false;
    bool must_symbol = true;    
    RandomEngine engine(length,must_uppercase,must_symbol,r_s);
    password+=engine.get_password();
    std::cout<<password<<std::endl;
}
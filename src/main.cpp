#include "engine.h"
#include <iostream>
#include <string>
#include <cmath>

uint64_t brute_force(uint8_t length,uint8_t modifier){
    return pow(modifier,(int)length)/pow(10,10);
}

int main(int argc, char* argv[]){
    std::string password = "";
    std::string required_string="";
    uint8_t length = 8;
    bool must_uppercase = false;
    bool must_symbol = false;
    uint64_t bf;
    bool err_flg = false;

    std::cout<<"------------------------ \n";
    std::cout<<"Password Generator \n";
    std::cout<<"To see the Possible CLI arguments : --h or --help \n";

    for(int i = 1; i< argc; ++i){
        std::string arg = argv[i];

        //--h or --help
        if(arg == "--h" || arg == "--help"){
            err_flg = true;
            std::cout<<"\nInformation: \n";
            std::cout<<"--h or --help : Display help information \n";
            std::cout<<"--l or --length : Specify password length, default - 8\n";
            std::cout<<"--u or --uppercase : Requires password generates with at least one uppercase, default - F\n";
            std::cout<<"--s or --symbol : Requires password generates with at least one symbol, default - F \n";
            std::cout<<"--i or --include : Requires password includes following string \n";
        }

        //--l or --length
        if(arg == "--l" || arg == "--length"){
            if (i+1<argc && !isdigit(atoi(argv[i+1]))){
                length = atoi(argv[i+1]);
            }
        }

        //--u or --uppercase
        if(arg == "--u" || arg == "--uppercase"){
            must_uppercase = true;
        }

        //--s or --symbol
        if(arg == "--s" || arg == "--symbol"){
            must_symbol = true;
        }

        //--i or --include
        if(arg == "--i" || arg == "--include"){
            if(i+1<argc){
                required_string = argv[++i];
                //required string > length error
                if(required_string.length()>length){
                    err_flg = true;
                    std::cerr<<"!! Required string must be shorter than the length !!\n";
                    return 1;
                }
                //required string = length and must_symbol and must_uppercase can't be fit in error
            }else{
                err_flg = true;
                std::cerr<<"!! --i or --include requires only one argument. !!\n";
                return 1;
            }            
        }
    }
    if(!err_flg){ //creates password
        RandomEngine engine(length, must_uppercase,must_symbol,required_string);
        password = engine.get_password();
        bf = brute_force(length,engine.get_modifier());
        std::cout<<"------------------\n";
        std::cout<<"Created Password : \n";
        std::cout<<password<<'\n';
        std::cout<<"------------------\n";
        std::cout<<"It takes about "<<bf/3600<<" hours to crack this password. \n";
    }
}
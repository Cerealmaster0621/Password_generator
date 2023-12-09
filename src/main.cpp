#include "engine.h"
#include "time.h"
#include <iostream>
#include <string>
#include <cmath>

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
            std::cout<<"--u or --uppercase : Requires the password to include at least one uppercase letter, default - F\n";
            std::cout<<"--s or --symbol : Requires the password to include at least one symbol, default - F \n";
            std::cout<<"--i or --include : Requires the password to include the following string \n";
            std::cout<<"Example: ./run.sh --l 12 --u --s --i aaa\n";
        }

        //--l or --length
        if(arg == "--l" || arg == "--length"){
            if (i+1<argc){
                //check if --l has integer not string
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
        TimeCalc time;
        password = engine.get_password();
        uint8_t modifier = engine.get_modifier();
        bf = time.get_crack_time(length,modifier,password);
        std::cout<<"------------------\n";
        std::cout<<"Created Password : \n";
        std::cout<<password<<'\n';
        std::cout<<"------------------\n";
        time.print_time(bf);
    }
}
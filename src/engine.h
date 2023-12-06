#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<memory>

class RandomEngine{
    private:
        std::string required_string="";
        uint8_t length = 12;
        bool must_uppercase = true;
        bool must_symbol = true;
        char seq[100]; //stores seed from dev/urandom
        uint8_t modifier = 72; //default - 72 changed depends on must_upp and must_sym
        std::unique_ptr<std::mt19937_64> generate;
        std::unique_ptr<std::uniform_int_distribution<uint64_t>> distributor;

    public:
        struct table {
            const std::vector<char> alpha_sym_lower_num = {//46            
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',                
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                '!', '@', '#', '$', '%', '^', '&', '*', '-', '_',
            };
            const std::vector<char> alpha_upper_sym_lower_num = {//72
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',                
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',                
                '!', '@', '#', '$', '%', '^', '&', '*', '-', '_',                                
            };
        };        
        //constructor
        void initialize_random_engine();
        RandomEngine(uint8_t l, bool m_u, bool m_s, std::string r_s);
        //member function
        void set_modifier();
        uint8_t get_length();
        void set_length(uint8_t l);
        bool get_must_uppercase();
        void set_must_uppercase(bool b);
        bool get_must_symbol();
        void set_must_symbol(bool b);
        std::string get_required_string();
        void set_required_string(std::string s);
        std::string get_password();
        char get_table_character(uint8_t index);//index - generated random number
};
#include "engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>
#include <cctype>

//CONSTRUCTORS IN engine.constructor.cpp

//MEMBER FUNCTIONS

/*
** RandomEngine::set_modifier():
** set desirable modifier depends on 
** user requires including uppercase or symbol
*/
void RandomEngine::set_modifier(){
    if(must_uppercase&&must_symbol){
        modifier = 72;
    }else if(!must_uppercase&&must_symbol){
        modifier = 46;
    }else if(must_uppercase&&!must_symbol){
        modifier = 62;
    }else{
        modifier = 36;
    }
}

uint8_t RandomEngine::get_length(){
    return length;
}

void RandomEngine::set_length(uint8_t l){
    length = l;
}

bool RandomEngine::get_must_uppercase(){
    return must_uppercase;
}

void RandomEngine::set_must_uppercase(bool b){
    must_uppercase = b;
    set_modifier();
}

bool RandomEngine::get_must_symbol(){
    return must_symbol;
}

void RandomEngine::set_must_symbol(bool b){
    must_symbol = b;
    set_modifier();
}

std::string RandomEngine::get_required_string(){
    return required_string;
}

void RandomEngine::set_required_string(std::string s){
    required_string = s;
}

/*
** RandomEngine::get_password(length,must_uppercase,must_symbol,required_string):
** OUTPUT => Randomly generated password
*/
std::string RandomEngine::get_password(){
    std::string password = "";
    std::string r_s = required_string;
    auto random = std::bind(*distributor, *generate);
    table tbl;
    while(password.length() != length){ //while generating loop is not finished
        while(!r_s.empty()){
            char first_char = r_s[0];
            password+=first_char;
            r_s.erase(0, 1);
        }
        if (password.length() != length){
            uint8_t idx = random();
            char new_char = get_table_character(idx);
            password+=new_char;
        }
    }
    return password;
}

/*
** RandomEngine::get_table_character(index from *distributor):
** OUTPUT => designated char from RandomEngine::table
*/
char RandomEngine::get_table_character(uint8_t index){
    table tbl;
    std::vector<char> arr = modifier==46?tbl.alpha_sym_lower_num:tbl.alpha_upper_sym_lower_num;
    char result = arr[index];
    return result;
}


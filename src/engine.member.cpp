#include "engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

//CONSTRUCTORS IN engine.constructor.cpp

//MEMBER FUNCTIONS

/*
** RandomEngine::set_modifier():
** set desirable modifier depends on 
** user requires included uppercase or symbol
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
    char c;
    std::string r_s = this->required_string;

    while(password.length() != this->length){ //while generating loop is not finished
        while(!r_s.empty()){
            char first_char = r_s[0];
            password+=first_char;
            r_s.erase(0, 1);
        }
        
    }
}

/*
** RandomEngine::get_table_character(index from *distributor):
** OUTPUT => designated char from RandomEngine::table
*/
char RandomEngine::get_table_character(uint64_t index){
    char result;
    table tbl;
    if (index<26){
        result = tbl.alpha_upper[index];
        return result;
    }else if(index<52){
        result = tbl.alpha_lower[index-26];
        return result;
    }else if(index<62){
        result = tbl.num[index-36];
        return result;
    }else{
        result = tbl.sym[index-46];
        return result;
    }
}


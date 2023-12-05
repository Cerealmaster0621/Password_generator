#include "engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//CONSTRUCTORS

RandomEngine::RandomEngine()
: length((uint8_t)8), must_uppercase(true),must_symbol(true),required_string((std::string)""){
    seq.resize(100);
    //get high quality seed from /dev/urandom
    //read binary mode since dev/urandom is written in binary
    std::ifstream file("/dev/urandom",std::ios::in|std::ios::binary);
    if (!file){
        throw std::system_error(errno, std::generic_category(), "failed to open /dev/urandom");
    }
    if (!file.read(seq.data(),seq.size())){
        throw std::system_error(errno, std::generic_category(), "failed to read /dev/urandom");
    }
    file.close();
    

}

RandomEngine::RandomEngine(uint8_t l, bool m_u, bool m_s, std::string r_s)
: length(l), must_uppercase(m_u), must_symbol(m_s), required_string(r_s) {
    generate = std::make_unique<std::mt19937_64>(std::random_device{}());
    distributor = std::make_unique<std::uniform_int_distribution<uint64_t>>(0,std::numeric_limits<uint64_t>::max());
}

//MEMBER FUNCTIONS

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

//create random password
std::string RandomEngine::get_password(uint8_t l, bool m_u, bool m_s, std::string r_s){
    
}
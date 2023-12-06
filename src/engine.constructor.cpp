#include "engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

/*
** RandomEngine::initialize_random_engine(): 
** basically every constructor share this function
** read /dev/urandom in binary and get 100 random numbers for seeds
** save it to seq vector and generate random index(0~modifier depends on what user requires)
*/
void RandomEngine::initialize_random_engine(){
    seq.resize(100);
    //get high quality seed from /dev/urandom
    //read binary mode since dev/urandom is written in binary
    std::ifstream file = std::ifstream("/dev/urandom",std::ios::in|std::ios::binary);
    if (!file){
        throw std::system_error(errno, std::generic_category(), "failed to open /dev/urandom");
    }
    if (!file.read(seq.data(),seq.size())){
        throw std::system_error(errno, std::generic_category(), "failed to read /dev/urandom");
    }
    file.close();
    //seq stored seeds
    std::seed_seq seedSeq(*seq.begin(),*seq.end());
    generate = std::make_unique<std::mt19937_64>(seedSeq);
    distributor = std::make_unique<std::uniform_int_distribution<uint64_t>>(0,modifier-1);
}

//MEMBER FUNCTIONS IN engine.member.cpp

//CONSTRUCTORS

RandomEngine::RandomEngine()
: length((uint8_t)8), must_uppercase(true),must_symbol(true),required_string((std::string)""){
    initialize_random_engine();
}

// Single Parameter Constructors
explicit RandomEngine::RandomEngine(uint8_t l)
: length(l), must_uppercase(true), must_symbol(true), required_string("") {
    initialize_random_engine();
}

explicit RandomEngine::RandomEngine(bool m_u)
: length(8), must_uppercase(m_u), must_symbol(true), required_string("") {
    initialize_random_engine();
}

explicit RandomEngine::RandomEngine(std::string r_s)
: length(8), must_uppercase(true), must_symbol(true), required_string(r_s) {
    initialize_random_engine();
}

// Two Parameter Constructors
RandomEngine::RandomEngine(uint8_t l, bool m_u)
: length(l), must_uppercase(m_u), must_symbol(true), required_string("") {
    initialize_random_engine();
}

RandomEngine::RandomEngine(uint8_t l, std::string r_s)
: length(l), must_uppercase(true), must_symbol(true), required_string(r_s) {
    initialize_random_engine();
}

RandomEngine::RandomEngine(bool m_u, bool m_s)
: length(8), must_uppercase(m_u), must_symbol(m_s), required_string("") {
    initialize_random_engine();
}

RandomEngine::RandomEngine(uint8_t l, bool m_s)
: length(l), must_uppercase(true), must_symbol(m_s), required_string("") {
    initialize_random_engine();
}

RandomEngine::RandomEngine(bool m_u, std::string r_s)
: length(8), must_uppercase(m_u), must_symbol(true), required_string(r_s) {
    initialize_random_engine();
}

RandomEngine::RandomEngine(bool m_s, std::string r_s)
: length(8), must_uppercase(true), must_symbol(m_s), required_string(r_s) {
    initialize_random_engine();
}

// Three Parameter Constructors
RandomEngine::RandomEngine(uint8_t l, bool m_u, bool m_s)
: length(l), must_uppercase(m_u), must_symbol(m_s), required_string("") {
    initialize_random_engine();
}

RandomEngine::RandomEngine(uint8_t l, bool m_u, std::string r_s)
: length(l), must_uppercase(m_u), must_symbol(true), required_string(r_s) {
    initialize_random_engine();
}

RandomEngine::RandomEngine(uint8_t l, bool m_s, std::string r_s)
: length(l), must_uppercase(true), must_symbol(m_s), required_string(r_s) {
    initialize_random_engine();
}

RandomEngine::RandomEngine(bool m_u, bool m_s, std::string r_s)
: length(8), must_uppercase(m_u), must_symbol(m_s), required_string(r_s) {
    initialize_random_engine();
}

// Four Parameter Constructor
RandomEngine::RandomEngine(uint8_t l, bool m_u, bool m_s, std::string r_s)
: length(l), must_uppercase(m_u), must_symbol(m_s), required_string(r_s) {
    initialize_random_engine();
}
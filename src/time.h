#pragma once
#include<iostream>

class TimeCalc{
    private:

    public:
    double get_weight(std::string required_password);
    uint64_t get_crack_time(uint8_t length,uint8_t modifier,std::string required_string);
    void print_time(uint64_t time);
};
#include "time.h"
#include <iostream>
#include <fstream>
#include <iomanip>


/*
** TimeCalc::get_crack_time(length of entire password, modifier, required_string)
** OUTPUT -> returns calculated time(seconds).
** Time taken = Modifier^(entire lengths) / 10^12 * weight*5
*/
uint64_t TimeCalc::get_crack_time(uint8_t length, uint8_t modifier, std::string required_string){
    double weight = required_string.length() > 0 ? get_weight(required_string) : 0.1;
    double log_numerator = length * log(modifier);
    double log_denominator = log(pow(10, 12)) + log(5 * weight);
    double result = exp(log_numerator - log_denominator);
    return static_cast<uint64_t>(result);
}

/*
** TimeCalc::get_weight(required string)
** OUTPUT -> max percentage of how much given string look alike to the password lists
** Weight = how many characters look alike in the password/length of the line
*/
double TimeCalc::get_weight(std::string required_password){
    std::string filepath = "password.txt";
    std::ifstream file(filepath);
    double max = -1, cnt = 0;
    if (!file) {
        throw std::system_error(errno, std::generic_category(), "failed to open " + filepath);
    }
    std::string line;
    while (std::getline(file, line)) {
        cnt = 0;
        for (size_t i = 0; i < line.length() && i < required_password.length(); i++) {
            if (line[i] == required_password[i]) {
                cnt++;
            }
        }
        double ratio = (cnt / line.length());
        if (ratio > max) {
            max = ratio;
        }
    }
    file.close();
    return max > 0 ? max : 0.2;
}

/*
** TimeCalc::print_time(calculated time(seconds))
** prints seconds to days/months/years/centuries
*/
void TimeCalc::print_time(uint64_t time){
    double seconds_per_minutes = 60, seconds_per_hours = 3600, seconds_per_day = 86400, seconds_per_month = 86400*30, seconds_per_year = 86400*30*12, seconds_per_century = 3155673600;
    if(time<seconds_per_minutes){
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time<<" seconds to crack this password. \n";        
    } else if(time<seconds_per_hours){
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_minutes<<" minutes to crack this password. \n";        
    } else if (time< seconds_per_day){
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_hours<<" hours to crack this password. \n";
    } else if (time < seconds_per_month) {
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_day<<" days to crack this password. \n";
    } else if (time < seconds_per_year) {
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_month<<" months to crack this password. \n";
    } else if (time < seconds_per_century) {
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_year<<" years to crack this password. \n";
    } else {
        std::cout<<std::fixed << std::setprecision(2)<<"It takes about "<<time/seconds_per_century<<" centuries to crack this password. \n";
    }    
}
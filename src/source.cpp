#include <cmath>
#include <stdexcept>
#include "number_utils.h"

/**
 * @brief Get the sqrt of a number
 * 
 * @param num
 * @return double the sqrt of the number
 * 
 * @throw std::invalid_argument if the num is negative 
 */
double get_sqrt(const double num){
    if(num < 0){
        throw std::invalid_argument("recieved negative number");
    }
    return sqrt(num);
}

/**
 * @brief 
 * Seeds and gets a random number
 * if odd it multiplies it by 2
 * 
 * if divisible by 3 it divides it by 3
 * 
 * if divisible by 4 it multiplies it by 4
 * 
 * if num after all this is greater than 4, throws an error
 * else returns that number
 * 
 * @param test_num used for testing
 * @return int the number after all these if statements are applied
 * 
 * @throws std::invalid_argument if after applying the operations the number is greater than 4
 */
int number_cases(int* test_num = nullptr){
    srand(time(0));
    int number_test = rand();

    if(test_num != nullptr){ // for testing purposes
        number_test = *test_num;
    }

    
    // odd will do nothing to number if even
    if(number_test & 1){
        number_test *= 2;
    }

    if(number_test % 3 == 0){
        number_test /= 3;
    }

    if(number_test % 4 == 0){
        number_test *= 4;
    }

    if(number_test > 4){
        throw std::invalid_argument("The number now is greater than 4");
    }

    return number_test;
}

/**
 * @brief Gets a divisibility list by the num from 1 to 10
 * 
 * @param num the number to check for divisibility by for [1, 10]
 * @return std::vector<int> a list that has the numbers that are divisible by num from 1 to 10 (set notation)  -> {xE[1, 10] | x mod(num) = 0}
 * 
 * @throw std::invalid_argument for if the num is 0 
 */
std::vector<int> is_divisible_list(const int num) {
    if (num == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }

    std::vector<int> div_by_num;
    for (int i = 1; i <= 10; i++) {
        if (i % num == 0) {
            div_by_num.push_back(i);
        }
    }
    return div_by_num;
}


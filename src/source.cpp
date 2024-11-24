#include <cmath>
#include <stdexcept>
#include "number_utils.h"

double get_sqrt(const double num){
    if(num < 0){
        throw std::invalid_argument("recieved negative number");
    }
    return sqrt(num);
}

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


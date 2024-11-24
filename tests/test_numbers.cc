#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include "number_utils.h"

// Test for get_sqrt function
TEST(NumberUtilsTest, GetSqrt) {
    // Test positive numbers
    EXPECT_NEAR(get_sqrt(100.0), 10.0, 0.01);
    EXPECT_NEAR(get_sqrt(25.0), 5.0, 0.01);

    // Test edge case: 0
    EXPECT_NEAR(get_sqrt(0.0), 0.0, 0.01);

    // Test negative numbers (should throw exception)
    EXPECT_THROW(get_sqrt(-1.0), std::invalid_argument);
    try {
        get_sqrt(-1.0);
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "recieved negative number");
    }
}

// Test for number_cases function
TEST(NumberUtilsTest, NumberCases) {
    // Test: odd number (1) gets doubled
    int test_num = 1;
    EXPECT_EQ(number_cases(&test_num), 2);  // Odd -> 2

    // Test: number divisible by 3
    test_num = 3;
    EXPECT_EQ(number_cases(&test_num), 2);  // Divisible by 3 -> 1

    // Test: even number (2) that does not trigger any exception
    test_num = 2;
    EXPECT_EQ(number_cases(&test_num), 2);  // No changes -> 2

    // Test: even number (4) triggers exception
    test_num = 4;
    EXPECT_THROW(number_cases(&test_num), std::invalid_argument);
}

// Test for is_divisible_list function
TEST(NumberUtilsTest, IsDivisibleList) {
    // Test dividble by 1
    std::vector<int> result = is_divisible_list(1);
    EXPECT_EQ(result, std::vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }));

    // Test divisible by 2
    result = is_divisible_list(2);
    EXPECT_EQ(result, std::vector<int>({2, 4, 6, 8, 10}));

    // Test divisible by 3
    result = is_divisible_list(3);
    EXPECT_EQ(result, std::vector<int>({3, 6, 9}));

    // Test divisible by 5
    result = is_divisible_list(5);
    EXPECT_EQ(result, std::vector<int>({5, 10}));



    // Test invalid input (0) - should handle gracefully
    EXPECT_THROW(is_divisible_list(0), std::invalid_argument);
    try {
        is_divisible_list(0);
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Division by zero is not allowed");
    }
}

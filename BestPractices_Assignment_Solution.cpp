#include <iostream>
#include <cassert>
#include <stdexcept>
#include <climits>


int calculateSum(int num_arr[], int start, int end,int num_arr_size) {
    //invalid argument handling
    if (start > end) {
        throw std::invalid_argument("start cannot be greater than end");
    }
    //out of range handling
    if(start < 0 || start > num_arr_size){
        std::cout<<"hi]n";
        throw std::out_of_range("start_idx is out of range index");
    }

    if(end < 0 || end > num_arr_size){
        throw std::out_of_range("start_idx is out of range index");
    }


    int sum = 0;
    for (int i = start; i < end; i++) {
        //overflow_handling
        if (num_arr[i] > 0 && sum > INT_MAX - num_arr[i]) {
            throw std::overflow_error("integer overflow occurred");
        } else if (num_arr[i] < 0 && sum < INT_MIN - num_arr[i]) {
            throw std::overflow_error("integer overflow occurred");
        }
        sum += num_arr[i];
    }
    return sum;
}

int main() {
    // Test Case 1: Basic case
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 1;
        int end = 4;
        int expectedSum = 2 + 3 + 4;
        int result = calculateSum(num_arr, start, end,5);
        assert(result == expectedSum);
        std::cout << "Test Case 1 Passed: Sum is correct." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 1 Failed: " << e.what() << std::endl;
    }

    // Test Case 2: Empty range
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 2;
        int end = 2;
        int expectedSum = 0; // No elements in the range
        int result = calculateSum(num_arr, start, end,5);
        assert(result == expectedSum);
        std::cout << "Test Case 2 Passed: Sum is correct." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 2 Failed: " << e.what() << std::endl;
    }

    // Test Case 3: Full range
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 0;
        int end = 5;
        int expectedSum = 1 + 2 + 3 + 4 + 5;
        int result = calculateSum(num_arr, start, end,5);
        assert(result == expectedSum);
        std::cout << "Test Case 3 Passed: Sum is correct." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 3 Failed: " << e.what() << std::endl;
    }

    // Test Case 4: Single element range
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 3;
        int end = 4;
        int expectedSum = 4;
        int result = calculateSum(num_arr, start, end,5);
        assert(result == expectedSum);
        std::cout << "Test Case 4 Passed: Sum is correct." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 4 Failed: " << e.what() << std::endl;
    }

    // Test Case 5: Negative numbers causing overflow
    try {
        int num_arr[] = {INT_MAX, INT_MAX, INT_MAX};
        int start = 0;
        int end = 3;
        calculateSum(num_arr, start, end,5);
        std::cout << "Test Case 5 Failed: No overflow exception thrown." << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Test Case 5 Passed: Overflow exception thrown." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 5 Failed: Unexpected exception thrown: " << e.what() << std::endl;
    }

    // Test Case 6: Invalid argument
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 3;
        int end = 2; // Invalid argument: start is greater than end
        calculateSum(num_arr, start, end,5);
        std::cout << "Test Case 6 Failed: No invalid_argument exception thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test Case 6 Passed: Invalid argument exception thrown." << std::endl;
    }

// Test Case 7: Index Out of Range
    try {
        int num_arr[] = {1, 2, 3, 4, 5};
        int start = 3;
        int end = 7;
        calculateSum(num_arr, start, end,5);
        std::cout << "Test Case 7 Failed: No out_of_range exception thrown." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Test Case 7 Passed: out_of_range exception thrown." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Case 7 Failed: Unexpected exception thrown: " << e.what() << std::endl;
    }

    std::cout << "All tests completed." << std::endl;
}

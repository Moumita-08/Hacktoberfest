//Question: You are given an array containing n distinct numbers taken from the range 0, 1, 2, ..., n. Since the array has n numbers out of the total n + 1 numbers, exactly one number is missing. Your task is to find the missing number.

#include <iostream>
#include <vector>

int find_missing_number(const std::vector<int>& arr) {
    int n = arr.size();
    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;

    for (int num : arr) {
        array_sum += num;
    }

    return total_sum - array_sum;
}

int main() {
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int missing_number = find_missing_number(arr);
    std::cout << "The missing number is: " << missing_number << std::endl;

    return 0;
}

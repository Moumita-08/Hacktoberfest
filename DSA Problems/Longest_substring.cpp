// Problem: Longest Substring Without Repeating Characters
//Ques: Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> char_map;
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < s.size(); ++right) {
        if (char_map.find(s[right]) != char_map.end()) {
            left = std::max(left, char_map[s[right]] + 1);
        }
        char_map[s[right]] = right;
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    int length = lengthOfLongestSubstring(s);
    std::cout << "Length of the longest substring without repeating characters: " << length << std::endl;

    return 0;
}


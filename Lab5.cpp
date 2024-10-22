#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool areAnagrams(const std::vector<char>& v1, const std::vector<char>& v2) {
    // If lengths are different, they cannot be anagrams
    if (v1.size() != v2.size()) {
        return false;
    }

    // Count characters
    std::unordered_map<char, int> charCount;
    for (char c : v1) {
        charCount[c]++;
    }

    for (char c : v2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false; // More of 'c' in v2 than in v1
        }
    }

    return true;
}

std::vector<char> getInputVector() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::vector<char> charVector;
    for (char c : input) {
        if (!isspace(c)) { // Ignore whitespace
            charVector.push_back(tolower(c)); // Convert to lowercase
        }
    }
    return charVector;
}

int main() {
    std::vector<char> v1 = getInputVector();
    std::vector<char> v2 = getInputVector();

    if (areAnagrams(v1, v2)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}

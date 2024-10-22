#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <algorithm>

bool areAnagrams(const std::list<char>& l1, const std::list<char>& l2) {
    // If lengths are different, they cannot be anagrams
    if (l1.size() != l2.size()) {
        return false;
    }

    // Count characters
    std::unordered_map<char, int> charCount;
    for (char c : l1) {
        charCount[c]++;
    }

    for (char c : l2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false; // More of 'c' in l2 than in l1
        }
    }

    return true;
}

void getInputList(std::list<char>& charList) {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    for (char c : input) {
        if (!isspace(c)) { // Ignore whitespace
            charList.push_back(tolower(c)); // Convert to lowercase
        }
    }
}

int main() {
    std::list<char>* l1 = new std::list<char>();
    getInputList(*l1);
    std::list<char>* l2 = new std::list<char>();
    getInputList(*l2);

    if (areAnagrams(*l1, *l2)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}

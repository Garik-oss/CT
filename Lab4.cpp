#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& input) {
    std::stack<char> brackets;

    for (char ch : input) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        }
        // Check for closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If the stack is empty, there is no matching opening bracket
            if (brackets.empty()) {
                return false;
            }
            // Check if the closing bracket matches the opening bracket
            char top = brackets.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                brackets.pop();
            } else {
                return false;
            }
        }
    }
    
    // If the stack is empty, all brackets were matched correctly
    return brackets.empty();
}

int main() {
    std::string input;
    std::cout << "Enter brackets: ";
    std::cin >> input;

    if (isValid(input)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

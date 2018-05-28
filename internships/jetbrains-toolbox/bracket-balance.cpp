#include <iostream>
#include <stack>
#include <string>

bool isClosingBracket(const char bracket) {
    return bracket == ')' || bracket == ']' || bracket == '}';
}

char GetOpeningBracket(const char closingBracket) {
    switch(closingBracket) {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    }
}

int main() {
    std::string sequence;
    std::cin >> sequence;

    std::stack<char> stack;

    for(std::size_t position = 0; position < sequence.size(); ++position) {
        const char bracket = sequence[position];
        if (!isClosingBracket(bracket)) {
            stack.push(bracket);
        } else if (!stack.empty() && stack.top() == GetOpeningBracket(bracket))  {
            stack.pop();
        } else {
            std::cout << position + 1 << std::endl;
            return 0;
        }
    }

    if (!stack.empty()) {
        std::cout << sequence.size() + 1;
    } else {
        std::cout << 0;
    }

    std::cout << std::endl;

    return 0;
}

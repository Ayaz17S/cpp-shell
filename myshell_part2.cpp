#include <iostream>  // For std::cout and std::cin
#include <string>    // For std::string
#include <vector>    // For std::vector
#include <sstream>   // For std::stringstream to parse the line

// This function splits a string by spaces into a vector of tokens
std::vector<std::string> parse_line(const std::string& line) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string input_line;

    while (true) {
        std::cout << "myshell> ";
        if (!std::getline(std::cin, input_line)) {
            std::cout << std::endl;
            break;
        }

        std::vector<std::string> args = parse_line(input_line);

        if (args.empty()) { // Handle empty lines
            continue;
        }

        if (args[0] == "exit") {
            break;
        }

        std::cout << "Tokens parsed: ";
        for (const auto& arg : args) {
            std::cout << "[" << arg << "] ";
        }
        std::cout << std::endl;
    }
    return 0;
}
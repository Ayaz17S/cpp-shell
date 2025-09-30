//
// Created by ayaz1 on 30-09-2025.
//
#include <iostream>
#include <string>

int main() {

    std::string input_line;

    while (true) {
        // 1. Print the prompt
        std::cout << "myshell> ";
if(!std::getline(std::cin, input_line)){
std::cout << std::endl;
break;
}

        // 3. A built-in command to exit the shell
        if (input_line == "exit") {
            break;
        }
std::cout << input_line << std::endl;
}
return 0;
}
//
// Created by ayaz1 on 01-10-2025.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>     // For fork(), execvp()
#include <sys/wait.h>   // For waitpid()

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

        if (args.empty()) {
            continue;
        }

        if (args[0] == "exit") {
            break;
        }

        std::vector<char*> c_args;
        for (auto& arg : args) {
            c_args.push_back(&arg[0]);
        }
        c_args.push_back(nullptr);

        pid_t pid = fork();
        if (pid == 0) {
            execvp(c_args[0], c_args.data());

            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            int status;
            waitpid(pid,&status,0);
        } else {
            perror("fork");
        }
    }
    return 0;
}
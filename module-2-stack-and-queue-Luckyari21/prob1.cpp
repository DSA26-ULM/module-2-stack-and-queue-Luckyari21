// Soal 2: Si Palui dan Mesin Hitung Aneh
// Kompilasi: g++ soal2.cpp stack.cpp -o soal2
// Algoritma: Evaluasi ekspresi postfix (Reverse Polish Notation) menggunakan stack.

#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    Stack s;
    init(&s);

    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);

            int result = 0;
            if      (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else                   result = a / b;

            push(&s, result);
        } else {
            push(&s, std::stoi(token));
        }
    }

    std::cout << peek(&s) << std::endl;
    return 0;
}
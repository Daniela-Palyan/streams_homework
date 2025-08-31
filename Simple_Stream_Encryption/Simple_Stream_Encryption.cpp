#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream input("text.txt");
    if (!input.is_open()) {
        throw std::runtime_error("Can't open input file");
    }

    std::ofstream output("enxripted_text.txt");
    if (!output.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    char c;
    while ((c = input.get()) != EOF) {
        if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
            if (c == 'z' || c == 'Z') {
                output << (c == 'z' ? 'a' : 'A');
            }
            else {
                output << ++c;
            }
        }

        else output << c;
    }

    input.close();
    output.close();

    std::cout << "Encription is finished" << std::endl;

    return 0;
}
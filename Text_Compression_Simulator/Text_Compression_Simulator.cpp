#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::ifstream input("text.txt");
    if (!input.is_open()) {
        throw std::runtime_error("Can't open input file");
    }

    std::ofstream output("compressed_text.txt");
    if (!output.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    std::string word;
    std::vector<std::string> words;

    while (getline(input, word, ' ')) {
        bool been = false;
        for (int i = 0; i < words.size(); ++i) {
            if (word == words[i]) {
                been = true;
                break;
            }
        }

        if (been) {
            output << "* ";
        }
        else {
            output << word << " ";
            words.push_back(word);
        }
    }

    input.close();
    output.close();

    std::cout << "Compressiopn is finished" << std::endl;

    return 0;
}
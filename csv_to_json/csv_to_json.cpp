#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::ifstream input("data.csv");
    if (!input.is_open()) {
        throw std::runtime_error("Can't open input file");
    }

    std::ofstream output("data.json");
    if (!output.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    std::string header;
    std::vector<std::string> headers;
    if (std::getline(input, header)) {
        std::stringstream ss(header);
        while (std::getline (ss, header, ',')) {
            headers.push_back(header);
        }
    }
    output << "[\n";

    std::string line;
    bool comma = false;
    while (std::getline(input, line)) {
        if (comma) {
            output << ", ";
        }
        comma = true;
        output << "{";
        std::vector<std::string> fields;
        std::stringstream ss(line);
        std::string field;
        for (size_t i = 0; i < headers.size(); ++i) {
            std::getline(ss, field, ',');
            output << "\"" << headers[i] << "\": ";
            
            if (std::all_of(field.begin(), field.end(), ::isdigit)) {
                output << field;
            }

            else {
                output << "\"" << field << "\"";
            }
            if (i != headers.size() - 1) {
                output << ", ";
            }
        }
        output << "}\n";
    }
    output << "]\n";

    input.close();
    output.close();

    std::cout << "Conversion is complated" << std:: endl;

    return 0;
}
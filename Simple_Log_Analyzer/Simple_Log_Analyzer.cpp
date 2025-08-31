#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream input("system_log.txt");
    if (!input.is_open()) {
        throw std::runtime_error("Can't open input file");
    }

    std::ofstream output_count("system_log_counts.txt");
    if (!output_count.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    std::ofstream output_err("system_errors.txt");
    if (!output_err.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    std::string line;
    int err = 0, warn = 0, info = 0;
    while (getline(input, line)) {
        std::stringstream ss(line);

        std::string state;
        if (getline(ss, state, ']')) {
            if (state == "[ERROR") {
                ++err;
                output_err << line << "\n";
            }

            else if (state == "[INFO") ++info;
            else ++warn;
        }
    }

    output_count << "INFO: " << info << "\n";
    output_count << "ERROR: " << err << "\n";
    output_count << "WARNING: " << warn << "\n";

    input.close();
    output_count.close();
    output_err.close();

    std::cout << "Files are generated" << std::endl;

    return 0;
}
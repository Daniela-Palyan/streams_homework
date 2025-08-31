#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::ifstream input("grades_input.txt");
    if (!input.is_open()) {
        throw std::runtime_error("Can't open input file");
    }

    std::ofstream output("grades_output.txt");
    if (!output.is_open()) {
        throw std::runtime_error("Can't open output file");
    }

    std::vector<std::pair<std::string, double>> students;

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);

        std::string name;
        std::string num;
        double final_grade = 0.0;


        std::getline(ss, name, ',');


        if (std::getline(ss, num, ',')) final_grade += 0.3 * std::stod(num);
        if (std::getline(ss, num, ',')) final_grade += 0.3 * std::stod(num);
        if (std::getline(ss, num, ',')) final_grade += 0.4 * std::stod(num);

        students.emplace_back(name, final_grade);
    }


    std::sort(students.begin(), students.end(),
              [](auto &a, auto &b) { return a.second > b.second; });


    for (auto &s : students) {
        output << s.first << ": " << s.second << "\n";
    }

    std::cout << "File written successfully.\n";

    return 0;
}

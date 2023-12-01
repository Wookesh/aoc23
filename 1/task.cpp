#include <iostream>
#include <string>

void part_one(const std::string &input) {
    auto first = 0;
    auto last = 0;
    auto cal = 0;
    for (const auto &c : input) {
        if (c == '\n') {
            cal += 10 * first + last;
            first = 0;
            last = 0;
        }
        if (c >= '0' && c <= '9') {
            if (first == 0) {
                first = c - '0';
            }
            last = c - '0';
        }
    }
    std::cout << "Part one: " << cal + first * 10  + last << std::endl;
}

void part_two(const std::string &input) {
    std::cout << "Part two: " << 0 << std::endl;
}
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>


int part_one(const std::string &input) {
    int result = 0;
    int round_val = 0;
    std::unordered_set<int> winning;

    int buf = 0;

    auto winning_section = false;
    for (const auto &c : input) {
        if (c >= '0' && c <= '9') {
            buf = buf * 10 + (c - '0');
        } else if (c == '|') {
            winning_section = false;
        } else if (c == '\n') {
            if (winning.contains(buf)) {
                if (round_val == 0) {
                    round_val = 1;
                } else {
                    round_val *= 2;
                }
            }
            result += round_val;
            round_val = 0;
            winning.clear();
            buf = 0;
        } else if (c == ' ') {
            if (winning_section && buf > 0) {
                winning.insert(buf);
            } else {
                if (winning.contains(buf)) {
                    if (round_val == 0) {
                        round_val = 1;
                    } else {
                        round_val *= 2;
                    }
                }
            }
            buf = 0;
        } else if (c == ':') {
            buf = 0;
            round_val = 0;
            winning_section = true;
            winning.clear();
        }
    }
    return result;
}

int part_two(const std::string &input) {
    int result = 0;
    int round_val = 0;
    std::unordered_set<int> winning;
    std::unordered_map<int, int> mult;

    int buf = 0;
    int card_id = 0;

    auto winning_section = false;
    for (const auto &c : input) {
        if (c >= '0' && c <= '9') {
            buf = buf * 10 + (c - '0');
        } else if (c == '|') {
            winning_section = false;
        } else if (c == '\n') {
            if (winning.contains(buf)) {
                ++round_val;
            }
            for (int i = 1; i <= round_val; i++) {
                mult[card_id + i] += mult[card_id] + 1;
            }
            result += mult[card_id] + 1;
            round_val = 0;
            winning.clear();
            buf = 0;
        } else if (c == ' ') {
            if (winning_section && buf > 0) {
                winning.insert(buf);
            } else {
                if (winning.contains(buf)) {
                    ++round_val;
                }
            }
            buf = 0;
        } else if (c == ':') {
            card_id = buf;
            buf = 0;
            round_val = 0;
            winning_section = true;
            winning.clear();
        }
    }
    return result;
}
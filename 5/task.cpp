#include <string>
#include <vector>
#include <iostream>

void skip_to(const std::string &input, int &i, char end);
std::vector<long long> load_line_numbers(const std::string &input, int &i);
std::vector<long long> load_ratio(const std::string &input, int &i);

long calculate_location(const long long &seed, const std::vector<std::vector<long long>> &ratios);

int part_one(const std::string &input) {
    int i = 0;
    skip_to(input, i, ':');
    const auto seeds = load_line_numbers(input, i);
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    std::vector<std::vector<long long>> ratios;
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));
    skip_to(input, i, ':');
    skip_to(input, i, '\n');
    ratios.push_back(load_ratio(input, i));

    long long lowest = 0;
    for (const auto &seed: seeds) {
        const auto loc = calculate_location(seed, ratios);
        if (loc < lowest || lowest == 0) {
            lowest = loc;
        }
    }

    return lowest;
}

void skip_to(const std::string &input, int &i, const char end) {
    for (const auto len = input.length(); i < len; ++i) {
        const auto &c = input[i];
        if (c == end) {
            ++i;
            return;
        }
    }
}

std::vector<long long> load_line_numbers(const std::string &input, int &i) {
    std::vector<long long> result;
    long long buf = 0;
    int buf_size = 0;
    for (const auto len = input.length(); i < len; ++i) {
        const auto &c = input[i];
        if (c == '\n') {
            if (buf_size > 0) {
                result.push_back(buf);
            }
            ++i;
            return result;
        }
        if (c >= '0' && c <= '9') {
            buf = buf * 10 + (c - '0');
            buf_size += 1;
        } else if (buf_size > 0) {
            result.push_back(buf);
            buf_size = 0;
            buf = 0;
        }
    }
    return result;
}

std::vector<long long> load_ratio(const std::string &input, int &i) {
    std::vector<long long> result;
    for (const auto len = input.length(); i < len;) {
        auto line = load_line_numbers(input, i);
        result.push_back(line[0]);
        result.push_back(line[1]);
        result.push_back(line[2]);
        const auto &c = input[i];
        if (c == '\n' && input[i - 1] == '\n') {
            return result;
        }
    }
    return result;
}

long calculate_location(const long long &seed, const std::vector<std::vector<long long>> &ratios) {
    long val = seed;
    for (const auto &ratio: ratios) {
        bool found = false;
        for (int i = 0; i < ratio.size() && !found; i += 3) {
            if (val >= ratio[i+1] && val <= ratio[i+1] + ratio[i+2]) {
                val = ratio[i] - ratio[i+1] + val;
                found = true;
            }
        }
    }
    return val;
}

int part_two(const std::string &input) {
    return 0;
}

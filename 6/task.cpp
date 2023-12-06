#include <cmath>
#include <string>
#include <vector>
#include <iostream>

void skip_to(const std::string &input, int &i, char end) {
    for (const auto len = input.length(); i < len; ++i) {
        const auto &c = input[i];
        if (c == end) {
            ++i;
            return;
        }
    }
}

std::vector<int> load_line_numbers(const std::string &input, int &i) {
    std::vector<int> result;
    int buf = 0;
    int buf_size = 0;
    for (; i < input.length(); ++i) {
        const auto &c = input[i];
        if (c >= '0' && c <= '9') {
            buf = buf * 10 + (c - '0');
            ++buf_size;
        } else if (c == '\n') {
            if (buf_size > 0) {
                result.push_back(buf);
                buf = 0;
                buf_size = 0;
            }
            ++i;
            return result;
        } else {
            if (buf_size > 0) {
                result.push_back(buf);
                buf = 0;
                buf_size = 0;
            }
        }
    }
    return result;
}

std::vector<long long> load_line_numbers_2(const std::string &input, int &i) {
    std::vector<long long> result;
    long long buf = 0;
    for (; i < input.length(); ++i) {
        const auto &c = input[i];
        if (c >= '0' && c <= '9') {
            buf = buf * 10 + (c - '0');
        } else if (c == '\n') {
            result.push_back(buf);
            ++i;
            return result;
        }
    }
    return result;
}


int part_one(const std::string &input) {
    int i = 0;
    skip_to(input, i, ':');
    const auto times = load_line_numbers(input, i);
    skip_to(input, i, ':');
    const auto distances = load_line_numbers(input, i);

    int result = 1;
    for (int j = 0; j < times.size(); ++j) {
        const auto t = times[j];
        const auto d = distances[j];
        // a * x^2 + b * x + c = 0
        // delta = b^2 - 4 * a * c
        // a = -1
        // b = t
        // c = -d
        // -x^2 + t * x - d = 0
        // delta = t^2 - 4 * d
        // x1 = (t + sqrt(delta)) / 2
        // x2 = (t - sqrt(delta)) / 2

        const int delta = t * t - 4 * d;
        if (delta == 0) {
            result += 1;
        } else if (delta > 0) {
            const int x1 = std::ceil(((t + std::sqrt(delta)) / 2) - 1);
            const int x2 = std::floor(((t - std::sqrt(delta)) / 2) + 1);
            const int options = x1 - x2 + 1;
            result *= options;
        }
    }

    return result;
}

int part_two(const std::string &input) {
    int i = 0;
    skip_to(input, i, ':');
    const auto times = load_line_numbers_2(input, i);
    skip_to(input, i, ':');
    const auto distances = load_line_numbers_2(input, i);

    long long result = 1;
    for (int j = 0; j < times.size(); ++j) {
        const auto t = times[j];
        const auto d = distances[j];
        // a * x^2 + b * x + c = 0
        // delta = b^2 - 4 * a * c
        // a = -1
        // b = t
        // c = -d
        // -x^2 + t * x - d = 0
        // delta = t^2 - 4 * d
        // x1 = (t + sqrt(delta)) / 2
        // x2 = (t - sqrt(delta)) / 2

        const long long delta = t * t - 4 * d;
        if (delta == 0) {
            result += 1;
        } else if (delta > 0) {
            const long long x1 = std::ceil(((t + std::sqrt(delta)) / 2) - 1);
            const long long x2 = std::floor(((t - std::sqrt(delta)) / 2) + 1);
            const long long options = x1 - x2 + 1;
            result *= options;
        }
    }
    return result;
}

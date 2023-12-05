#include <iostream>
#include <string>
#include <unordered_map>

int part_one(const std::string &input) {
    int part_num_sum = 0;
    int part_num_buf = 0;
    int part_num_size = 0;
    const uint len = input.length();
    const int width = input.find_first_of('\n') + 1;
    const int height = len / width;
    std::unordered_map<int, bool> m;

    for (auto i = 0; i < len; i++) {
        const auto c = input[i];
        if ((c < '0' || c > '9') && c != '\n' && c != '.') {
            const auto x = i % width;
            const auto y = i / width;
            if (y > 0) {
                if (x < width - 1) {
                    m[i + 1 - width] = true;
                }
                m[i - width] = true;
                if (x > 0) {
                    m[i - 1 - width] = true;
                }
            }
            if (x < width - 1) {
                m[i + 1] = true;
            }
            if (x > 0) {
                m[i - 1] = true;
            }
            if (y < height) {
                if (x < width - 1) {
                    m[i + 1 + width] = true;
                }
                m[i + width] = true;
                if (x > 0) {
                    m[i - 1 + width] = true;
                }
            }
        }
    }

    for (int i = 0; i < input.length(); ++i) {
        const auto c = input[i];
        if (c >= '0' && c <= '9') {
            part_num_buf = part_num_buf * 10 + (c - '0');
            part_num_size++;
        } else {
            if (part_num_buf > 0) {
                auto added = false;
                for (auto k = 0; !added && k < part_num_size; ++k) {
                    if (m[i - 1 - k]) {
                        part_num_sum += part_num_buf;
                        added = true;
                    }
                }
            }
            part_num_buf = 0;
            part_num_size = 0;
        }
    }
    return part_num_sum;
}

int part_two(const std::string &input) {
    int part_num_buf = 0;
    int part_num_size = 0;
    const uint len = input.length();
    const int width = input.find_first_of('\n') + 1;
    const int height = len / width;
    std::unordered_map<int, int> m;

    for (auto i = 0; i < len; i++) {
        const auto c = input[i];
        if (c == '*') {
            const auto x = i % width;
            const auto y = i / width;
            if (y > 0) {
                if (x < width - 1) {
                    m[i + 1 - width] = i;
                }
                m[i - width] = i;
                if (x > 0) {
                    m[i - 1 - width] = i;
                }
            }
            if (x < width - 1) {
                m[i + 1] = i;
            }
            if (x > 0) {
                m[i - 1] = i;
            }
            if (y < height) {
                if (x < width - 1) {
                    m[i + 1 + width] = i;
                }
                m[i + width] = i;
                if (x > 0) {
                    m[i - 1 + width] = i;
                }
            }
        }
    }
    std::unordered_multimap<int, int> m2;
    for (int i = 0; i < input.length(); ++i) {
        const auto c = input[i];
        if (c >= '0' && c <= '9') {
            part_num_buf = part_num_buf * 10 + (c - '0');
            part_num_size++;
        } else {
            if (part_num_buf > 0) {
                auto added = false;
                for (auto k = 0; !added && k < part_num_size; ++k) {
                    const auto pos = m.find(i - 1 - k);
                    if (pos != m.end()) {
                        m2.insert(std::pair<int, int>(pos->second, part_num_buf));
                        added = true;
                    }
                }
            }
            part_num_buf = 0;
            part_num_size = 0;
        }
    }

    int c = 0;
    int mult = 1;
    int sum = 0;
    int prev_i = 0;
    for (const auto &p : m2) {
        if (prev_i != p.first) {
            if (c == 2) {
                sum += mult;
            }
            mult = 1;
            c = 0;
        }
        c += 1;
        mult *= p.second;
        prev_i = p.first;
    }
    if (c == 2) {
        sum += mult;
    }

    return sum;
}
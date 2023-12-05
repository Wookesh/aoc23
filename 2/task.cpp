#include <iostream>
#include <string>

int part_one(const std::string &input) {
    int r = 0;
    int g = 0;
    int b = 0;
    int id = 0;
    int id_sum = 0;

    int v_buf = 0;
    std::string buf;
    for (const auto &c : input) {
        if (c == '\n') {
            if (r <= 12 && g <= 13 && b <= 14) {
                id_sum += id;
            }
            r = 0;
            g = 0;
            b = 0;
            id = 0;
            v_buf = 0;
            buf = "";
        }
        if (c >= '0' && c <= '9') {
            v_buf = v_buf * 10 + (c - '0');
        } else if ( c >= 'a' && c <= 'z') {
            buf += c;
        } else if (c == ':') {
            id = v_buf;
            v_buf = 0;
            buf = "";
        } else if (c == ',' || c == ';') {
            if (buf == "red" && r < v_buf) {
                r = v_buf;
            } else if (buf == "green" && g < v_buf) {
                g = v_buf;
            } else if (buf == "blue" && b < v_buf) {
                b = v_buf;
            }
            v_buf = 0;
            buf = "";
        }
    }
    return id_sum;
}

int part_two(const std::string &input) {
    int r = 0;
    int g = 0;
    int b = 0;
    int result = 0;

    int v_buf = 0;
    std::string buf;
    for (const auto &c : input) {
        if (c == '\n') {
            if (buf == "red" && r < v_buf) {
                r = v_buf;
            } else if (buf == "green" && g < v_buf) {
                g = v_buf;
            } else if (buf == "blue" && b < v_buf) {
                b = v_buf;
            }
            result += r * g * b;
            r = 0;
            g = 0;
            b = 0;
            v_buf = 0;
            buf = "";
        }
        if (c >= '0' && c <= '9') {
            v_buf = v_buf * 10 + (c - '0');
        } else if ( c >= 'a' && c <= 'z') {
            buf += c;
        } else if (c == ':') {
            v_buf = 0;
            buf = "";
        } else if (c == ',' || c == ';') {
            if (buf == "red" && r < v_buf) {
                r = v_buf;
            } else if (buf == "green" && g < v_buf) {
                g = v_buf;
            } else if (buf == "blue" && b < v_buf) {
                b = v_buf;
            }
            v_buf = 0;
            buf = "";
        }
    }
    return result;
}
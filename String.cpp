//
// Created by remy on 4/8/22.
//

#include "String.h"
#include <cstring>
#include <stdexcept>

#define INITIAL_CAPACITY 10
#define GROWTH_RATE 2

String::String() : m_size {0}, m_capacity {INITIAL_CAPACITY}, m_data { new char[this->m_capacity + 1] } {
    this->m_data[this->m_size] = '\0';
}

String::String(const char *str) : m_size {strlen(str)}, m_capacity {this->m_size}, m_data {new char[this->m_capacity + 1]} {
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = str[i];
    }
    this->m_data[this->m_size] = '\0';
}

String::String(const String &str) : m_size {str.m_size}, m_capacity {str.m_capacity}, m_data {new char[this->m_capacity + 1]}{
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = str.m_data[i];
    }
    this->m_data[this->m_size] = '\0';
}

String::String(const std::string &str)  : m_size {str.length()}, m_capacity {str.length()}, m_data {new char[this->m_capacity + 1]}{
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] = str[i];
    }
    this->m_data[this->m_size] = '\0';
}

String::~String() {
    delete[] this->m_data;
}

String &String::operator=(const String& other) noexcept {
    if (this->m_capacity != other.m_capacity) {
        this->m_capacity = other.m_capacity;
        char* new_data = new char[this->m_capacity + 1];
        delete[] this->m_data;
        this->m_data = new_data;

    }
    this->m_size = other.m_size;
    for (int i = 0; i  < this->m_size; i++) {
        this->m_data[i] = other.m_data[i];
    }
    this->m_data[this->m_size] = '\0';

    return *this;
}

void String::swap(String& str) {
    String temp = String {str};

    str = *this;
    *this = temp;
}

int String::length() const {
    return this->m_size;
}

bool String::empty() const {
    return this->m_size == 0;
}

const char *String::c_str() const {
    return this->m_data;
}

char &String::at(int index) {
    if (index > 0 && index < this->m_size) {
        return this->m_data[index];
    } else {
        throw std::out_of_range("");
    }
}

char &String::get(int index) {
    return this->m_data[index];
}

char &String::front() {
    return this->m_data[0];
}

char &String::back() {
    return this->m_data[this->m_size - 1];
}

void String::append(String &str) {
    this->reserve(this->m_size + str.length());

    std::size_t new_size = this->m_size + str.length();
    for (; m_size < new_size; m_size++) {
        this->m_data[this->m_size] = str.m_data[m_size - (new_size - str.length())];
    }
    this->m_data[this->m_size] = '\0';
}

void String::append(std::string &str) {
    this->reserve(this->m_size + str.length());

    std::size_t new_size = this->m_size + str.length();
    for (; m_size < new_size; m_size++) {
        this->m_data[this->m_size] = str[m_size - (new_size - str.length())];
    }
    this->m_data[this->m_size] = '\0';
}

void String::append(const char *str) {
    this->reserve(this->m_size + std::strlen(str));

    std::size_t new_size = this->m_size + std::strlen(str);
    for (; m_size < new_size; m_size++) {
        this->m_data[this->m_size] = str[m_size - (new_size - std::strlen(str))];
    }
    this->m_data[this->m_size] = '\0';
}

void String::append(char str) {
    this->reserve(this->m_size + 1);
    this->m_data[this->m_size++] = str;
    this->m_data[this->m_size] = '\0';
}

String String::substr(int start, int length) const {
    String str {};
    str.reserve(length);

    for (int i = start; i < start + length; i++) {
        str.m_data[str.m_size++] = this->m_data[i];
    }
    str.m_data[str.m_size] = '\0';

    return str;
}

String String::substr(int start) const {
    return this->substr(start, this->length() - start);
}

bool String::starts_with(const String &prefix) const {
    for (int i = 0; i < prefix.length(); i++) {
        if (this->m_data[i] != prefix.m_data[i]) {
            return false;
        }
    }
    return true;
}

bool String::ends_with(const String &suffix) const {
    for (int i = 0; i < suffix.length(); i++) {
        if (this->m_data[this->length() - suffix.length() + i] != suffix.m_data[i]) {
            return false;
        }
    }
    return true;
}

bool String::contains(const String &needle) const {
    return this->find(needle) != -1;
}

int String::find(const String &needle) const {
    int needle_index = 0;
    for (int i = 0; i < this->length(); i++) {
        if (this->m_data[i] == needle.m_data[needle_index]) {
            needle_index++;
            if (needle_index >= needle.length()) {
                return i - needle_index + 1;
            }
        } else {
            needle_index = 0;
        }
    }
    return -1;
}

int String::find(const String &needle, int start) const {
    int needle_index = 0;
    for (int i = start; i < this->length(); i++) {
        if (this->m_data[i] == needle.m_data[needle_index]) {
            needle_index++;
            if (needle_index >= needle.length()) {
                return i - needle_index + 1;
            }
        } else {
            needle_index = 0;
        }
    }
    return -1;
}

String String::concat(const String &first, const String &second) {
    String str {};
    str.reserve(first.length() + second.length());

    for (int i = 0; i < first.length(); i++) {
        str.m_data[str.m_size++] = first.m_data[i];
    }
    for (int i = 0; i < second.length(); i++) {
        str.m_data[str.m_size++] = second.m_data[i];
    }
    str.m_data[str.m_size] = '\0';

    return str;
}

void String::reserve(std::size_t min_size) {
    while (this->m_capacity < min_size) {
        this->m_capacity *= GROWTH_RATE;
    }

    char* new_data = new char[this->m_capacity + 1];
    for (int i = 0; i < this->m_size; i++) {
        new_data[i] = this->m_data[i];
    }
    new_data[m_size] = '\0';
    delete[] this->m_data;
    this->m_data = new_data;
}

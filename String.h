//
// Created by remy on 4/8/22.
//

#ifndef CPP_ASSIGNMENT6_STRING_H
#define CPP_ASSIGNMENT6_STRING_H


#include <cstddef>
#include <string>

class String {
private:
    std::size_t m_size;
    std::size_t m_capacity;
    char* m_data;

    void reserve(std::size_t min_size);
public:
    String();
    String(const char* str);
    String(String const &str);
    String(std::string const &str);
    ~String();
    String& operator=(const String& other) noexcept;
    void swap(String& str);

    char& at(int index);
    char& get(int index);
    char& front();
    char& back();

    void append(String &str);
    void append(std::string &str);
    void append(const char* str);
    void append(char str);

    String substr(int start, int length) const;
    String substr(int start) const;
    bool starts_with(const String& prefix) const;
    bool ends_with(const String& suffix) const;
    bool contains(const String& needle) const;
    int find(const String& needle) const;
    int find(const String& needle, int start) const;

    static String concat(const String& first, const String& second);

    int length() const;
    bool empty() const;
    const char* c_str() const;
};


#endif //CPP_ASSIGNMENT6_STRING_H

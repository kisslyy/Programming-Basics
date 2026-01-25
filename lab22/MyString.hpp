#pragma once
#include <iostream>
#include <cstring>

class MyString {
public:
    MyString();

    MyString(const char* str);

    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    MyString operator+(const MyString& other) const;

    ~MyString();

private:
    char* m_str;
};
#include "MyString.hpp"

    MyString::MyString() {
        m_str = new char[1];
        m_str[0] = '\0';
    }

    MyString::MyString(const char* str) {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }

    MyString::MyString(const MyString& other) {
        m_str = new char[strlen(other.m_str) + 1];
        strcpy(m_str, other.m_str);
    }

    MyString& MyString::operator=(const MyString& other) {
        if (this != &other) {
            delete[] m_str;
            m_str = new char[strlen(other.m_str) + 1];
            strcpy(m_str, other.m_str);
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.m_str;
        return os;
    }

    MyString MyString::operator+(const MyString& other) const {
        size_t newLen = strlen(m_str) + strlen(other.m_str);
        char* tempStr = new char[newLen + 1];

        strcpy(tempStr, m_str);
        strcat(tempStr, other.m_str);

        MyString result(tempStr);
        delete[] tempStr;

        return result;
    }

    MyString::~MyString() {
        delete[] m_str;
    }
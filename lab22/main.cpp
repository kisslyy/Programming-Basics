#include <iostream>
#include <cstring>

class MyString {
public:
    MyString() {
        m_str = new char[1];
        m_str[0] = '\0';
    }

    MyString(const char* str) {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }

    MyString(const MyString& other) {
        m_str = new char[strlen(other.m_str) + 1];
        strcpy(m_str, other.m_str);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] m_str;
            m_str = new char[strlen(other.m_str) + 1];
            strcpy(m_str, other.m_str);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.m_str;
        return os;
    }

    MyString operator+(const MyString& other) const {
        size_t newLen = strlen(m_str) + strlen(other.m_str);
        char* tempStr = new char[newLen + 1];

        strcpy(tempStr, m_str);
        strcat(tempStr, other.m_str);

        MyString result(tempStr);
        delete[] tempStr;

        return result;
    }

    ~MyString() {
        delete[] m_str;
    }

private:
    char* m_str;
};

int main() {

    MyString s1 = MyString(); // default ctor
    std::cout << "s1: " << s1 << "\n";

    MyString s2 = "abcd"; // ctor char*
    std::cout << "s2: " << s2 << "\n";

    s1 = s2; // operator=
    std::cout << "s1: " << s1 << "\n";

    MyString s3 = s1; // copy ctor
    std::cout << "s3: " << s3 << "\n";

    MyString s4 = "qwert"; // ctor char*
    std::cout << "s4: " << s4 << "\n";

    MyString s5 = s2 + s4; // operator+
    std::cout << "s5: " << s5 << "\n";
}
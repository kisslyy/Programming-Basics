#include <iostream>

class MyString {
public:
    MyString() { // default ctor
        size_ = 1;
        str_ = new char[size_];
        str_[0] = '\0';
    }
    MyString(const char* str) { // argument ctor
        size_ = strlen(str);
        str_ = new char[size_ + 1];
        str_ = strcpy(str_, str);
    }
    MyString(const MyString& other) { // copy ctor
        copyString(other);
    }
    MyString& operator=(const MyString& other) {
        copyString(other);
        return *this;
    }
    ~MyString() { // dtor
        delete[] str_;
    }
    void print() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << str_[i];
        }
        std::cout << std::endl;
    }
private:
    size_t size_;
    char* str_;

    void copyString(const MyString& other) {
        size_ = strlen(other.str_);
        str_ = new char[size_ + 1];
        str_ = strcpy(str_, other.str_);
    }
};

int main() {
    MyString string1 = MyString();
    MyString string2 = "abcd";
    MyString string3 = string1;
    
}
#include <iostream>
#include "MyString.hpp"

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
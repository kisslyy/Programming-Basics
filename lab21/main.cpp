#include <iostream>

class Counter {
public:
    Counter() = default;
    Counter(int startValue) {
        if (startValue < 0) {
            value = 0;
        }else{
            value = startValue;
        }
    } 
    ~Counter() {
        std::cout << "—чЄтчик удален, финальное значение: " << value << std::endl;
    }

private:
    int value = 0;
public:
    void incrementValue(int amount) {
        value += amount;
    }
    void decrementValue(int amount) {
        value -= amount;
    }
    int getValue() const { return value; }
    void reset() { value = 0; }
    bool isEven() const { return value % 2 == 0; }
    void setValue(int newValue) { value = newValue; }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Counter stackCounter;
    stackCounter.incrementValue(330);
    std::cout << stackCounter.isEven() << std::endl;



    Counter* c = new Counter;
    c->incrementValue(14);
    std::cout << c->getValue() << std::endl;
    c->decrementValue(2);
    std::cout << c->getValue() << std::endl;
    c->reset();
    std::cout << c->getValue() << std::endl;
    delete c;

    return 0;
}
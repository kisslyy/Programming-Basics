#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* MAKE(int value) {
    Node* p = new Node;
    p->data = value;
    p->next = nullptr;
    return p;
}

void ADD_BACK(Node* head, int value) {
    Node* p = MAKE(value);
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = p;
}

void PRINT(Node* head) {
    Node* p = head->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << "\n";
}

// удалить узел после prev
void DELETE_AFTER(Node* prev) {
    if (prev == nullptr || prev->next == nullptr) return;
    Node* t = prev->next;
    prev->next = t->next;
    delete t;
}

// удаление первого элемента
void DELETE_FRONT(Node* head) {
    if (head->next == nullptr) return;
    Node* t = head->next;
    head->next = t->next;
    delete t;
}

bool isPalindrome(int x) {
    int orig = x;
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == orig;
}

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// cорт по невозрастанию
void SORT_DESC(Node* head) {
    for (Node* i = head->next; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data < j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    Node head;
    head.next = nullptr;

    std::cout << "¬ведите натуральные числа (0 Ч конец ввода):\n";

    int x;
    while (std::cin >> x && x > 0) {
        ADD_BACK(&head, x);
    }

    bool hasPalindrome = false;
    for (Node* p = head.next; p != nullptr; p = p->next) {
        if (isPalindrome(p->data)) {
            hasPalindrome = true;
            break;
        }
    }

    if (!hasPalindrome) {
        SORT_DESC(&head);
    } else {
        Node* prev = &head;
        Node* cur = head.next;

        while (cur != nullptr) {
            // удалить простые
            if (isPrime(cur->data)) {
                DELETE_AFTER(prev);
                cur = prev->next;
                continue;
            }

            // дублировать числа на 0
            if (cur->data % 10 == 0) {
                Node* copy = MAKE(cur->data);
                copy->next = cur->next;
                cur->next = copy;

                prev = copy;     // пропускаем копию
                cur = copy->next;
                continue;
            }

            prev = cur;
            cur = cur->next;
        }
    }

    std::cout << "\n–езультат:\n";
    PRINT(&head);

    return 0;
}

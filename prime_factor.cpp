#include <iostream>
#include <array>
#include <vector>

struct Node {
    long value;
    Node* next2;
    Node* next3;
    Node* next5;
    Node* next7;
};

long divBy(long val, long by) {
    if(val % by == 0) return val / by;
    return 0;
}

int main() {
    long max_product = 600851475143;
    int two;
    Node* root = new Node{max_product, nullptr, nullptr, nullptr, nullptr}; 

    std::cout << "root value: " << root->value << std::endl;
    long n = divBy(root->value, 2);
    root->next2 = new Node{n, nullptr, nullptr, nullptr, nullptr};

    return 0;
}
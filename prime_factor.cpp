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
    //long max_product = 600851475143;
    long max_product = 32; 
    int two;
    Node* root = new Node{max_product, nullptr, nullptr, nullptr, nullptr}; 

    long n = divBy(root->value, 2);
    root->next2 = new Node{n, nullptr, nullptr, nullptr, nullptr};


    root->next2->next2 = new Node{divBy(root->next2->value, 2), nullptr, nullptr, nullptr, nullptr};

    // iterate depth-first through tree
    Node* current = root;
    while(current != nullptr) {
        std::cout << "current value: " << current->value << std::endl;
        current = current->next2;
    }

    return 0;
}
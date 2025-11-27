#include <iostream>
#include <array>
#include <vector>

struct Node {
    long value;
    //Node* parent;
    std::vector<Node*> children;
    std::vector<int> num;
};

long divBy(long val, long by) {
    if(val % by == 0) return val / by;
    return 0;
}

bool isPrime(long val) {
    if(val < 2) return false;
    for(long i = 2; i * i <= val; ++i) {
        if(val % i == 0) return false;
    }
    return true;
}


int main() {
    //long max_product = 600851475143;
    //long max_product = 2 * 3 * 5 * 7;
    long max_product = 2 * 2 * 2 * 2 * 2;
    Node* root = new Node{max_product, {}};

    std::vector<Node*> nodeStack; 

    std::cout << "is prime " << max_product << ": " << isPrime(max_product) << std::endl;
    
    try {
        root->children.push_back(new Node{divBy(root->value, 2), {}});
        root->children.push_back(new Node{divBy(root->value, 3), {}});
        root->children.push_back(new Node{divBy(root->value, 5), {}});
        root->children.push_back(new Node{divBy(root->value, 7), {}});

    //nodeStack.push_back(root->next2);
    } catch(const std::exception& e) {
        std::cout << "exception caught " << e.what() << std::endl;
    }
    
    // iterate depth-first through tree
    Node* current = root;
    while(current != nullptr) { // nodes unvisited
        nodeStack.push_back(current);
        int childIndex = 0;
        current = current->children.empty() ? nullptr : current->children[0];
        //current->children.push_back(new Node{divBy(current->value, 2), {}});
        if(current != nullptr) { 
            std::cout << "current value:" << current->value << std::endl;
            
        }
    }

    return 0;
}
#include <iostream>
#include <array>
#include <vector>
#include <cmath>

struct Node {
    long value;
    //Node* parent;
    std::vector<Node*> children;
    std::vector<int> num;
};

long divBy(long val, int by) {
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

bool createNeighbors(Node* current) {
    current->children.push_back(new Node{divBy(current->value, 2), {}});
    current->children.push_back(new Node{divBy(current->value, 3), {}});
    current->children.push_back(new Node{divBy(current->value, 5), {}});
    current->children.push_back(new Node{divBy(current->value, 7), {}});
    return true;
}

bool visited(std::vector<Node*> stack, Node* node) {
    stack.push_back(node);
    return true;
}

bool popStack(std::vector<Node*> stack) {
    try {
        if(stack.empty()) throw std::runtime_error("stack is empty, cannot pop");
        stack.pop_back();
    } catch(const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    
    return true;
}

bool pushStack(std::vector<Node*>& stack, Node* node) {
    stack.push_back(node);
    return true;
}


int main() {
    //long max_product = 600851475143;
    long product = pow(2, 10);

    std::vector<Node*> nodeStack; 

    std::cout << "is prime " << product << ": " << isPrime(product) << std::endl;
    
    // create depth-first through tree with stack
    Node* root = new Node{product, {}};
    int v;
    Node* current = nullptr;
    pushStack(nodeStack, root);
    while(nodeStack.size() > 0) { // nodes unvisited
        current = nodeStack.back();
        createNeighbors(current);
        visited(nodeStack, current);

        v = divBy(current->value, 2); // 0 should terminate this branch
        std::cout << "divBy result: " << v << std::endl;
        current->children[0]->value = v;
        if(v == 1) popStack(nodeStack);
        if(v > 0) pushStack(nodeStack, current->children[0]);
        if(nodeStack.empty()) {
            std::cout << "stack empty, terminating" << std::endl;
            break;
        }
        current = nodeStack.back();

        //int childIndex = 0;
        //current = current->children.empty() ? nullptr : current->children[0];
        //current->children.push_back(new Node{divBy(current->value, 2), {}});
        if(current != nullptr) { 
            std::cout << "current value:" << current->value << std::endl;
            
        }
    }

    return 0;
}
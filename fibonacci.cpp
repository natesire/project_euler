#include <iostream>
#include <array>
#include <vector>

int main() {
    int sum = 0;
    int new_term = 0;
    std::vector<int> fibonacci_terms = {1, 2};
    for(int i = 0; i < fibonacci_terms.size(); ++i) {
        new_term = fibonacci_terms[0] + fibonacci_terms[1];
        if(new_term > 4000000) break;
    }
    return 0;
}
#include <iostream>
#include <array>
#include <vector>

int main() {
    int sum = 2;
    int new_term = 0;
    std::vector<int> fibonacci_terms = {1, 2};
    for(int i = 0; i < 40000000; ++i) {
        new_term = fibonacci_terms[i] + fibonacci_terms[i + 1];
        fibonacci_terms.push_back(new_term);
        if(new_term >= 4000000) {
            break;
        }
        if(new_term % 2 == 0) {
            sum += new_term;
        }
    }
    std::cout << "Sum of even Fibonacci terms below four million: " << sum;
    return 0;
}
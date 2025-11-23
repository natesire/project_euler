#include <iostream>
#include <cstdint>

int main () {
	unsigned long sum = 0;
	unsigned long squared = 0;
	const int FIRST_Squared = 11;

	for(int j = 1; j <= FIRST_Squared; j += 2) {

		squared = j * j;
		sum += squared;
		std::cout << "j " << j << " squared to " << squared << ", squared is odd, sum now " << sum << std::endl;
	}	
	
	return 0; // what if I don't return anything?
}

// failed
// 8443086211760
// 8500711509336
// 8500711509336
// 8500711509336
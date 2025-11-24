#include <iostream>
#include <cstdint>

int main () {
	unsigned long sum = 0;
	unsigned long squared = 0;

	for(unsigned long j = 1; j <= 598000; j += 2) {

		if(j % 2 == 0) {
			throw std::runtime_error("j is even!");
		} else {
			squared = j * j;
			sum = sum + squared;
			std::cout << "j " << j << " squared to " << squared << ", squared is odd, sum now " << sum << std::endl;
		}
		
	}	
	
	return 0; // what if I don't return anything?
}

// failed
// 8443086211760
// 8500711509336
// 8500711509336
// 8500711509336
// 178802000000
// 89401000000
// 8500711509336
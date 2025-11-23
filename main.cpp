#include <iostream>
#include <cstdint>

bool isOdd(long number) {
	return number % 2 != 0;
}

int main () {
	int squared_and_odd_summed = 0;
	unsigned long squared = 0;
	const int FIRST_Squared = 5;
	int i = 0;
	
	while(true) {
		i++;

		if(i > FIRST_Squared) {
			std::cout << "stopping at: " << i << "\n";
			break;
		}
		
		squared = i * i;

		if(squared < 0) {
			std::cout << "overflow detected at i: " << squared << "\n";
			break;
		}

		if(isOdd(squared)) { 
			std::cout << squared << " squared number is odd \n";
			squared_and_odd_summed += squared; }
		std::cout << "sum: " << squared_and_odd_summed << "\n";	
	}	
	
	return squared_and_odd_summed;
}

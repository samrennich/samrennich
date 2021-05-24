// Prime Seive

#include <iostream>
#include <vector>
#include <cmath>

// Constants
const unsigned long long int range = 1000000; // Sets the upper limit of where to find primes

// Prototypes
void primeSeive(std::vector<bool>&); // Sets all non-prime values to false
void printPrimes(std::vector<bool>); // Prints all values that are prime given prime vector
int numOfPrimes(std::vector<bool>); // Finds the number of primes in the vector

int main() {
	
	// Create initial vector
	std::vector<bool> primes(range + 1, true);
	primes[0] = false; // Manual override for value 0
	primes[1] = false; // Manual override for value 1
	
	// Sort, leaving only primes true
	primeSeive(primes);
	
	// Prints all primes in the given range
	//printPrimes(primes);
	
	// Print the number of primes in range
	std::cout << numOfPrimes(primes) << std::endl;
	
	//Exit
	std::cin.clear();
    getchar();
    return 0;
}


// Removes all non-primes leaving only primes as true in the vector
void primeSeive(std::vector<bool>& primes) {
	
	// Sets scale to the square root of the range for finding prime divisors
	unsigned long long int scale = static_cast<int>(sqrt(range));
	
	// Turns all even numbers (bar 2) to false
	for (unsigned long long int i = 4; i <= range; i += 2) {
		primes[i] = false;
	}
	
	// Iterates through every other value in the vector
	for (unsigned long long int i = 3; i <= scale; i += 2) {
		if (primes[i]) { // If the value is prime...
			for (unsigned long long int j = (i * 2); j <= range; j += i) { // Set all multiples of it to be false
				primes[j] = false;
			}
		}
	}
	
	return; // Finish
}

// Prints all values that are prime
void printPrimes(std::vector<bool> primes) {
	
	for (unsigned long long int i = 0; i <= range; i++) { // Iterates through every value in the vector
		if (primes[i]) { // If it is prime...
			std::cout << i << std::endl; // Print it
		}
	}
	
	return; // Finish
}

// Finds the number of primes in the vector
int numOfPrimes(std::vector<bool> primes) {
	
	unsigned long long int counter = 0; // Counts the number of primes
	
	for (unsigned long long int i = 0; i < primes.size(); i++) { // Iterates through every value in the vector
		if (primes[i]) { // If it is prime...
			counter++; // Add to the counter
		}
	}
	
	return counter; // Finish
}
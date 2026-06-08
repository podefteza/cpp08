#include "easyfind.hpp"

int main () {
	///////////////////////// VECTOR TESTS /////////////////////////
	std::cout << "Creating a vector of odd numbers from 0 to 50..." << std::endl;
	std::vector<int> odd_numbers;
	for (int i = 0; i <= 50; i++) {
		if (i % 2 == 1) {
			odd_numbers.push_back(i);
		}
	}

	try {
		std::cout << "Looking for 42 in odd_numbers: ";
		easyfind(odd_numbers, 42);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for 13 in odd_numbers: ";
		easyfind(odd_numbers, 13);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	//////////////////////// LIST TESTS /////////////////////////
	std::cout << "Creatting a list of even numbers from 0 to 50..." << std::endl;
	std::list<int> even_numbers;
	for (int i = 0; i <= 50; i += 2) {
		even_numbers.push_back(i);
	}

	try {
		std::cout << "Looking for 42 in even_numbers: ";
		easyfind(even_numbers, 42);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for -1 in even_numbers: ";
		easyfind(even_numbers, -1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for 0 in even_numbers: ";
		easyfind(even_numbers, 0);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	//////////////////////// DEQUE TESTS /////////////////////////
	std::cout << "Creating a deque of multiples of 5 from 0 to 50..." << std::endl;
	std::deque<int> multiples_of_5;
	for (int i = 0; i <= 50; i += 5) {
		multiples_of_5.push_back(i);
	}

	try {
		std::cout << "Looking for 25 in multiples_of_5: ";
		easyfind(multiples_of_5, 25);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for 42 in multiples_of_5: ";
		easyfind(multiples_of_5, 42);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

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

	////////////////////////// TESTING CONST /////////////////////////
	std::cout << std::endl << "Testing with a const vector, list and deque..." << std::endl;
	const int vec_vals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	const int list_vals[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40};
	const int deque_vals[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60};

	const std::vector<int> multiples_of_1_and_2(vec_vals, vec_vals + 20);
	const std::list<int> multiples_of_3_and_4(list_vals, list_vals + 20);
	const std::deque<int> multiples_of_5_and_6(deque_vals, deque_vals + 20);

	try {
		std::cout << "Looking for 6 in multiples_of_1_and_2: ";
		easyfind(multiples_of_1_and_2, 6);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for 12 in multiples_of_3_and_4: ";
		easyfind(multiples_of_3_and_4, 42);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Looking for 30 in multiples_of_5_and_6: ";
		easyfind(multiples_of_5_and_6, 30);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

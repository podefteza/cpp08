#include "Span.hpp"

void bigTest() {
	std::cout << std::endl << "Creating a Span of 42000 elements..." << std::endl;
	Span sp(42000);

	std::vector<int> vals;
	vals.reserve(42000);
	for (int i = 0; i < 42000; ++i)
		vals.push_back(i);
	try {
		sp.addNumber(vals.begin(), vals.end());
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void sameNumber() {
	std::cout << std::endl << "Creating a Span of 5 elements with the same number..." << std::endl;
	Span sp(5);

	sp.addNumber(42);
	sp.addNumber(42);
	sp.addNumber(42);
	sp.addNumber(42);
	sp.addNumber(42);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void sameSpan() {
	std::cout << std::endl << "Creating a Span of 2 elements..." << std::endl;
	Span sp(2);

	sp.addNumber(-42);
	sp.addNumber(42);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void oneElement() {
	std::cout << std::endl << "Creating a Span of 1 element..." << std::endl;
	Span sp(1);

	sp.addNumber(42);

	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void testException() {
	std::cout << std::endl << "Testing exception handling..." << std::endl;
	Span sp(3);

	try {
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sameNumber();
	sameSpan();
	oneElement();
	testException();
	bigTest();

	return 0;
}

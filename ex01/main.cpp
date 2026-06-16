#include "Span.hpp"

void sameNumber() {
	std::cout << std::endl << "Creating a Span of 5 elements with the same number..." << std::endl;
	Span same(5);

	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);

	std::cout << "Shortest span: " << same.shortestSpan() << std::endl;
	std::cout << "Longest span: " << same.longestSpan() << std::endl;
}

void sameSpan() {
	std::cout << std::endl << "Creating a Span of 2 elements..." << std::endl;
	Span same(2);

	same.addNumber(-42);
	same.addNumber(42);

	std::cout << "Shortest span: " << same.shortestSpan() << std::endl;
	std::cout << "Longest span: " << same.longestSpan() << std::endl;
}

void oneElement() {
	std::cout << std::endl << "Creating a Span of 1 element..." << std::endl;
	Span one(1);

	one.addNumber(42);

	try {
		std::cout << "Shortest span: " << one.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << one.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void testException() {
	std::cout << std::endl << "Testing exception handling..." << std::endl;
	Span exception(3);

	try {
		exception.addNumber(1);
		exception.addNumber(2);
		exception.addNumber(3);
		exception.addNumber(4);
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void bigTest() {
	srand(static_cast<unsigned int>(time(0)));

	std::cout << std::endl << "Creating a Span of 42000 elements, testing with an array..." << std::endl;
	Span big(42000);
	int values[42000];
	for (int i = 0; i < 42000; i++)
		values[i] = i;
	big.addNumber(values, values + 42000);
	std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big.longestSpan() << std::endl;

	std::cout << std::endl << "Creating a Span of 12345 elements, testing with a vector..." << std::endl;
	Span random(12345);
	std::vector<int> randomValues(12345);
	for (int i = 0; i < 12345; i++)
		randomValues[i] = rand();
	random.addNumber(randomValues.begin(), randomValues.end());
	std::cout << "Shortest span: " << random.shortestSpan() << std::endl;
	std::cout << "Longest span: " << random.longestSpan() << std::endl;

	std::cout << std::endl << "Creating a Span of 20000 elements, testing with a list..." << std::endl;
	Span listSpan(20000);
	std::list<int> listValues;
	for (int i = 0; i < 20000; i++)
		listValues.push_back(rand());
	listSpan.addNumber(listValues.begin(), listValues.end());
	std::cout << "Shortest span: " << listSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << listSpan.longestSpan() << std::endl;

	std::cout << std::endl << "Creating a Span of 15000 elements, testing with a deque..." << std::endl;
	Span dequeSpan(15000);
	std::deque<int> dequeValues;
	for (int i = 0; i < 15000; i++)
		dequeValues.push_back(rand());
	dequeSpan.addNumber(dequeValues.begin(), dequeValues.end());
	std::cout << "Shortest span: " << dequeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << dequeSpan.longestSpan() << std::endl;
}

int main()
{
	//////////////////////// SUBJECT TESTS /////////////////////////
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//////////////////////// MY TESTS /////////////////////////
	sameNumber();
	sameSpan();
	oneElement();
	testException();
	bigTest();

	return 0;
}

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : maxSize(n) {
}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize) {
		throw std::runtime_error("Span is full");
	}
	numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sortedNumbers.size() - 1; ++i) {
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int maxSpan = sortedNumbers[sortedNumbers.size() - 1] - sortedNumbers[0];
	return maxSpan;
}

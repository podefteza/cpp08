#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int maxSize;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);

		template <typename Iterator>
		void addNumber(Iterator first, Iterator last)
		{
			if (numbers.size() + std::distance(first, last) > maxSize)
				throw std::runtime_error("Span is full");
			numbers.insert(numbers.end(), first, last);
		}

		int shortestSpan() const;
		int longestSpan() const;
};

#endif

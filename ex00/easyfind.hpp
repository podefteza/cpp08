#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw std::runtime_error("Value not found in the container.");
	std::cout << "Found " << value << " in the container, on the index " << std::distance(container.begin(), i) << "." << std::endl;
	return i;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	typename T::const_iterator i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw std::runtime_error("Value not found in the container.");
	std::cout << "Found " << value << " in the container, on the index " << std::distance(container.begin(), i) << "." << std::endl;
	return i;
}

// the incrementation of the index is done by std::find; i is the iterator, like a pointer to the value found
// using std::runtime_error allows us to throw an exception with a custom message, unlike std::exception where we'd have to override the what() method

#endif

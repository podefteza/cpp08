#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
	const char* what() const throw() {
		return "Value not found in the container.";
	}
};

template <typename T>
void easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);;
	if (it != container.end()) {
		std::cout << "Found " << value << " in the container." << std::endl;
	} else {
		throw ValueNotFoundException();
	}
}

#endif

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(T &container, int value) {
	std::find_first_of(value, container);
}


#endif


/*Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value*/

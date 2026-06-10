#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	//////////////////////// SUBJECT TESTS /////////////////////////
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	//////////////////////// MY TESTS /////////////////////////
	std::cout << std::endl << "Testing with a list..." << std::endl;
	std::list<int> mstackList;

	mstackList.push_back(5);
	mstackList.push_back(17);

	std::cout << mstackList.back() << std::endl;

	mstackList.pop_back();

	std::cout << mstackList.size() << std::endl;

	mstackList.push_back(3);
	mstackList.push_back(5);
	mstackList.push_back(737);
	//[...]
	mstackList.push_back(0);

	std::list<int>::iterator list_it = mstackList.begin();
	std::list<int>::iterator list_ite = mstackList.end();

	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
	std::list<int> sList(mstackList);

	std::cout << std::endl << "Testing with a vector AND a reverse iterator..." << std::endl;
	std::vector<int> mstackVector;

	mstackVector.push_back(5);
	mstackVector.push_back(17);

	std::cout << mstackVector.back() << std::endl;

	mstackVector.pop_back();

	std::cout << mstackVector.size() << std::endl;

	mstackVector.push_back(3);
	mstackVector.push_back(5);
	mstackVector.push_back(737);
	//[...]
	mstackVector.push_back(0);

	std::vector<int>::reverse_iterator vector_it = mstackVector.rbegin();
	std::vector<int>::reverse_iterator vector_ite = mstackVector.rend();

	++vector_it;
	--vector_it;
	while (vector_it != vector_ite)
	{
		std::cout << *vector_it << std::endl;
		++vector_it;
	}
	std::vector<int> sVector(mstackVector);

	return 0;
}

# C++ Module 08: Templated Containers, Iterators, and Algorithms

Welcome to Module 08! If you're new to these concepts, this module represents a huge leap in how you'll write C++ code. You are moving away from manually managing every single array and looping through them with indices, and moving towards the **Standard Template Library (STL)**.

Before diving into the exercises, let's break down the four core concepts you need to know:

## Core Concepts for Beginners

### 1. Templates
Templates are a way to write generic code. Instead of writing one function to find a number in an array of `int`s and another for an array of `float`s, you write a *single template function*. The compiler then dynamically generates the correct version of the function based on the type of data you pass to it. It's like a blueprint for code.

### 2. Containers
Containers are pre-built classes in C++ that store collections of data. You don't have to write your own linked lists or dynamic arrays anymore!
- `std::vector`: A dynamic array that can grow in size.
- `std::list`: A doubly linked list.
- `std::deque`: A double-ended queue (you can insert/remove from both ends).
- `std::stack`: A LIFO (Last-In-First-Out) data structure.

### 3. Iterators
Think of iterators as "smart pointers" for containers. They let you traverse (loop through) a container without needing to know how that container is built under the hood.
- `begin()` gives you an iterator pointing to the first element.
- `end()` gives you an iterator pointing to *just past* the last element.
By incrementing an iterator (`it++`), you move to the next item, whether you're using a vector, list, or deque!

### 4. Algorithms
The STL includes a bunch of pre-written functions that operate on ranges of elements (using iterators). Instead of writing your own loops to search, sort, or count elements, you can use built-in algorithms like `std::find`, `std::sort`, or `std::distance`.

---

## The Exercises Explained

### Exercise 00: Easy find
**The Goal:** Write a generic function that takes *any* container of integers and searches for a specific integer inside it.

**The Implementation:**
- We wrote a template function `easyfind(T &container, int value)`.
- Inside, we use the STL algorithm `std::find(container.begin(), container.end(), value)`. This algorithm uses the container's iterators to search from start to finish.
- If `std::find` reaches `container.end()` without finding the value, it means the value isn't there, and we throw a `std::runtime_error`.
- We also overloaded the function to take `const T &container` so that it works perfectly with read-only containers (returning a `const_iterator`).
- We used `std::distance` to calculate the exact index of the found element for our print statement, showcasing how iterators can be used to measure distances.

### Exercise 01: Span
**The Goal:** Create a class `Span` that stores up to `N` integers. We need to be able to find the shortest and longest distance (span) between any two numbers currently in the object. We also need an efficient way to add thousands of numbers at once.

**The Implementation:**
- **Storage:** We used a `std::vector<int>` internally to store the numbers because it's fast and easy to sort.
- **Single Addition:** `addNumber(int)` checks if we've hit our max capacity. If so, it throws a `std::runtime_error`.
- **Range Addition:** To avoid calling `addNumber` 10,000 times in a row, we created a template function `addNumber(Iterator first, Iterator last)`. It takes two iterators (representing a range from *any* other container) and uses the vector's `insert()` method to add all of them at once.
- **Longest Span:** We first make a copy of our vector and sort it using the `std::sort` algorithm. The longest span is simply the difference between the very last element and the very first element of this sorted vector.
- **Shortest Span:** After sorting the copy, we loop through the sorted vector, comparing each number to the one right next to it. We keep track of the smallest difference we find. Sorting makes this highly efficient (O(n log n) instead of comparing every number to every other number, which would be O(n²)).

### Exercise 02: Mutated abomination
**The Goal:** The standard `std::stack` is a "container adaptor." It's great for pushing and popping data, but it intentionally hides its contents so you *cannot* iterate through it. Our goal was to hack the stack to make it iterable, without breaking its core functionality.

**The Implementation:**
- We created a `MutantStack` template class that directly inherits from `std::stack`.
- By looking under the hood of how `std::stack` is implemented in C++, we know it contains a protected member variable called `c`. This `c` is the underlying container (usually a `std::deque` by default) where the data is actually stored.
- Because `c` is a protected member, our derived `MutantStack` class is allowed to access it.
- We created standard iterator methods like `begin()`, `end()`, `rbegin()` (reverse begin), and `rend()` (reverse end) inside `MutantStack`.
- These methods simply reach into the underlying container `c` and return *its* iterators (e.g., `return this->c.begin();`).
- The result? We get an object that functions exactly like a normal `std::stack`, but can also be looped through like a `std::vector` or `std::list`. We proved this in `main.cpp` by getting identical output whether we used our `MutantStack`, a `std::vector`, or a `std::list`.

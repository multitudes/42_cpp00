# 42_cpp00

## First exercise of the C++ module at 42 Berlin

### style notes
I want to use a style which is different than the one used in the C module.  
- The format of the comments is doxygen compatible
- the braces are on the same line as the function name or the control structure.
- no namespaces are allowed as per in the subject. 

## The use of `endl`
One of the differences to C is the use of `endl` instead of `\n`. Also `std::cout` is a "stream" and `std::endl` is a manipulator that not only inserts a new line but also flushes the output buffer.

### The `toupper` function
`toupper` is a c function also directly avalaible in cpp without using namespaces. It converts a lowercase char to uppercase. In C++ 98 there are not many other alternatives. I did not see in this case a "proper" c++ way of getting a string uppercase. There are possible variations of this using `transform` but I cannot use them because the subject forbid the use of the STL for this exercise.

### Use of `pragma once` and #if guards

to avoid double inclusion of header files we can use either this syntax:
```cpp
#ifndef HEADER_HPP
#define HEADER_HPP
// code
#endif
```
or 
```cpp
#pragma once
```
The second one is more modern and is supported by most compilers but it is not standard. Some codebases use both to ensure compatibility with older compilers.

Use whichever you prefer but be consistent.

## ex00

Simple program that prints a string in uppercase in a c++ way. To find the c++ was probably more challenging than the actual implementation.

## ex01

Create a contact book with 8 entries and a basic menu to interact with it. I can ADD, SEARCH and EXIT. 

## ex02
It is a kind of puzzle in c++. the file `Account.hpp` and the `tests.cpp` was given. We had to create the file `Account.cpp` and implement the methods. The output had to be the same as the log file given in the subject. For this assignment I actually also did create some tests in the `tests` folder which compare my output to the one in the subject.

### Explanation of Code in tests.cpp Ex02
In the "Account.hpp" file, both `pragma once` and `#if` guards are used for compatibility.
the `Account` class is defined with a `typedef` for `t` like `typedef Account	t;` which is probably for conciveness. 
The main function in tests.cpp has a few other typedefs:
```cpp
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
```	
It seems that they want us to see some real cpp code in action. So `accounts_t` is a vector of `Account::t` (where t is an alias for Account again). `ints_t` is a vector of integers. `acc_int_t` is a pair of iterators, one for `accounts_t` and one for `ints_t`, facilitating simultaneous iteration over accounts and transaction amounts.
The rest of the code is about initializing account and transaction data, and printing the account information before and after the transactions.

### tests
to run the tests you can use the following command:
```bash
make 
make -C tests
```

## Debug
I use a debug macro in the code. To enable it you can uncomment this line in the makefile:
```makefile
# CXXFLAGS += -DNDEBUG
```
It is just a simple macro that prints the file and the line where it was called.
```
#ifdef NDEBUG
#define debug(...)
#else
#define debug(msg) \
    std::cerr << COLOR << __FILE__ << ":" << __LINE__ << ": " << msg << RESET << std::endl;
#endif
```
It is nice to be able to switch on and off the debug statements.  

## links

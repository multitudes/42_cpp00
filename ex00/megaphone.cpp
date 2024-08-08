/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:06:44 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/08 14:30:14 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief Prints the arguments in uppercase
 * 
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @return int 0 if successful
 * 
 * @note If no arguments are passed, it prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
 * idiomatic in cpp I usse const char** instead of char**
 * and static_cast<char> instead of (char)
 * static_cast is generally preferred over C-style casting in modern C++
 * but also is mostly about clarity and readability
 * 
 * really in modern cpp you would have this:
 *     for (char& c : str) {
        c = toupper(c);
    }
*/
int main(int argc, char **argv) {
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			for (const char* p = argv[i]; *p; ++p) {
				std::cout << static_cast<char>(toupper(*p));
			}
		}
		std::cout << std::endl; 
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}

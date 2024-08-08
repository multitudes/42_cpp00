/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:53:01 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/02 10:23:44 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

/**
 * @brief Function to check if a string is only spaces because the phonebook
 * should not allow empty strings
 * 
 * @param str The string to check.
 * @return true If the string is only spaces.
 */
static bool isOnlySpaces(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isspace(str[i])) {
			return (false);
		}
	}
	return (true);
}

/**
 * @brief Function to get a string from the user and return it.
 * 
 * @param input The string to store the user input.
 * @param prompt The prompt to display to the user.
 * @return true If the user input is not empty.
 */
static void getString(std::string& input, const std::string& prompt) {
	while (true) {
		std::cout << prompt << std::endl;
		if (!(std::cin >> input)) {
            if (std::cin.eof()) {
				std::cout << "Exiting..." << std::endl;
				std::exit(0);
			}
		}
		if (!isOnlySpaces(input)) {
			return ;
		}
	}
	return ;
}
	
/**
 * @brief Function to get the input from the user and return a Contact object
 * will only accept non empty strings
 * 
 * @return Contact The contact object created from the user input.
 */
static Contact getInput() {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	getString(firstName, "Enter first name: ");
	getString(lastName, "Enter last name: ");
	getString(nickName, "Enter nickname: ");
	getString(phoneNumber, "Enter phone number: ");
	getString(darkestSecret, "Enter darkest secret: ");
	std::cout << "-----------\nContact added\n-----------\n" << std::endl;
	return (Contact(firstName, lastName, nickName, phoneNumber, darkestSecret));
}

/**
 * @brief Main function
 * The user can add a contact, search for a contact or exit the program
 */
 int main() {
	PhoneBook phoneBook; // phonebook is initialized with 0 contacts
	std::string command; // in cpp this string is already by default initializing to ""
	
	while (true)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		if (!(std::cin >> command)) {
            if (std::cin.eof()) {
                std::cout << "Exiting..." << std::endl;
                break;
			}
        }
		if (command == "ADD")
			phoneBook.addContact(getInput());
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}

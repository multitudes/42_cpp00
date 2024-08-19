/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:59:31 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/19 21:05:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

/**
 * @brief Default constructor for the PhoneBook class.
 * 
 * Initializes all member variables to their default values.
 * I need the empty constructor because of the array in PhoneBook which needs
 * to be initialized with an empty contact array.
 */ 
PhoneBook::PhoneBook(): numContacts(0), nextPositionToAdd(0) {
	for (int i = 0; i < maxContacts; ++i) 
		contacts[i] = Contact();
}

/**
 * @brief Function to add a contact to the phone book.
 * 
 * @param contact The contact to add to the phone book.
 * 
 * If the phonebook is full, the oldest contact will be overwritten
 * therefore the next position to add will be rotating (modulo maxContacts)
 * but once it is full the number of contacts will not increase
 * so i know what to print when searching for contacts
 */
void PhoneBook::addContact(Contact contact) {
	numContacts = (numContacts < maxContacts) ? numContacts + 1 : numContacts;
	contacts[nextPositionToAdd] = contact;
	nextPositionToAdd = (nextPositionToAdd + 1) % maxContacts;
}

/**
 * @brief Function to print all contacts in the phone book.
 * 
 * This function will display a list of all contacts in the phone book.
 */
void PhoneBook::printAllContacts() {
	std::cout << "Index     |First Name|Last Name |Nick Name |" << std::endl;
	for (int i = 0; i < numContacts; i++) {
		std::cout << std::setw(10) << std::left;
		std::cout << i << "|";
		if (contacts[i].getFirstName().length() > 10) {
			std::cout << std::setw(10) << std::left << contacts[i].getFirstName().substr(0, 9) + ".";
		} else {
			std::cout << std::setw(10) << std::left << contacts[i].getFirstName();
		}
		std::cout << "|";
		if (contacts[i].getLastName().length() > 10) {
			std::cout << std::setw(10) << std::left << contacts[i].getLastName().substr(0, 9) + ".";
		} else {
			std::cout << std::setw(10) << std::left << contacts[i].getLastName();
		}
		std::cout << "|";
		if (contacts[i].getNickName().length() > 10) {
			std::cout << std::setw(10) << std::left << contacts[i].getNickName().substr(0, 9) + ".";
		} else { 
			std::cout << std::setw(10) << std::left << contacts[i].getNickName();
		}
		std::cout << "|";
		std::cout << std::endl; 
	}
}


/**
 * @brief Function to print the details of a contact in the phone book.
 * 
 * @param index The index of the contact to display.
 * 
 * This function will display the details of a contact in the phone book.
 */
bool PhoneBook::printOneContact(const int index) {
	if (index < numContacts) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nick Name: " << contacts[index].getNickName() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		return true;
	} else {
		std::cout << "No contact found with this item." << std::endl;
		return false;
	}
}

/**
 * @brief Function to search for a contact in the phone book.
 * 
 * This function will display a list of all contacts in the phone book and
 * prompt the user to enter an index to display the details of a contact.
 * If the user enters an invalid index, the function will prompt the user to
 * enter a valid index.
 */
void PhoneBook::searchContact() {
	if (numContacts == 0) {
		std::cout << "No contacts to display.\n" << std::endl;
		return;
	} else {
		printAllContacts();
		while (1) {
			std::string index;
			std::cout << "Enter index to display: ";
			if (!(std::getline(std::cin, index))) {
				if (std::cin.eof()) {
					std::cout << "Exiting..." << std::endl;
					exit(0);
				}
			}
			bool isDigit = true;
			for (size_t i = 0; i < index.length(); i++) {
				if (!std::isdigit(index[i])) {
					isDigit = false;
					break;
				}
			}
			if (!isDigit) {
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue;
			} else {
				if (printOneContact(atoi(index.c_str()))) {
					return;
				} else {
					continue;
				}
			}
		}
	}	
	return;
}

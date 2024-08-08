/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:59:59 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/07 11:00:47 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

/**
 * @brief A class representing a phone book.
 * 
 * This class stores an array of contacts and provides functions to add and search
 * for contacts.
 * Our phonebook an contain only 8 contacts. When adding more than that the 
 * oldest will be overwritten. I tried to make this class as minimal 
 * as possible. I do not need a destructor since I do not acquire any resources.
 */
class PhoneBook
{
	public:
		// Constructors
		PhoneBook();  
		
		// Member functions
		void addContact(const Contact contact);
		bool printOneContact(const int index);
		void printAllContacts();
		void searchContact();
		
		// constants
		static const int maxContacts = 8;
		
	private:
		Contact contacts[maxContacts];
		int numContacts;
		int nextPositionToAdd;
};

#endif  // PHONEBOOK_HPP_

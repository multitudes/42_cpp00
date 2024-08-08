/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:59:18 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/08 14:35:14 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * @brief Default constructor for the Contact class.
 * 
 * Initializes all member variables to an empty string.
 * I need the empty constructor because of the array in PhoneBook which needs 
 * to be initialized with an empty contact array.
 */
Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

/**
 * @brief Parameterized constructor for the Contact class.
 * 
 * Initializes all member variables to the provided values.
 * 
 * @param firstName The first name of the contact.
 * @param lastName The last name of the contact.
 * @param nickName The nickname of the contact.
 * @param phoneNumber The phone number of the contact.
 * @param darkestSecret The darkest secret of the contact.
 */
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
    this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

/**
 * setters are not used therefore I removed them
 */

/**
 * getters are used in searchContact() in PhoneBook.cpp
 */
std::string Contact::getFirstName() const {
	return this->firstName;
}

/**
 * @brief Getter for the last name of the contact.
*/
std::string Contact::getLastName() const {
	return this->lastName;
}

/**
 * @brief Getter for the nickname of the contact.
*/
std::string Contact::getNickName() const {
	return this->nickName;
}

/**
 * @brief Getter for the phone number of the contact.
*/
std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

/**
 * @brief Getter for the darkest secret of the contact.
*/
std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:00:36 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/07 11:00:40 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
btw In C++, when you declare a member function as const after the function 
signature, it means that the function is a "const member function." 
This indicates that the function does not modify the object on which it is called. 
It's a promise to the compiler that the function won't modify any non-static 
data members of the class.
*/
#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

// class definition in non canonical form!

/**
 * @brief A class representing a contact in a phone book.
 * 
 * This class stores the first name, last name, nickname, phone number, and
 * darkest secret of a contact.
 */
class Contact
{
	public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
	
	// member functions
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
		
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif  // CONTACT_HPP_

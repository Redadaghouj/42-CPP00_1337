/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:52:27 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/03 00:42:29 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
	_index++;
	_index %= PHONEBOOK_CAPACITY;
}

void Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName)
{
	_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickName() const
{
	return (_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

int Contact::getIndex()
{
	return (_index);
}

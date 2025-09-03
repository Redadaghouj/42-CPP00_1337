/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:52:27 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/03 02:03:55 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <string>
#include <sys/types.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int Contact::_index = -1;

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "Goodbye! 👋" << std::endl << std::endl;
}

Field	*initFields()
{
	static Field fields[]  = {
		{"- Enter your first name: ", &Contact::setFirstName},
		{"- Enter your last name: ", &Contact::setLastName},
		{"- Enter your nick name: ", &Contact::setNickName},
		{"- Enter your phone number: ", &Contact::setPhoneNumber},
		{"- Enter your darkest secret: ", &Contact::setDarkestSecret},
	};
	return (fields);
}

bool	isOnlyWhitespace(std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(input[i])))
			return (false);
	}
	return (true);
}

bool	promptAndSet(const std::string msg, SetterMethod setter, Contact& newContact)
{
	std::string input;

	while (true)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (!input.empty() && !isOnlyWhitespace(input))
		{
			(newContact.*setter)(input);
			break ;
		}
		else if (std::cin.eof())
			return (false);
		std::cout << "❌ This field cannot be empty. Please try again." << std::endl;
	}
	return (true);
}

void PhoneBook::addContact()
{
	Contact newContact;
	Field *fields;

	fields = initFields();
	for (int i = 0; i < NUM_FIELDS; i++)
	{
		if (!promptAndSet(fields[i].msg, fields[i].setter, newContact))
			return ;
	}
	_contacts[Contact::getIndex()] = newContact;
	std::cout << "✅ Contact added successfully.\n" << std::endl;
}

void displayHeader()
{
	const char HEADER[] = "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << SEPARATOR << HEADER << SEPARATOR;
}

void PhoneBook::displayContact(int& index)
{
	const int WIDTH = 10;

	std::cout
	<< "|" << std::setw(WIDTH) << std::right << index
	<< "|" << std::setw(WIDTH) << _contacts[index].getFirstName()
	<< "|" << std::setw(WIDTH) << _contacts[index].getLastName()
	<< "|" << std::setw(WIDTH) << _contacts[index].getNickName()
	<< "|" << std::endl;
	std::cout << SEPARATOR;
}

void PhoneBook::displayAllContacts()
{

	for (int i = 0; i < PHONEBOOK_CAPACITY; i++)
	{
		if (!_contacts[i].getFirstName().empty())
			displayContact(i);
	}

}

bool atoi(std::string &str, int &num)
{
	std::stringstream ss(str);

	if (ss.fail() || !std::cin.eof())
		return (false);
	ss >> num;
	return (true);
}

void PhoneBook::searchContact()
{
	std::string input;
	int index;

	displayHeader();
	displayAllContacts();
	std::cout << "Enter Index you search for: ";
	std::getline(std::cin, input);
	if (!atoi(input, index))
		std::cout << "not a num\n";
	else if (index < 0 || index > PHONEBOOK_CAPACITY)
		std::cout << "not in the range\n";
	else
	{
		displayHeader();
		displayContact(index);
	}
}

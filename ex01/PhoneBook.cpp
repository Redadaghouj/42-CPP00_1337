/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:52:27 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/03 15:35:37 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream>

int Contact::_index = -1;

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "\tGoodbye! 👋" << std::endl << std::endl;
}

Field	*initFields()
{
	static Field fields[]  = {
		{"🔹 Enter your first name\t:  ", &Contact::setFirstName},
		{"🔹 Enter your last name\t\t:  ", &Contact::setLastName},
		{"🔹 Enter your nickname\t\t:  ", &Contact::setNickName},
		{"🔹 Enter your phone number\t:  ", &Contact::setPhoneNumber},
		{"🔹 Enter your darkest secret\t:  ", &Contact::setDarkestSecret},
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

bool atoi(std::string &str, int &num)
{
	std::stringstream ss(str);

	ss >> num;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

bool isDigitsOnly(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<int>(str[i])))
			return (false);		
	}
	return (true);
}

bool promptAndSet(const std::string msg, SetterMethod setter, Contact& newContact)
{
	std::string input;

	while (true)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (!input.empty() && !isOnlyWhitespace(input))
		{
			if (msg.find("phone") != std::string::npos && !isDigitsOnly(input))
			{
				std::cout << "❌ Only digits are allowed. Please try again." << std::endl;
				continue ;
			}
			(newContact.*setter)(input);
			break ;
		}
		else if (std::cin.eof())
			return (false);
		std::cout << "\n❌ This field cannot be empty. Please try again." << std::endl;
	}
	return (true);
}

void PhoneBook::addContact()
{
	Contact newContact(0);
	Field *fields;

	fields = initFields();
	std::cout << std::endl;
	for (int i = 0; i < NUM_FIELDS; i++)
	{
		if (!promptAndSet(fields[i].msg, fields[i].setter, newContact))
			return ;
	}
	_contacts[Contact::getIndex()] = newContact;
	std::cout << "\n✅ Contact added successfully." << std::endl;
}

void displayHeader()
{
	std::cout
	<< SEPARATOR << std::right
	<< "|" << std::setw(COLUMNS_WIDTH) << "Index"
	<< "|" << std::setw(COLUMNS_WIDTH) << "First Name"
	<< "|" << std::setw(COLUMNS_WIDTH) << "Last Name"
	<< "|" << std::setw(COLUMNS_WIDTH) << "Nickname"
	<< "|" << std::endl << SEPARATOR;
}

std::string truncateWithDot(const std::string &str)
{
	if (str.length() > COLUMNS_WIDTH)
	{
		std::string tmp = str.substr(0, COLUMNS_WIDTH);
		tmp[COLUMNS_WIDTH - 1] = '.';
		return (tmp);
	}
	return (str);
}

void PhoneBook::displayContactRow(int index)
{
	std::cout
	<< std::right
	<< "|" << std::setw(COLUMNS_WIDTH) << index
	<< "|" << std::setw(COLUMNS_WIDTH) << truncateWithDot(_contacts[index].getFirstName())
	<< "|" << std::setw(COLUMNS_WIDTH) << truncateWithDot(_contacts[index].getLastName())
	<< "|" << std::setw(COLUMNS_WIDTH) << truncateWithDot(_contacts[index].getNickName())
	<< "|" << std::endl << SEPARATOR;
}

void PhoneBook::displayAllContacts()
{

	for (int i = 0; i < PHONEBOOK_CAPACITY; i++)
	{
		if (!_contacts[i].getFirstName().empty())
			displayContactRow(i);
	}
	std::cout << std::endl;
}

void printField(const std::string &label, const std::string &value)
{
    std::cout
	<< " 🔹 " << std::left << std::setw(COLUMNS_WIDTH * 2) << label << value
	<< std::endl;
}

void PhoneBook::displayContactDetails(int index)
{
    std::cout << std::endl;
    printField("First name:", _contacts[index].getFirstName());
    printField("Last name:", _contacts[index].getLastName());
    printField("Nickname:", _contacts[index].getNickName());
    printField("Phone number:", _contacts[index].getPhoneNumber());
    printField("Darkest secret:", _contacts[index].getDarkestSecret());
}

void PhoneBook::searchContact()
{
	std::string input;
	int index;

	displayHeader();
	if (Contact::getIndex() != -1)
	{
		displayAllContacts();
		std::cout << "➤ Enter Index you search for: ";
		std::getline(std::cin, input);
		if (!atoi(input, index))
			std::cout << "\n❌ Invalid input. Please enter a number." << std::endl;
		else if (index > Contact::getIndex() || index < 0 || index > PHONEBOOK_CAPACITY)
			std::cout << "\n❌ Number out of range. Please try again." << std::endl;
		else
			displayContactDetails(index);
	}
	else
		std::cout << "\n\t⚠️  CONTACT IS EMPTY." << std::endl;
}

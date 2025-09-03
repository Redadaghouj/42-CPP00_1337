/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:44:11 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/03 15:08:36 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

const int PHONEBOOK_CAPACITY = 8;
const int NUM_FIELDS = 5;
const int COLUMNS_WIDTH = 10;
const char SEPARATOR[] = "+----------+----------+----------+----------+\n";

typedef	void (Contact::*SetterMethod)(const std::string&);

struct Field
{
	const char *msg;
	SetterMethod setter;
};

class PhoneBook
{
	private:
		Contact	_contacts[PHONEBOOK_CAPACITY];
		
	public:
		~PhoneBook();
		void addContact();
		void searchContact();
		void displayAllContacts();
		void displayContactRow(int index);
		void displayContactDetails(int index);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:44:11 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/02 02:37:59 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PHONEBOOK_CAPACITY 8

class PhoneBook
{
	private:
		Contact	contacts[PHONEBOOK_CAPACITY];

	public:
		void addContact();
		void searchContact();
};

#endif
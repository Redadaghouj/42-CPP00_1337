/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:52:27 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/02 00:26:08 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecrect(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void)
{
	return (firstName);
}

std::string Contact::getLastName(void)
{
	return (lastName);
}

std::string Contact::getNickName(void)
{
	return (nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:52:27 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/02 21:18:09 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	printInvalidCommand(std::string &cmd)
{
	std::cout << "❌ Invalid command: '" << cmd
				<< "' Please type ADD, SEARCH, or EXIT." << std::endl;
}

void	clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

int main() 
{
	PhoneBook phoneBook;
	std::string cmd;

	while (!std::cin.eof())
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		clearScreen();
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT" || std::cin.eof())
			break ;
		else
			printInvalidCommand(cmd);
	}
	return (0);
}

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void	printInvalidCommand(const std::string &cmd)
{
	std::cout
	<< "\n❌ Invalid command: '" << cmd
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
		std::cout << "\n➤ Enter command (ADD, SEARCH, EXIT): ";
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

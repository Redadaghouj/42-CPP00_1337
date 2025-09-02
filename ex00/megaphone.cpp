/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redadgh <redadgh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:30:14 by redadgh           #+#    #+#             */
/*   Updated: 2025/09/02 02:41:32 by redadgh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

# define DEFAULT_PHRASE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	printUpperCase(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		std::cout << static_cast<char>(toupper(static_cast<unsigned char>(str[i])));
}

void	transformStrings(char **strings, int count)
{
	for (int i = 0; i < count; i++)
		printUpperCase(strings[i]);
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
		transformStrings(argv + 1, argc - 1);
	else
		std::cout << DEFAULT_PHRASE << std::endl;
	return (0);
}

#include <iostream>
#include <cctype>

void	printUpperCase(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		std::cout << static_cast<char>(toupper(static_cast<unsigned char>(str[i])));
}

void	transformStrings(char **strings, int count)
{
	for (int i = 0; i < count; i++)
	{
		printUpperCase(strings[i]);
		std::cout << (i + 1 < count ? " " : "");
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	const char DEFAULT_OUTPUT[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc > 1)
		transformStrings(argv + 1, argc - 1);
	else
		std::cout << DEFAULT_OUTPUT << std::endl;
	return (0);
}

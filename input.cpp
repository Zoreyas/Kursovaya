#include "input.h"
#include "text.h"


double inputNumber()
{
	double number;

	while (!(std::cin >> number) || (std::cin.get() != '\n'))
	{
		std::cout << ERROR_INPUT << std::endl;
		std::cin.clear();
		while (std::cin.get() != '\n');
	}

	return number;
}

char inputMenu(char top_edge, char bottom_edge)
{
	char input;
	while (true)
	{
		input = _getch();
		if ((input >= top_edge) && (input <= bottom_edge))
		{
			return input;
		}
	}
}
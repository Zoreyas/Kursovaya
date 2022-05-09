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

void inputBorders(double* left_border, double* right_border)
{
	std::cout << LINE_INPUT_LEFT_BORDER << std::endl;
	*left_border = inputNumber();
	std::cout << LINE_INPUT_RIGHT_BORDER << std::endl;
	*right_border = inputNumber();

	if (*left_border > *right_border)
	{
		double temp;
		temp = *left_border;
		*left_border = *right_border;
		*right_border = temp;
		std::cout << LINE_BORDERS_SWAPPED << std::endl;
	}
}
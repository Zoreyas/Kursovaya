#include "data.h"


std::vector<car> getCars()
{
	std::vector<car> cars;

	std::fstream data_file;
	data_file.open(FILE_NAME_DATA);
	car buffer;
	while (data_file
		>> buffer.type_of_car
		>> buffer.title
		>> buffer.capacity
		>> buffer.amount
		>> buffer.fuel_consumption
		>> buffer.price)
	{
		cars.push_back(buffer);
	}
	data_file.close();
	return cars;
}

void saveCars(std::vector<car> cars)
{
	std::fstream data_file;
	data_file.open(FILE_NAME_DATA, std::ifstream::out);

	for (int i = 0; i < cars.size(); i++)
	{
		data_file << cars.at(i).type_of_car << std::endl;
		data_file << cars.at(i).title << std::endl;
		data_file << cars.at(i).capacity << std::endl;
		data_file << cars.at(i).amount << std::endl;
		data_file << cars.at(i).fuel_consumption << std::endl;
		data_file << cars.at(i).price << std::endl;
	}

	data_file.close();
}

void viewData(std::vector<car>* cars)
{
	for (int i = 0; i < cars->size(); i++)
	{
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
	}
}

void addData(std::vector<car>* cars)
{
	car buffer;

	while (true)
	{
		std::cout << LINE_TITLE << std::endl;
		std::cin >> buffer.title;
		if (isTitleExist(cars, buffer.title) == false)
		{
			break;
		}
		else
		{
			std::cout << LINE_TITLE_ALREADY_EXIST << std::endl;
		}
	}
	std::cout << LINE_TYPE << std::endl;
	std::cin >> buffer.type_of_car;
	std::cout << LINE_PRICE << std::endl;
	buffer.price = inputNumber();
	std::cout << LINE_CAPACITY << std::endl;
	buffer.capacity = inputNumber();
	std::cout << LINE_FUEL_CONSUMPTION << std::endl;
	buffer.fuel_consumption = inputNumber();
	std::cout << LINE_AMOUNT << std::endl;
	buffer.amount = inputNumber();

	cars->push_back(buffer);
}

void deleteData(std::vector<car>* cars)
{
	std::string chos_title;
	int amount_of_deleted_cars;

	system("cls");
	viewData(cars);
	std::cout << LINE_INPUT_TITLE << std::endl;
	std::cin >> chos_title;

	if (isTitleExist(cars, chos_title) == true)
	{
		for (int i = 0; i < cars->size(); i++)
		{
			if (cars->at(i).title == chos_title)
			{
				std::cout << LINE_NUMBER_OF_DELETED_CARS << std::endl;
				amount_of_deleted_cars = inputNumber();
				if (cars->at(i).amount <= amount_of_deleted_cars)
				{
					cars->erase(cars->begin() + i);
				}
				else
				{
					cars->at(i).amount = cars->at(i).amount - amount_of_deleted_cars;
				}
			}
		}

		std::cout << LINE_DATA_DELETED << std::endl;
		_getch();
	}
	else
	{
		std::cout << ERROR_TITLE_DONT_EXIST << std::endl;
		_getch();
	}
}

bool isTitleExist(std::vector<car>* cars, std::string title)
{
	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			return true;
		}
	}

	return false;
}

void editData(std::vector<car>* cars)
{
	std::string chos_title;

	system("cls");
	viewData(cars);
	std::cout << LINE_INPUT_TITLE << std::endl;
	std::cin >> chos_title;

	if (isTitleExist(cars, chos_title) == true)
	{
		editOneRecord(cars, chos_title);
	}
	else
	{
		std::cout << ERROR_TITLE_DONT_EXIST << std::endl;
		_getch();
	}
}

void editOneRecord(std::vector<car>* cars, std::string title)
{
	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << LINE_ADMIN_DATA_EDIT_MENU_EDIT << std::endl;
			switch (_getch())
			{
			case '1':
				changeTitle(cars, title);
				break;
			case '2':
				changeType(cars, title);
				break;
			case '3':
				changeCapacity(cars, title);
				break;
			case '4':
				changeAmount(cars, title);
				break;
			case '5':
				changeFuelConsumption(cars, title);
				break;
			case '6':
				changePrice(cars, title);
				break;
			}
		}
	}
}

void changeTitle(std::vector<car>* cars, std::string title)
{
	std::string new_title;
	std::cout << LINE_INPUT_TITLE << std::endl;
	std::cin >> new_title;

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).title = new_title;
		}
	}
}

void changeType(std::vector<car>* cars, std::string title)
{
	std::string new_type;
	std::cout << LINE_INPUT_TYPE << std::endl;
	std::cin >> new_type;

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).type_of_car = new_type;
		}
	}
}

void changeCapacity(std::vector<car>* cars, std::string title)
{
	int new_capacity;
	std::cout << LINE_INPUT_CAPACITY << std::endl;
	new_capacity = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).capacity = new_capacity;
		}
	}
}

void changeFuelConsumption(std::vector<car>* cars, std::string title)
{
	int new_fuel_consumption;
	std::cout << LINE_INPUT_FUEL_CONSUMPTION << std::endl;
	new_fuel_consumption = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).fuel_consumption = new_fuel_consumption;
		}
	}
}

void changePrice(std::vector<car>* cars, std::string title)
{
	int new_price;
	std::cout << LINE_INPUT_PRICE << std::endl;
	new_price = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).price = new_price;
		}
	}
}

void changeAmount(std::vector<car>* cars, std::string title)
{
	int new_amount;
	std::cout << LINE_INPUT_AMOUNT << std::endl;
	new_amount = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (cars->at(i).title == title)
		{
			cars->at(i).amount = new_amount;
		}
	}
}

void getPrice(std::vector<car>* cars)
{
	double total_price = 0;
	for (int i = 0; i < cars->size(); i++)
	{
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_PRICE_PER_UNIT << cars->at(i).price << "||" << LINE_TOTAL_PRICE << cars->at(i).price * cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------" << std::endl;
		total_price += cars->at(i).price * cars->at(i).amount;
	}
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TOTAL_PRICE << total_price << "||\n------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void getCarViaCapacity(std::vector<car>* cars)
{
	double left_border, right_border;
	inputBorders(&left_border, &right_border);

	for (int i = 0; i < cars->size(); i++)
	{
		if ((cars->at(i).capacity >= left_border) && (cars->at(i).capacity <= right_border))
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchTitle(std::vector<car>* cars)
{
	std::string chos_title;
	std::cout << LINE_INPUT_TITLE << std::endl;
	std::cin >> chos_title;

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_title == cars->at(i).title)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchAmount(std::vector<car>* cars)
{
	int chos_amount;
	std::cout << LINE_INPUT_AMOUNT << std::endl;
	chos_amount = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_amount == cars->at(i).amount)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchCapacity(std::vector<car>* cars)
{
	int chos_capacity;
	std::cout << LINE_INPUT_CAPACITY << std::endl;
	chos_capacity = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_capacity == cars->at(i).capacity)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchFuelConsumption(std::vector<car>* cars)
{
	double chos_fuel_consumption;
	std::cout << LINE_INPUT_FUEL_CONSUMPTION << std::endl;
	chos_fuel_consumption = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_fuel_consumption == cars->at(i).fuel_consumption)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchType(std::vector<car>* cars)
{
	std::string chos_type;
	std::cout << LINE_INPUT_TYPE << std::endl;
	std::cin >> chos_type;

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_type == cars->at(i).type_of_car)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void searchPrice(std::vector<car>* cars)
{
	double chos_price;
	std::cout << LINE_INPUT_PRICE << std::endl;
	chos_price = inputNumber();

	for (int i = 0; i < cars->size(); i++)
	{
		if (chos_price == cars->at(i).price)
		{
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n||" << LINE_TITLE << cars->at(i).title << "||" << LINE_TYPE << cars->at(i).type_of_car << "||" << LINE_CAPACITY << cars->at(i).capacity << "||" << LINE_FUEL_CONSUMPTION << cars->at(i).fuel_consumption << "||" << LINE_PRICE << cars->at(i).price << "||" << LINE_AMOUNT << cars->at(i).amount << "||\n------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
}

void sortPrice(std::vector<car>* cars)
{
	car temp;

	for (int i = 0; i < cars->size(); i++)
	{
		for (int j = 0; j < cars->size() - 1; j++)
		{
			if (cars->at(j).price < cars->at(j + 1).price)
			{
				temp = cars->at(j);
				cars->at(j) = cars->at(j + 1);
				cars->at(j + 1) = temp;
			}
		}
	}
}

void sortAmount(std::vector<car>* cars)
{
	car temp;

	for (int i = 0; i < cars->size(); i++)
	{
		for (int j = 0; j < cars->size() - 1; j++)
		{
			if (cars->at(j).amount < cars->at(j + 1).amount)
			{
				temp = cars->at(j);
				cars->at(j) = cars->at(j + 1);
				cars->at(j + 1) = temp;
			}
		}
	}
}

void sortFuelConsumption(std::vector<car>* cars)
{
	car temp;

	for (int i = 0; i < cars->size(); i++)
	{
		for (int j = 0; j < cars->size() - 1; j++)
		{
			if (cars->at(j).fuel_consumption < cars->at(j + 1).fuel_consumption)
			{
				temp = cars->at(j);
				cars->at(j) = cars->at(j + 1);
				cars->at(j + 1) = temp;
			}
		}
	}
}

void sortCapacity(std::vector<car>* cars)
{
	car temp;

	for (int i = 0; i < cars->size(); i++)
	{
		for (int j = 0; j < cars->size() - 1; j++)
		{
			if (cars->at(j).capacity < cars->at(j + 1).capacity)
			{
				temp = cars->at(j);
				cars->at(j) = cars->at(j + 1);
				cars->at(j + 1) = temp;
			}
		}
	}
}
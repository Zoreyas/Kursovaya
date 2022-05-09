#include "GUI.h"


user* screenLogIn(std::vector<user>* accounts, int* flag_menu)
{
	user* current_account = NULL;

	system("cls");
	std::cout << LINE_LOG_IN_OR_REGISTER_MENU;

	switch (inputMenu('1', '3'))
	{
	case '1':
		current_account = logIn(*accounts);
		if (current_account != NULL)
		{
			*flag_menu = 2;
		}
		return current_account;
	case '2':
		accounts->push_back(registerAccount(*accounts));
		return NULL;
	case '3':
		*flag_menu = 0;
		return NULL;
	}
}

void screenAdmin(std::vector<user>* accounts, std::vector<car>* cars, int* flag_menu, user current_account)
{
	system("cls");
	std::cout << LINE_ADMIN_MENU << std::endl;
	switch (_getch())
	{
	case '1':
		screenAdminAccounts(accounts, current_account);
		break;
	case '2':
		screenAdminData(cars);
		break;
	case '3':
		*flag_menu = 1;
		break;
	}
}

void screenAdminAccounts(std::vector<user>* accounts, user current_account)
{
	bool flag = true;
	while (flag) {
		system("cls");
		std::cout << LINE_ADMIN_ACCOUNTS_MENU << std::endl;

		switch (_getch())
		{
		case '1':
			showAccounts(accounts);
			_getch();
			break;
		case '2':
			accounts->push_back(registerAccount(*accounts));
			break;
		case '3':
			editAccount(accounts, current_account);
			break;
		case '4':
			deleteAccount(accounts);
			break;
		case '5':
			flag = false;
			break;
		}
	}
}

void screenAdminData(std::vector<car>* cars)
{
	bool flag = true;
	while (flag) 
	{
		system("cls");
		std::cout << LINE_ADMIN_DATA_MENU << std::endl;

		switch (_getch())
		{
		case '1':
			screenAdminEditData(cars);
			break;
		case '2':
			screenViewData(cars);
			break;
		case '3':
			flag = false;
			break;
		}
	}
}

void screenAdminEditData(std::vector<car>* cars)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << LINE_ADMIN_DATA_EDIT_MENU << std::endl;

		switch (_getch())
		{
		case '1':
			system("cls");
			viewData(cars);
			_getch();
			break;
		case '2':
			system("cls");
			addData(cars);
			break;
		case '3':
			system("cls");
			deleteData(cars);
			break;
		case '4':
			system("cls");
			editData(cars);
		case '5':
			flag = false;
			break;
		}
	}
}

void screenViewData(std::vector<car>* cars)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << LINE_VIEW_DATA_MENU << std::endl;

		switch (_getch())
		{
		case '1':
			system("cls");
			viewData(cars);
			_getch();
			break;
		case '2':
			system("cls");
			getPrice(cars);
			_getch();
			break;
		case '3':
			system("cls");
			getCarViaCapacity(cars);
			_getch();
			break;
		case '4':
			system("cls");
			searchScreen(cars);
			break;
		case '5':
			system("cls");
			sortScreen(cars);
			break;
		case '6':
			flag = false;
			break;
		}
	}
}

void searchScreen(std::vector<car>* cars)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << LINE_SEARCH_SCREEN << std::endl;

		switch (_getch())
		{
		case '1':
			system("cls");
			searchTitle(cars);
			_getch();
			break;
		case '2':
			system("cls");
			searchCapacity(cars);
			_getch();
			break;
		case '3':
			system("cls");
			searchAmount(cars);
			_getch();
			break;
		case '4':
			system("cls");
			searchFuelConsumption(cars);
			_getch();
			break;
		case '5':
			system("cls");
			searchPrice(cars);
			_getch();
			break;
		case '6':
			system("cls");
			searchType(cars);
			_getch();
			break;
		case '7':
			flag = false;
			break;
		}
	}
}

void sortScreen(std::vector<car>* cars)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << LINE_SORT_SCREEN << std::endl;

		switch (_getch())
		{
		case '1':
			system("cls");
			sortCapacity(cars);
			viewData(cars);
			_getch();
			break;
		case '2':
			system("cls");
			sortPrice(cars);
			viewData(cars);
			_getch();
			break;
		case '3':
			system("cls");
			sortFuelConsumption(cars);
			viewData(cars);
			_getch();
			break;
		case '4':
			system("cls");
			sortAmount(cars);
			viewData(cars);
			_getch();
			break;
		case '5':
			flag = false;
			break;
		}
	}
}
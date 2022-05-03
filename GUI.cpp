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

void screenAdmin(std::vector<user>* accounts, std::vector<car>* cars, int* flag_menu)
{
	system("cls");
	std::cout << LINE_ADMIN_MENU << std::endl;
	switch (_getch())
	{
	case '1':
		screenAdminAccounts(accounts);
		break;
	case '2':
		screenAdminData(cars);
		break;
	case '3':
		*flag_menu = 1;
		break;
	}
}

void screenAdminAccounts(std::vector<user>* accounts)
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
			editAccount(accounts);
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
		std::cout<<
	}
}
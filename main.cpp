#include "GUI.h"


int main()
{
	std::vector<user> accounts;
	int flag_menu = 1;
	user* current_account = NULL;
	accounts = getAccounts();
	
	while (flag_menu == 1)
	{
		system("cls");
		std::cout << LINE_LOG_IN_OR_REGISTER;
		switch (inputMenu('1', '3'))
		{
		case '1':
			current_account = logIn(accounts);
			if (current_account != NULL)
			{
				flag_menu = 2;
			}	
			break;
		case '2':
			accounts.push_back(registerAccount(accounts));
			break;
		case '3':
			flag_menu = 0;

			break;
		}
	}

	saveAccounts(accounts);
	return 0;
}
#include "GUI.h"


int main()
{
	std::vector<user> accounts;
	std::vector<car> cars;
	int flag_menu = 1;
	user* current_account = NULL;

	accounts = getAccounts();
	cars = getCars();

	while (true)
	{

		if (flag_menu == 0)
		{
			saveAccounts(accounts);
			saveCars(cars);
			delete current_account;
			return 0;
		}

		while (flag_menu == 1)
		{
			current_account = screenLogIn(&accounts, &flag_menu);
		}

		while (flag_menu == 2)
		{
			system("cls");

			if (current_account->approved == 0)
			{
				std::cout << LINE_NOT_APPROVED_USER << std::endl;
				_getch();
				flag_menu = 1;
			}
			else
			{
				if (current_account->admin == 1)
				{
					screenAdmin(&accounts, &cars, &flag_menu, *current_account);
				}
				else
				{
					screenViewData(&cars);
				}
			}
		}
	}
}
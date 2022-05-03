#include "accounts.h"


std::vector<user> getAccounts()
{
	std::vector<user> accounts;

	std::fstream account_file;
	account_file.open(FILE_NAME_ACCOUNTS);
	user buffer;
	while (account_file
		>> buffer.admin
		>> buffer.approved
		>> buffer.login
		>> buffer.hash_from_password_with_salt
		>> buffer.salt)
	{
		accounts.push_back(buffer);
	}
	account_file.close();
	return accounts;
}

user registerAccount(std::vector<user> accounts)
{
	std::string login, password, salt, hash;
	user* new_account = new user;

	while (true)
	{
		system("cls");
		std::cout << "Create new account" << std::endl;
		std::cout << "Login:";
		std::cin >> login;
		if (isLoginExist(accounts, login) == false)
		{
			std::cout << "Password:";
			std::cin >> password;
			salt = generateSalt(SALT_SIZE);
			hash = sha256(sha256(password + salt) + sha256(password));
			
			new_account->admin = false;
			new_account->approved = false;
			new_account->hash_from_password_with_salt = hash;
			new_account->login = login;
			new_account->salt = salt;
	
			std::cout << "Account created" << std::endl;
			_getch();
			return *new_account;
		}
		else
		{
			std::cout << "This login already exist. Try another";
			_getch();
		}
	}
}

void saveAccounts(std::vector<user> accounts)
{
	std::fstream account_file;
	account_file.open(FILE_NAME_ACCOUNTS, std::ifstream::out);

	for (int i = 0; i < accounts.size(); i++)
	{
		account_file << accounts.at(i).admin << std::endl;
		account_file << accounts.at(i).approved << std::endl;
		account_file << accounts.at(i).login << std::endl;
		account_file << accounts.at(i).hash_from_password_with_salt << std::endl;
		account_file << accounts.at(i).salt << std::endl;
	}
	account_file.close();
}

user* logIn(std::vector<user> accounts)
{
	std::string login, password;

	system("cls");
	std::cout << LINE_LOGIN;
	std::cin >> login;
	std::cout << LINE_PASSWORD;
	std::cin >> password;
	
	if (isLoginExist(accounts, login) == true)
	{
		if (isPasswordFit(accounts, login, password) == true)
		{
			return getAccount(accounts, login);
		}
	}

	std::cout << ERROR_LOG_IN;
	_getch();

	return NULL;
}

bool isLoginExist(std::vector<user> accounts, std::string login)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i).login == login)
		{
			return true;
		}
	}
	return false;
}

bool isPasswordFit(std::vector<user> accounts, std::string login, std::string password)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i).login == login)
		{
			std::string input_hash = sha256(sha256(password + accounts.at(i).salt) + sha256(password));
			if (input_hash == accounts.at(i).hash_from_password_with_salt)
			{
				return true;
			}
		}
	}
	
	return false;
}

std::string generateSalt(int salt_size)
{
	std::string symbols = getSymbolsForSalt();

	srand(time(NULL));

	std::string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
	{
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}

	return salt;
}

std::string getSymbolsForSalt()
{
	std::string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++)
	{
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}

user* getAccount(std::vector<user> accounts, std::string login)
{
	user* usr = new user;

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i).login == login)
		{
			*usr = accounts.at(i);
			return usr;
		}
	}
}

void showAccounts(std::vector<user>* accounts)
{
	system("cls");

	for (int i = 0; i < accounts->size(); i++)
	{
		std::cout << "----------------------------------------\n||" << accounts->at(i).login;

		if (accounts->at(i).admin == true)
		{
			std::cout << "||admin";
		}
		else
		{
			std::cout << "||user";
		}

		if (accounts->at(i).approved == true)
		{
			std::cout << "||approved||\n";
		}
		else
		{
			std::cout << "||not approved||\n";
		}

		std::cout << "----------------------------------------\n";
	}
}

void editAccount(std::vector<user>* accounts)
{
	showAccounts(accounts);
	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_CHOOSE << std::endl;
	std::string chos_login;
	std::cin >> chos_login;

	if (isLoginExist(*accounts, chos_login) == true)
	{
		editOneAccount(getAccount(*accounts, chos_login), accounts);
	}
	else
	{
		std::cout << ERROR_LOGIN_DONT_EXIST << std::endl;
		_getch();
	}
}

void editOneAccount(user* account, std::vector<user>* accounts)
{
	system("cls");
	std::cout << "----------------------------------------\n||" << account->login;

	if (account->admin == true)
	{
		std::cout << "||admin";
	}
	else
	{
		std::cout << "||user";
	}

	if (account->approved == true)
	{
		std::cout << "||approved||\n";
	}
	else
	{
		std::cout << "||not approved||\n";
	}

	std::cout << "----------------------------------------\n";

	std::cout << LINE_ADMIN_ACCOUNTS_EDIT << std::endl;
	switch (_getch())
	{
	case '1':
		changeLogin(account->login, accounts);
		break;
	case '2':
		changeApprove(account->login, accounts);
		break;
	case '3':
		changeAdmin(account->login, accounts);
		break;
	}
}

void changeLogin(std::string login, std::vector<user>* accounts)
{
	std::string new_login;
	
	system("cls");

	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_LOGIN << std::endl;
	std::cin >> new_login;

	for (int i = 0; i < accounts->size(); i++)
	{
		if (accounts->at(i).login == login)
		{
			accounts->at(i).login = new_login;
		}
	}
	
	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_LOGIN_CHANGED << std::endl;
	_getch();
}

void changeApprove(std::string login, std::vector<user>* accounts)
{
	system("cls");

	for (int i = 0; i < accounts->size(); i++)
	{
		if (accounts->at(i).login == login)
		{
			if (accounts->at(i).approved == 0)
			{
				accounts->at(i).approved = 1;
			}
			else
			{
				accounts->at(i).approved = 0;
			}
		}
	}

	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_APPROVE_CHANGED << std::endl;
	_getch();
}

void changeAdmin(std::string login, std::vector<user>* accounts)
{
	system("cls");

	for (int i = 0; i < accounts->size(); i++)
	{
		if (accounts->at(i).login == login)
		{
			if (accounts->at(i).admin == 0)
			{
				accounts->at(i).admin = 1;
			}
			else
			{
				accounts->at(i).admin = 0;
			}
		}
	}

	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_ADMIN_CHANGED << std::endl;
	_getch();
}

void deleteAccount(std::vector<user>* accounts)
{
	system("cls");
	showAccounts(accounts);
	std::cout << LINE_ADMIN_ACCOUNTS_EDIT_CHOOSE << std::endl;
	std::string chos_login;
	std::cin >> chos_login;
	if (isLoginExist(*accounts, chos_login) == true)
	{
		for (int i = 0; i < accounts->size(); i++)
		{
			if (accounts->at(i).login == chos_login)
			{
				accounts->erase(accounts->begin() + i);
			}
		}
		
		std::cout << LINE_ADMIN_ACCOUNTS_DELETED << std::endl;
		_getch();
	}
	else
	{
		std::cout << ERROR_LOGIN_DONT_EXIST << std::endl;
		_getch();
	}
}
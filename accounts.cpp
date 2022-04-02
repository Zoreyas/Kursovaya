#include "accounts.h"


std::vector<user> getAccounts()
{
	std::vector<user> accounts;

	std::fstream account_file;
	account_file.open(FILE_NAME_ACCOUNTS);
	user buffer;
	while (account_file
		>> buffer.login
		>> buffer.hash_from_password_with_salt
		>> buffer.salt
		>> buffer.admin
		>> buffer.approved)
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
	account_file.open(FILE_NAME_ACCOUNTS);

	for (int i = 0; i < accounts.size(); i++)
	{
		account_file << accounts.at(i).login << std::endl;
		account_file << accounts.at(i).hash_from_password_with_salt << std::endl;
		account_file << accounts.at(i).salt << std::endl;
		account_file << accounts.at(i).admin << std::endl;
		account_file << accounts.at(i).approved << std::endl;
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
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts.at(i).login == login)
		{
			return &accounts.at(i);
		}
	}
}
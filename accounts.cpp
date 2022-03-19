#include "accounts.h";


std::vector<user> getAccounts()
{
	std::vector<user> accounts;

	std::fstream account_file;
	account_file.open(FILE_NAME_ACCOUNTS);
	user buffer;
	while (!(account_file.eof()))
	{
		account_file >> buffer.login;
		account_file >> buffer.hash_from_password_with_salt;
		account_file >> buffer.salt;
		account_file >> buffer.admin;
		account_file >> buffer.approved;
		accounts.push_back(buffer);
	}
	account_file.close();
	return accounts;
}

void registerAccount(std::vector<user> accounts)
{

}

void saveAccounts(std::vector<user> accounts)
{
	std::fstream account_file;
	account_file.open(FILE_NAME_ACCOUNTS);
	for (int i = 0; i < accounts.size(); i++)
	{
		account_file << accounts.at(i).login;
		account_file << accounts.at(i).hash_from_password_with_salt;
		account_file << accounts.at(i).salt;
		account_file << accounts.at(i).admin;
		account_file << accounts.at(i).approved;
	}
	account_file.close();
}
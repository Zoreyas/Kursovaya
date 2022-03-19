#pragma once


#include <iostream>;
#include <vector>;
#include <fstream>;
#include "text.h";


struct user
{
	std::string login; // User login
	double hash_from_password_with_salt; // Hash received from password + salt
	std::string salt; // Unique combination that should be combined with password
	bool admin; // true = admin 
				// false = usual user
	bool approved; // true = approved
				   // false = not approved
};


std::vector<user> getAccounts(); // Receiving accounts data

void registerAccount(std::vector<user>); // Create new account

void saveAccounts(std::vector<user>); // Write accounts data in file
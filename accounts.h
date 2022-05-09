#pragma once


#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include "text.h"
#include "sha256.h"


struct user
{
	std::string login; // User login
	std::string hash_from_password_with_salt; // Hash received from password + salt
	std::string salt; // Unique combination that should be combined with password
	int admin; // 1 = admin 
			   // 0 = usual user
	int approved; // 1 = approved
				  // 0 = not approved
};


std::vector<user> getAccounts(); // Receiving accounts data

user registerAccount(std::vector<user>); // Create new account

void saveAccounts(std::vector<user>); // Write accounts data in file

user* logIn(std::vector<user>); // Logging in to account

bool isLoginExist(std::vector<user>, std::string); // Check if login exist

bool isPasswordFit(std::vector<user>, std::string, std::string); // Check if password is correct

user* getAccount(std::vector<user>, std::string); // Get account via login

std::string generateSalt(int); // Genearate salt for password

std::string getSymbolsForSalt(); // Generate symbols for salt

void showAccounts(std::vector<user>*); // Show all accounts

void editAccount(std::vector<user>*, user); // Choose account to edit

void editOneAccount(user*, std::vector<user>*); // Edit account

void changeLogin(std::string, std::vector<user>*); // Change account login

void changeApprove(std::string, std::vector<user>*); // Change account approve

void changeAdmin(std::string, std::vector<user>*); // Change account admin status

void deleteAccount(std::vector<user>*); // Delete one account

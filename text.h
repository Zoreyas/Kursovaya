#pragma once


#include <string>
#include "input.h"


const std::string ERROR_INPUT = "Invalid input"; 
const std::string ERROR_LOG_IN = "Incorrect login or password";
const std::string ERROR_LOGIN_DONT_EXIST = "Login doesn't exist";
const std::string ERROR_TITLE_DONT_EXIST = "Title doesn't exist";

const std::string LINE_LOG_IN_OR_REGISTER_MENU = "1) Log in\n2) Create account\n3) Exit";
const std::string LINE_LOGIN = "Login:";
const std::string LINE_PASSWORD = "Password:";
const std::string LINE_NOT_APPROVED_USER = "Your account isn't approved yet";
const std::string LINE_USER_MENU = "1)";
const std::string LINE_ADMIN_MENU = "1) Accounts\n2) Data\n3) Back";
const std::string LINE_ADMIN_ACCOUNTS_MENU = "1) Show accounts\n2) Add account\n3) Edit account\n4) Delete account\n5) Back";
const std::string LINE_ADMIN_ACCOUNTS_EDIT_CHOOSE = "Choose account";
const std::string LINE_ADMIN_ACCOUNTS_EDIT = "1) Change login\n2) Change approve status\n3) Change admin status";
const std::string LINE_ADMIN_ACCOUNTS_EDIT_LOGIN = "Input new login";
const std::string LINE_ADMIN_ACCOUNTS_EDIT_LOGIN_CHANGED = "Login changed";
const std::string LINE_ADMIN_ACCOUNTS_EDIT_APPROVE_CHANGED = "Approve changed";
const std::string LINE_ADMIN_ACCOUNTS_EDIT_ADMIN_CHANGED = "Admin changed";
const std::string LINE_ADMIN_ACCOUNTS_DELETED = "Account removed";
const std::string LINE_ADMIN_DATA_MENU = "1) Edit data\n2) View data\n3) Back";
const std::string LINE_ADMIN_DATA_EDIT_MENU = "1) View data\n2) Add new car\n3) Delete car\n4) Edit car\n5) Back";
const std::string LINE_TITLE = "Title:";
const std::string LINE_TYPE = "Type:";
const std::string LINE_CAPACITY = "Capacity:";
const std::string LINE_FUEL_CONSUMPTION = "Fuel consumption:";
const std::string LINE_PRICE = "Price:";
const std::string LINE_AMOUNT = "Amount:";
const std::string LINE_TITLE_ALREADY_EXIST = "Title already exist";
const std::string LINE_INPUT_TITLE = "Input title";
const std::string LINE_NUMBER_OF_DELETED_CARS = "How many cars should be deleted";
const std::string LINE_DATA_DELETED = "Cars deleted";
const std::string LINE_ADMIN_DATA_EDIT_MENU_EDIT = "1) Change title\n2) Change type\n3) Change capacity\n4) Change amount\n5) Change fuel capacity\n6) Change price";
const std::string LINE_INPUT_TYPE = "Input type";
const std::string LINE_INPUT_CAPACITY = "Input capacity";
const std::string LINE_INPUT_AMOUNT = "Input amount";
const std::string LINE_INPUT_FUEL_CONSUMPTION = "Input fuel consumption";
const std::string LINE_INPUT_PRICE = "Input price";
const std::string LINE_VIEW_DATA_MENU = "1) View data\n2)";

const std::string FILE_NAME_ACCOUNTS = "Accounts.txt";
const std::string FILE_NAME_DATA = "Data.txt";

const int SALT_SIZE = 16;
const int SYMBOLS_SIZE = 32;
#pragma once


#include "input.h"
#include "accounts.h"
#include "data.h"


user* screenLogIn(std::vector<user>*, int*); // Log in screen

void screenAdmin(std::vector<user>*, std::vector<car>*, int*, user); // Admin screen (work with accounts or with data)

void screenAdminAccounts(std::vector<user>*, user); // Admin screen (work with accounts)

void screenAdminData(std::vector<car>*); // Admin screen (work with data)

void screenAdminEditData(std::vector<car>*); // Admin data edit mode

void screenViewData(std::vector<car>*); // Data view mode

void searchScreen(std::vector<car>*); // Screen to choose type of searching

void sortScreen(std::vector<car>*); // Screen to choose type of sorting
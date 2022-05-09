#pragma once


#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include "text.h"


struct car
{
	std::string type_of_car;
	int capacity;
	int amount;
	double fuel_consumption;
	double price;
	std::string title;
};


std::vector<car> getCars(); // Get cars data from file

void saveCars(std::vector<car>); // Save cars data in file

void viewData(std::vector<car>*); // View all data

void addData(std::vector<car>*); // Add new record

void deleteData(std::vector<car>*); // Delete record

bool isTitleExist(std::vector<car>*, std::string); // Check if title already exist

void editData(std::vector<car>*); // Data edit screen

void editOneRecord(std::vector<car>*, std::string); // Edit record

void changeTitle(std::vector<car>*, std::string); // Change title

void changeType(std::vector<car>*, std::string); // Change type

void changeCapacity(std::vector<car>*, std::string); // Change capacity

void changeFuelConsumption(std::vector<car>*, std::string); // Change fuel consumption

void changePrice(std::vector<car>*, std::string); // Change price

void changeAmount(std::vector<car>*, std::string); // Change amount

void getPrice(std::vector<car>*); // Get total price of cars

void getCarViaCapacity(std::vector<car>*); // Find cars with selected capacity

void searchTitle(std::vector<car>*); // Find cars via title

void searchCapacity(std::vector<car>*); // Find cars via capacity

void searchFuelConsumption(std::vector<car>*); // Find cars via fuel consumption

void searchType(std::vector<car>*); // Find cars via type

void searchPrice(std::vector<car>*); // Find cars via price

void searchAmount(std::vector<car>*); // Find cars via amount

void sortAmount(std::vector<car>*); // Sort cars by amount

void sortFuelConsumption(std::vector<car>*); // Sort cars by fuel consumption

void sortPrice(std::vector<car>*); // Sort cars by price

void sortCapacity(std::vector<car>*); // Sort cars by capacity
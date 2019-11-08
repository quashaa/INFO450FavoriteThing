#pragma once
#include <iostream>
#include <string>
#include "Restaurant.h"
using namespace std;

class RestaurantList
{
	Restaurant *restaurants = new Restaurant[100];
	int numRestaurants;
public:
	RestaurantList();
	void AddRestaurant();
	void deleteRestaurant(string unwanted);
	void showRestaurants();
	bool isValidName(string n);
};
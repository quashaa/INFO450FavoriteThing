#include <iostream>
#include <string>
#include "Restaurant.h"
#include "RestaurantList.h"
using namespace std;

// Constructor
RestaurantList::RestaurantList()
{
	numRestaurants = 0;
}

// Gets restaurants and validates it's not a duplcate
void RestaurantList::AddRestaurant()
{
	bool capture = true;
	string currentRestaurant;

	restaurants[numRestaurants].getRestaurant();

	while (capture == true)
	{

		if (numRestaurants == 0)
		{
			break;
		}

		for (int i = 0; i < numRestaurants; i++)
		{
			if (restaurants[i].name != restaurants[numRestaurants].name)
			{
				capture = false;
			}
			else {

				cout << "\nYou have already added a restaurant with this name!" << endl;
				numRestaurants--;
				break;
			}
		}
	}
	numRestaurants++;
}

// Verifies unwanted restaurants exists in array
bool RestaurantList::isValidName(string n)
{
	for (int i = 0; i < numRestaurants; i++)
	{
		bool check = (restaurants[i].name == n);

		if (check == true)
		{
			return true;
		}
		else if (i == (numRestaurants - 1))
		{
			return false;

		}
	}
}

// Deletes restaurant from array
void RestaurantList::deleteRestaurant(string unwanted)
{
	char answer = 'y';
	int index = 0, length = 0;
	string newUnwanted = "";

	if (isValidName(unwanted))
	{
		for (int i = 0; i < numRestaurants; i++)
		{
			if (restaurants[i].name == unwanted)
			{
				int deleteIndex = i;

				length = numRestaurants - 1;

				for (index = 0; index < length; index++)
				{
					if (index >= deleteIndex)
					{
						restaurants[index] = restaurants[index + 1];
					}
				}
				break;
			}
		}

		numRestaurants--;
	}
	else
	{

		newUnwanted = unwanted;

		while (isValidName(newUnwanted) == false)
		{
			cout << "\n(Error: This restaurant has not been entered)" << endl;
			cout << "\nPlease enter a valid Resaurant: ";
			getline(cin, newUnwanted);
		}

		for (int i = 0; i < numRestaurants; i++)
		{
			if (restaurants[i].name == newUnwanted)
			{
				int deleteIndex = i;

				length = numRestaurants - 1;

				for (index = 0; index < length; index++)
				{
					if (index >= deleteIndex)
					{
						restaurants[index] = restaurants[index + 1];
					}
				}
				break;
			}
		}
		numRestaurants--;
	}
}

void RestaurantList::showRestaurants()
{
	int i;

	for (i = 0; i < numRestaurants; i++)
	{
		cout << restaurants[i];
	}
}

#include <iostream>
#include <string>
#include "Restaurant.h"
#include"RestaurantList.h"

using namespace std;

int main()
{
	cout << "*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       Welcome To      ***" << endl;
	cout << "***  Restaurant Tracker!  ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***   This app will show  ***" << endl;
	cout << "***   you a list of all   ***" << endl;
	cout << "***   of your favorite    ***" << endl;
	cout << "***     restaurants!      ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***  Each restaurant will ***" << endl;
	cout << "***  need the following:  ***" << endl;
	cout << "***     - Name            ***" << endl;
	cout << "***     - Location        ***" << endl;
	cout << "***     - Rating          ***" << endl;
	cout << "***     - Favorite Item   ***" << endl;
	cout << "***     - Item Price      ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***" << endl;
	cout << endl;

	system("pause");
	system("CLS");

	char answer = 'Y';
	RestaurantList favRestaurants;

	// Loops to gather multiple list items
	while (answer == 'y' || answer == 'Y')
	{
		favRestaurants.AddRestaurant();

		cout << "\nWould you like to add another favorite restaurant? ";
		cin >> answer;
		cin.ignore();
	}
	
	// Displays all Restaurant Items
	favRestaurants.showRestaurants();

	cout << "\nWould you like to remove a restaurant from your list? ";
	cin >> answer;
	cin.ignore();

	// Gets name of the Restaurant to be deleted
	while (answer == 'y' || answer == 'Y')
	{
		string unwanted = "";

		cout << "\nPlease Enter name of the restaurant you would like to delete: ";
		getline(cin, unwanted);

		favRestaurants.deleteRestaurant(unwanted);

		cout << "\nYour new and improved list of restaurants is below:\n" << endl;
		favRestaurants.showRestaurants();

		cout << "\nWould you like to remove another restaurant from your list? ";
		cin >> answer;
		cin.ignore();
	}

	cout << "\n\n*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       GOOD BYE        ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***\n\n" << endl;	
	
	system("pause");
	return 0;
}
// Mahala Covey
// CIS 1202 800
// March 29, 2024

// Driver for the Publication class.
#include <iostream>
#include <fstream>
#include "Publication.h"
using namespace std;

// Function prototypes
void getPublicationInfo(Publication&);
void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

int main()
{
	const int SIZE = 50; // Maximum array capacity
	Publication publicationData[SIZE]; // Array of Publication objects
	int count = 0; // Holds count of Publication objects in file
	int choiceMade; // User's menu choice
	string searchTitle; // Title user wants to search for

	// Call getPublications
	getPublications(publicationData, count);

	// Handle menu choice
	do
	{
		choiceMade = getMenuChoice();

		switch (choiceMade)
		{
		case 1: // Display all publications
			showPublications(publicationData, count);
			break;

		case 2: // Display publication titles
			showTitles(publicationData, count);
			break;

		case 3: // Find a publication
			cin.ignore(); // Ignore newline character
			cout << "Publication name? "; // Prompt for title
			getline(cin, searchTitle);
			if (findPublication(publicationData, count, searchTitle) != -1)
			{
				publicationData[findPublication(publicationData, count, searchTitle)].displayInfo(); // Call displayInfo
				cout << endl;
			}
			else
			{
				cout << searchTitle << " was not found." << endl;
			}
			break;

		case 4: // Check out
			cin.ignore(); // Ignore newline character
			cout << "Publication name? "; // Prompt for title
			getline(cin, searchTitle);
			if (findPublication(publicationData, count, searchTitle) != -1)
			{
				if (publicationData[findPublication(publicationData, count, searchTitle)].getStock() > 0)
				{
					publicationData[findPublication(publicationData, count, searchTitle)].checkOut(); // Call checkOut
				}
				else
				{
					cout << "There are no copies of " << searchTitle << " to check out." << endl;
				}
			}
			else
			{
				cout << searchTitle << " was not found." << endl;
			}
			break;

		case 5: // Check in
			cin.ignore(); // Ignore newline character
			cout << "Publication name? "; // Prompt for title
			getline(cin, searchTitle);
			if (findPublication(publicationData, count, searchTitle) != -1)
			{
				publicationData[findPublication(publicationData, count, searchTitle)].checkIn(); // Call checkIn
			}
			else
			{
				cout << searchTitle << " was not found." << endl;
			}
			break;
		}
	} while (choiceMade != 6);

	return 0;
}

//***********************************************************************************************************************************************************
// getPublicationInfo asks the user for publication information and stores it in the referenced Publication object parameter p by calling storePublication. *
//***********************************************************************************************************************************************************

void getPublicationInfo(Publication& p)
{
	// Variables to hold Publication members
	string pTitle = "";
	string pPublisher = "";
	float pPrice = 0;
	int pYear = 0;
	int iType; // To hold int type that will be assigned PublicationType pType
	PublicationType pType;
	int pStock = 0;

	// Prompt for and get input 
	cout << "Title: ";
	getline(cin, pTitle);
	cout << "Publisher: ";
	getline(cin, pPublisher);
	cout << "Price: ";
	cin >> pPrice;
	cout << "Year: ";
	cin >> pYear;
	cout << "1. Book / 2. Magazine / 3. Newspaper / 4. Audio / 5. Video" << endl;
	cout << "Type: ";
	cin >> iType;
	pType = static_cast<PublicationType>(iType - 1);
	cout << "Stock: ";
	cin >> pStock;

	p.storePublication(pTitle, pPublisher, pPrice, pYear, pType, pStock);
}

void getPublications(Publication list[], int& i)
{
	fstream file; // File stream object
	// Variables to hold Publication members
	string pTitle;
	string pPublisher;
	float pPrice;
	int pYear;
	int iType; // To hold int type that will be assigned PublicationType pType
	PublicationType pType; 
	int pStock;

	// Open file in input/reading mode
	file.open("11publications.txt", ios::in);

	// If file is successfully opened, load data into array
	if (file)
	{	
		while (getline(file, pTitle))
		{
			getline(file, pPublisher);
			file >> pPrice >> pYear >> iType >> pStock; 
			pType = static_cast<PublicationType>(iType); // Cast int to PublicationType for type member
			list[i].storePublication(pTitle, pPublisher, pPrice, pYear, pType, pStock);
			i++;

			file.ignore(4, '\n'); // Skip newline characters in file
		}
		// Close file
		file.close();
	}
	else
		cout << "Error opening the file..." << endl;
}

void showPublications(Publication list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		list[i].displayInfo();
		cout << endl;
	}
}

void showTitles(Publication list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << list[i].getTitle();
		cout << endl;
	}
}

int findPublication(Publication list[], int count, string search)
{
	for (int i = 0; i < count; i++)
	{
		if (list[i].getTitle() == search)
		{
			return i; // Returns position if match found
		}
	}

	return -1; // Returns sentinal if match not found
}

//***************************************************************************************
// getMenuChoice displays the menu and returns the user's menu choice once it is valid. *
//***************************************************************************************

int getMenuChoice()
{
	int choice; // Holds user's menu choice

	// Display the menu
	cout << "1. Display all publications" << endl
		<< "2. Display all publication titles" << endl
		<< "3. Find a publication" << endl
		<< "4. Check out" << endl
		<< "5. Check in" << endl
		<< "6. Exit" << endl;

	// Get menu choice
	cin >> choice;

	while (choice < 1 || choice > 6)
	{
		cout << "Invalid choice. Please enter a number 1-7: ";
		cin >> choice;
	}

	return choice;
}
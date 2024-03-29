// Mahala Covey
// CIS 1202 800
// March 20, 2024

// Implementation file for the Publication class.
#include "Publication.h"
#include <iostream>
using namespace std;

//**************************************************************
// storePublication sets the value of the Publication members. *
//**************************************************************

void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = static_cast<float>(itemPrice);
	year = itemYear;
	type = itemType;
	stock = itemStock;
}

//***********************************************************
// displayInfo prints all of the Publication member values. *
//***********************************************************

void Publication::displayInfo()
{
	cout << title << endl;
	cout << publisher << endl;
	cout << "$ " << price << endl;
	cout << year << endl;
	switch (type)
	{
	case BOOK: cout << "Book";
		break;
	case MAGAZINE: cout << "Magazine";
		break;
	case NEWSPAPER: cout << "Newspaper";
		break;
	case AUDIO: cout << "Audio";
		break;
	case VIDEO: cout << "Video";
	}
	cout << endl;
	cout << stock << " in stock";
}

//**************************************************************************
// checkOut decrements the member variable stock by one if it is not zero. *
//**************************************************************************

void Publication::checkOut()
{
	if (stock != 0)
		stock--;
}

//*******************************************************
// checkIn increments the member variable stock by one. *
//*******************************************************

void Publication::checkIn()
{
	stock++;
}

//***********************************************************
// getTitle returns the value in the member variable title. *
//***********************************************************

string Publication::getTitle() const
{
	return title;
}

//***********************************************************
// getStock returns the value in the member variable stock. *
//***********************************************************

int Publication::getStock() const
{
	return stock;
}
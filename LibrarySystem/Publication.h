// Mahala Covey
// CIS 1202 800
// March 20, 2024

// Specification file for the Publication class.
#include <string>
#ifndef PUBLICATION_H
#define PUBLICATION_H
using namespace std;

// Enumerator definitonf for different publication types
enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication
{
	// Member variables
private:
	string title;
	string publisher;
	float price;
	int year;
	PublicationType type;
	int stock;
	// Member functions
public:
	void storePublication(string, string, double, int, PublicationType, int);
	void displayInfo();
	void checkOut();
	void checkIn();
	string getTitle() const;
	int getStock() const;
};
#endif
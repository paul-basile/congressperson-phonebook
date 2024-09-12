#include <iostream>
#include "CongressPerson.h"
class PhoneBook {
public:
	PhoneBook();
	PhoneBook(const PhoneBook& orig);
	PhoneBook& operator=(const PhoneBook& orig);
	~PhoneBook();

	int getSize() { return size; }
	void searchNum(string phone);
	void addPerson(CongressPerson congressPerson);
	void display() const;
	void sort();

private:
	CongressPerson* congressPersonList;
	int size;
	int capacity;

	template <typename TypeVal>
	int binarySearch(int lowVal, int highVal, TypeVal phoneMatch);
};

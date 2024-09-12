#include <iostream>
#include <string>
#include <vector>
#include "PhoneBook.h"
using namespace std;

PhoneBook::PhoneBook() {
		capacity = 20;
		congressPersonList = new CongressPerson[capacity];
		size = 0;
}

PhoneBook::PhoneBook(const PhoneBook& orig) {
	cout << "Copy constructor called" << endl;

	//gives original size and capacity values to size and capacity
	this->size = orig.size;
	this->capacity = orig.capacity;

	//creates personList with new capacity
	this->congressPersonList = new CongressPerson[orig.capacity];

	//limit is the new size instead of the old size
	//fills personList elements with original personList elements
	for (int i = 0; i < size; i++) {
		congressPersonList[i] = orig.congressPersonList[i];
	}
}

PhoneBook& PhoneBook::operator=(const PhoneBook& orig) {
	cout << "Assignment operator called" << endl;
	if (this != &orig) {		//avoids self assignment
		delete[] congressPersonList;	//frees up personList
		size = orig.size;
		capacity = orig.capacity;
		congressPersonList = new CongressPerson[capacity];
		for (int i = 0; i < size; i++) {
			congressPersonList[i] = orig.congressPersonList[i];
		}
	}
	return *this;		//returns new values
}

PhoneBook::~PhoneBook() {
	cout << "Destructor called" << endl;
	delete[] congressPersonList;
}

template <typename TypeVal>
int PhoneBook::binarySearch(int lowVal, int highVal, TypeVal phoneMatch) {
	int midVal;
	int rangeSize;
	int itemPos;

	midVal = (highVal + lowVal) / 2;
	rangeSize = (highVal - lowVal) + 1;

	if (congressPersonList[midVal] == phoneMatch) {        //base case 1
		return midVal;
	}
	else if (rangeSize == 1) {
		itemPos = -1;                        //base case 2
	}
	else {
		if (phoneMatch < congressPersonList[midVal].GetPhone()) {
			itemPos = binarySearch(lowVal, midVal, phoneMatch);
		}
		else {
			itemPos = binarySearch(midVal + 1, highVal, phoneMatch);
		}
	}
	return itemPos;
}
void PhoneBook::searchNum(string phone) {
	int index = binarySearch(0, size, phone);
	if (index >= 0) {
		cout << endl << "Found." << endl << congressPersonList[index] << endl << endl;
	}
	else {
		cout << "Not found." << endl;
	}
}

void PhoneBook::addPerson(CongressPerson person) {
	//double the capacity for more array storage
	if (size == capacity) {
		capacity *= 2;
		CongressPerson* temp = new CongressPerson[capacity];	//copying elements to temp
		for (int i = 0; i < size; i++) {
			temp[i] = congressPersonList[i];
		}
		delete[] congressPersonList;		//deleting old size of personList
		congressPersonList = temp;			//personList size is doubled
	}
	congressPersonList[size] = person;
	size++;
}

void PhoneBook::display() const {
	CongressPerson aCongressPerson;
	cout << "Contents of phone book: " << endl;
	for (int i = 0; i < size; i++) {
		aCongressPerson = congressPersonList[i];
		cout << aCongressPerson << "\n\n";
	}
}

void PhoneBook::sort() {
	CongressPerson temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (congressPersonList[j] > congressPersonList[j + 1]) {
				temp = congressPersonList[j];
				congressPersonList[j] = congressPersonList[j + 1];
				congressPersonList[j + 1] = temp;
			}
		}
	}
}
#include <iostream>
#include <string>
#include <fstream>
#include "PhoneBook.h"
using namespace std;
int main(int argc, char* argv[]) {
	
	// wants to accomplish a search for a congressperson by phone number, but this requires the templated bubble sort,
	// recursive binary search, overloaded ==, >, >=, <=

	CongressPerson aCongressPerson;
	PhoneBook phoneBook;
	ifstream inFile;

	if (argc != 2) {
		cout << endl << "Usage: PhoneBookCongressPerson.exe CongressContacts.txt" << endl;
		return 1;   // 1 indicates error
	}

	cout << "Opening file " << argv[1] << "." << endl;
	inFile.open(argv[1]);

	if (!(inFile.is_open())) {
		cout << "File " << argv[1] << " not found." << endl;
		return 1;
	}


	string last_name, first_name, middle_name, suffix, nickname, 
		full_name, birthday, gender, type, state, district, senate_class, party, url, address, phone;
	string header;
	string birthday_suffix;
	//clears first line of CongressContacts.txt
	getline(inFile, header);

	//gets every line for each Congressperson from CongressContacts.txt
	while (!inFile.eof()) {
		getline(inFile, last_name, ',');
		getline(inFile, first_name, ',');
		getline(inFile, middle_name, ',');
		getline(inFile, suffix, ',');
		getline(inFile, nickname, ',');
		getline(inFile, full_name, ',');
		//checks if there is a suffix, if not, gives birthday the original line.
		getline(inFile, birthday_suffix, ',');
		if (birthday_suffix.at(0) == ' ') {
			full_name.append(birthday_suffix);
			getline(inFile, birthday, ',');
		}
		else {
			birthday = birthday_suffix;
		}
		getline(inFile, gender, ',');
		getline(inFile, type, ',');
		getline(inFile, state, ',');
		getline(inFile, district, ',');
		getline(inFile, senate_class, ',');
		getline(inFile, party, ',');
		getline(inFile, url, ',');
		getline(inFile, address, ',');
		getline(inFile, phone);

		aCongressPerson.SetAll(last_name, first_name, middle_name, suffix, nickname,
			full_name, birthday, gender, type, state, district, senate_class, party, url, address, phone);
		phoneBook.addPerson(aCongressPerson);
	}

	//use sort() function and overloaded comparison operators to sort the list of contacts by phone number
	phoneBook.sort();


	//start of do-while/switch menu

	int choice;
	do {	
		cout << "Enter a character to choose: " << endl;	
		cout << "(1) Display Congress person phone book" << endl;
		cout << "(2) Search for a phone number" << endl;
		cout << "(3) Exit" << endl;
		cout << "--> ";
		cin >> choice;
		
		//checks if a character/string is input instead of a number, prevents infinite loop
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
		}

		switch (choice) {
		case 1: {
			//displays the entire phonebook
			phoneBook.display();
			cout << endl;
			break;
		}
		case 2: {
			string phoneNum;
			cout << "Search phone number here: ";
			cin >> phoneNum;
			//searches for a matching phone number
			phoneBook.searchNum(phoneNum);
			break;
		}
		case 3: {
			cout << "Exiting...";
			break;
		}
		default: {
			cout << "Error occured. Please try a new input." << endl;
			break;
		}
		}
	} while (choice != 3);
	return 0;

}
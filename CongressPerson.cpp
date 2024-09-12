#include <iostream>
#include "CongressPerson.h"
using namespace std;

CongressPerson::CongressPerson() { //default constructor
	last_name = "Undefined";
	first_name = "Undefined";
	phone = "0";
}
CongressPerson::CongressPerson(string fullName, string phoneNum) {	//other constructor
	full_name = fullName;
	phone = phoneNum;
}

//sets all congressperson contacts
void CongressPerson::SetAll(string l, string f, string m, string s, string n, string fu, string b, string g, string t,
	string st, string d, string se, string p, string u, string a, string ph) {
	last_name = l;
	first_name = f;
	middle_name = m;
	suffix = s;
	nickname = n;
	full_name = fu;
	birthday = b;
	gender = g;
	type = t;
	state = st;
	district = d;
	senate_class = se;
	party = p;
	url = u;
	address = a;
	phone = ph;
}

//comparison operators
bool CongressPerson::operator== (const CongressPerson& rhs) {
	return (this->phone == rhs.phone);
}
bool CongressPerson::operator== (string rhsPhone) const {
	return  this->phone == rhsPhone;
}
bool CongressPerson::operator!= (const CongressPerson& rhs) {
	return (!(this->phone == rhs.phone));
}
bool CongressPerson::operator< (const CongressPerson& rhs) {
	return (this->phone < rhs.phone);
}
template <typename TypeVal>
bool CongressPerson::operator< (TypeVal rhsPhone) const {
	return (this->phone < rhsPhone);
}
bool CongressPerson::operator> (const CongressPerson& rhs) {
	return (this->phone > rhs.phone);
}
bool CongressPerson::operator<= (const CongressPerson& rhs) {
	return (!(this->phone > rhs.phone));
}
bool CongressPerson::operator>= (const CongressPerson& rhs) {
	return (!(this->phone < rhs.phone));
}
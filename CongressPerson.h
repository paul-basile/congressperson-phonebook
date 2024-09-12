#include <iostream>
#include <string>
using namespace std;

class CongressPerson {
public:
	CongressPerson();	//default constructor
	CongressPerson(string, string);		//other constructor
	void SetAll(string l, string f, string m, string s, string n, string fu, string b, string g, string t,
		string st, string d, string se, string p, string u, string a, string ph);

	//comparison operators
	bool operator== (const CongressPerson& rhs);
	bool operator== (string) const;
	bool operator!= (const CongressPerson& rhs);
	bool operator< (const CongressPerson& rhs);
	template <typename TypeVal>
	bool operator< (TypeVal) const;
	bool operator> (const CongressPerson& rhs);
	bool operator<= (const CongressPerson& rhs);
	bool operator>= (const CongressPerson& rhs);

	//allows for cout functionality with the CongressPerson class
	friend ostream& operator<<(ostream& out, const CongressPerson& Person) {
		out << Person.last_name << ' ' << Person.first_name << ' ' << Person.middle_name << ' ' << Person.suffix
			<< ' ' << Person.nickname << ' ' << Person.full_name << ' ' << Person.birthday << ' ' <<
			Person.gender << ' ' << Person.type << ' ' << Person.state << ' ' << Person.district
			<< ' ' << Person.senate_class << ' ' << Person.party << ' ' << Person.url
			<< ' ' << Person.address << ' ' << Person.phone;
		return out;
	}

	//getters
	string GetLast() const { return last_name; }
	string GetFirst() const { return first_name; }
	string GetPhone() const { return phone; }
private:
	string last_name, first_name, middle_name, suffix, nickname,
		full_name, birthday, gender, type, state, district, senate_class, party, url, address, phone;
};
#pragma once
#include "string"

using namespace std;

// This class defines a contact item, specifying a string key and name, passing these values to each contact object when the data is provided
class Contact {
public:
	string key;
	string name;
	Contact(string key, string name) {
		this->key = key;
		this->name = name;
	}
};

#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Contact_Object_Str.h"

using namespace std;

// This class allows the creation of a hash table. It has a maximum size of int size, and holds string keys and contact items that are mapped to those keys
class ContactsTable {
private:
	int size;
	Contact** data;
public:
	ContactsTable(int size);
	Contact* Find(string key);
	void Insert(Contact* item);
	Contact* Delete(string key);
	void Display();
	int HashFunction(string key);
};

// This constructor defines the hash table's size, and creates a hash of data depending on the contact item input. It loops through each row in the table and sets
// the value to null - so that the table is empty when created
ContactsTable::ContactsTable(int size) {
	this->size = size;
	data = new Contact * [size];
	for (int n = 0; n < size; n++) {
		data[n] = NULL;
	}
}

// This function creates an integer hash based on the length of the string key provided
int ContactsTable::HashFunction(string key) {
	int sum = 0;
	for (int n = 0; n < key.length(); n++) {
		sum += (int)key[n];
	}
	cout << "key : " << key << " sum : " << sum << " hash : " << sum % size << endl;
	return sum % size;
}

// This function finds a contact item in the hash table based on their string key value. If the data is not null and a key matches, it will return the data stored
// at that row
Contact* ContactsTable::Find(string key) {
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		if (data[hash]->key == key) {
			return data[hash];
		}
		hash++;
		hash %= size;
	}
	return NULL;
}

// This function inserts a new contact item into the hash table, accepting a strink key and data item as input
void ContactsTable::Insert(Contact* item) {
	string key = item->key;
	int hash = HashFunction(key.c_str());
	while (data[hash] != NULL) {
		++hash;
		hash %= size;
	}
	data[hash] = item;
}

// This method deletes a hash table item based on their string key input
Contact* ContactsTable::Delete(string key) {
	int hash = HashFunction(key.c_str());
	while (data[hash] != NULL) {
		if (data[hash]->key == key) {
			Contact* temp = data[hash];
			data[hash] = NULL;
			return temp;
		}
		++hash;
		hash %= size;
	}
	return NULL;
}

// This method displays each hash table contact item, for every non-null value, and outputs their string keys and item names
void ContactsTable::Display() {
	for (int n = 0; n < size; n++) {
		if (data[n] != NULL) {
			cout << n << " : " << data[n]->key << " : " << data[n]->name << endl;
		}
	}
}

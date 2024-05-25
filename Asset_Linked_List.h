#pragma once
#include "Asset_Link.h"

// This class creates a linked list for assets of this system. It has methods to find and delete specific links based on their keys
class AssetList {
public:
	Link* first;
	AssetList();
	bool IsEmpty();
	void Insert(Link* newLink);
	void Display();
	Link* Find(int key);
	Link* Delete(int key);
	Link* Delete();
};

// The constructor for the linked list. It is a program-defined constructor that reserves memory for the linked list. The variable first stores the key value of
// the first link in the list
AssetList::AssetList() {
    first = 0;
}

// This boolean method is used to return the first value of the linked list. It doesn't check the contents of the list, but returns its head if it exists
bool AssetList::IsEmpty() {
    return (first == 0);
}

// This method allows the insertion of a link along with data into the linked list
void AssetList::Insert(Link* newLink) {
    newLink->next = first;
    first = newLink;
}

// This method displays the list items by outputting the data stored in one link, finding the next value in the linked list and repeating the process until it
// reaches the end of the list
void AssetList::Display() {
    Link* current = first;
    while (current != 0) {
        current->Display();
        current = current->next;
    }
}

// This find method will allow the program to locate a specific link when passing its input value in
Link* AssetList::Find(int key) {
    Link* current = first;
    while (current->data != key) {
        if (current->next == 0)
            return 0;
        else
            current = current->next;
    }
    return current;
}

// This delete method will allow the program to delete a link if the input integer data is correct, and sets the previous and current link keys to the same value.
// This means when the current link is destroyed, then the previous link assumes the role of that link, and the list is stable
Link* AssetList::Delete(int key) {
    Link* current = first;
    Link* previous = first;
    while (current->data != key) {
        if (current->next == 0)
            return 0;
        else {
            previous = current;
            current = current->next;
        }
    }
    if (current == first)
        first = first->next;
    else
        previous->next = current->next;
    return current;
}

// This method allows the program to delete the first link in a linked list, by setting a temporary variable to the list's head, setting the next link in the list
// as the first one, and returning the temporary variable
Link* AssetList::Delete() {
    Link* temp = first;
    first = first->next;
    return temp;
}
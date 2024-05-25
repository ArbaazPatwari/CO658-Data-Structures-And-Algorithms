#pragma once
#include <iostream>

using namespace std;

// Class Link that creates links for the linked list. It stores a pointer (the memory address) to the next link in the list
class Link {
public:
    int data;
    Link* next;
    Link(int data);
    int GetData();
    void Display();
    Link* Find(int key);
    Link* Delete(int key);
};

// This is the constructor to make a link, and pass it an integer value of data
Link::Link(int data) {
    this->data = data;
}

// This is a function to return the integer value stored by a link
int Link::GetData() {
    return data;
}

// This display function outputs the link data to the console
void Link::Display() {
    cout << data << endl;
}
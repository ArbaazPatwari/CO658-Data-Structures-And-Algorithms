// DS&A_CW1_22133895.cpp 
// This file contains the main function of the program

#include <tchar.h>
#include <iostream>
#include <math.h>
#include <string>
#include "IT_Ticket_Queue.h"
#include "Asset_Linked_List.h"
#include "Contact_Object_Str.h"
#include "Contact_Hash_Table_Str.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Queue with Ticket IDs:\n" << endl;

    // IT Ticket queue code
	// 
	// This block of code creates a queue 20 values long, and inserts 5 elements. The data of each queue item is stored as an integer (I tried changing this 
	// tostring to write descriptions of the tickets but I kept getting errors). This way, it displays the IDs of each ticket, after displaying the size of the 
	// queue, then removes them as the queue count is more than 0 (not empty). I also wanted to see what the PeekFront() method would do after deleting the queue
	// items, and it gave me a negative value. It probably should have been 0 so it could be some data that was still initialised in memory.
	
	TicketQueue *tickets = new TicketQueue(20);
	tickets->Insert(1);
	tickets->Insert(2);
	tickets->Insert(3);
	tickets->Insert(4);
	tickets->Insert(5);

	cout << "Ticket queue size: " << tickets->Size() << endl;
	cout << "Front ticket ID: " << tickets->PeekFront() << endl;

	while (!tickets->IsEmpty()){
		cout << "Ticket IDs : " << tickets->Remove() << endl;
	}

	cout << "Front ticket ID: " << tickets->PeekFront() << endl;



	cout << "\nAssets stored in a linked list:\n" << endl;

    // Asset Status linked list code
	//
	// This code block creates a linked list object, and inserts various links with integer values. I also tried to modify this linked list for the links to
	// accept string values (indicating the status of each item - such as operational/ under maintenance), but it didn't work. A statement invoked the function
	// Find() which will instruct the program to find the linked item with the value 4. This is possible as it displays in the console, using the if statement to
	// check it is not equal to 0. The next statement orders the program to delete a link, and set the previous link as current. The last statement will confirm 
	// there are assets still being managed using the 'IsEmpty()' function.

	AssetList* assets = new AssetList();
	assets->Insert(new Link(2));
	assets->Insert(new Link(4));
	assets->Insert(new Link(8));
	assets->Insert(new Link(12));
	assets->Insert(new Link(20));
	assets->Display();
	
	Link* foundLink = assets->Find(4);
	
	if (foundLink != 0) {
		cout << " Found Asset with data value : " << foundLink->data << endl;
	}
	else {
		cout << "Unable to delete Asset" << endl;
	}
	
	Link* deleteLink = assets->Delete(4);
	
	if (deleteLink != 0) {
		cout << " Deleted Asset with data value : " << deleteLink->data << endl;
		assets->Display();
	}
	else {
		cout << "Unable to delete Asset" << endl;
	}

	if (!assets->IsEmpty()) {
		cout << "\nThere are existing assets being managed" << endl;
	}
	else {
		cout << "\nThere are no more assets being managed" << endl;
	}



	cout << "\n Contacts stored in a Hash Table:\n" << endl;

    // Contact information hash table code
	//
	// This code block creates a hash table that can store 16 key-value pairs. The next four statements insert a 'Contact' hash table object into the table. The 
	// keys are string values, and a string name is also provided. Invoking the display function will output information for each contact object. It first outputs
	// the hash data, then direct object information (key, sum, hash value), (hash value, key, contact name). The next line finds a specific contact with their 
	// string name, and prints this to the console. The delete function is then invoked, and when the program is instructed to display all contacts, the first
	// three show without the fourth one.

	ContactsTable* contacts = new ContactsTable(16);

	contacts->Insert(new Contact("one", "Joseph Macklson"));
	contacts->Insert(new Contact("two", "Florence Higgs"));
	contacts->Insert(new Contact("three", "AI Helper Bob"));
	contacts->Insert(new Contact("four", "Polka West"));
	contacts->Display();

	Contact* advisor = contacts->Find("four");
	cout << "Found : " << advisor->name << endl;
	contacts->Delete("four");
	contacts->Display();

	return 0;
}

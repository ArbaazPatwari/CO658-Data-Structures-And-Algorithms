#pragma once
#include <string>

// This class creates a Queue, along with methods and private variables such as queue size, a pointer to data items in the queue, the front and rear of the queue
class TicketQueue {
private:
	int size;
	int* data;
	int front;
	int rear;
	int count;
public:
	TicketQueue(int size);
	~TicketQueue();
	void Insert(int item);
	int Remove();
	int PeekFront();
	bool IsEmpty();
	bool IsFull();
	int Size();
};

// This class creates a queue of size int. If a value of 20 is provided, the queue would be able to store 20 items. It is a circular queue, where there is a front
// and rear, and items are inserted at the rear of the queue
TicketQueue::TicketQueue(int size) :size(size) {
	data = new int[size];
	front = 0;
	rear = -1;
	count = 0;
}

// This is the destructor method, to remove the queue from memory, preventing leaks which would diminish performance, or allow exploitation of unused code
TicketQueue::~TicketQueue()
{
}

// This function inserts a new integer item at the rear, if the queue is not full
void TicketQueue::Insert(int item) {
	if (rear == (size - 1)) {
		rear = -1;
	}
	data[++rear] = item;
	count++;
}

// This function removes an element from the front of the queue, by setting its value to 0, and removing one count from the number of items in the queue
int TicketQueue::Remove() {
	int temp = data[front++];
	if (front == size) {
		front = 0;
	}
	count--;
	return temp;
}

// This method returns an element at the front of the queue
int TicketQueue::PeekFront() {
	return data[front];
}

// This method returns the count of the queue as zero, it doesn't check individual items, but can be used to check if the queue exists
bool TicketQueue::IsEmpty() {
	return count == 0;
}

// This method checks if the number of items in the queue matches the maximum capacity of the queue, and returns a true or false value accordingly
bool TicketQueue::IsFull() {
	return count == size;
}

// This method checks the size of the queue and returns an integer value
int TicketQueue::Size() {
	return size;
}
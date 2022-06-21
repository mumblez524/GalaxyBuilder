#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;			//Data to hold in the Node
	Node<T>* next;	//Pointer to the next Node
	Node<T>* prev;	//Pointer to the previous Node
};

template <class T>
class LinkedList {
private:
	Node<T>* mHead;		//Pointer to first Node in chain
	Node<T>* mTail;		//Pointer to last Node in chain
	int mSize;			//Keeps count of number of Nodes in chain

	//Copies one linked list to another.
	void copy(const LinkedList& list) {
		Node<T>* nodePtr = list.mHead;
		while (nodePtr != nullptr) {
			push_front(nodePtr);
			nodePtr = nodePtr->next;
		}
	}
	//Checks if list is empty.
	bool isEmpty() {
		bool status;
		if (mSize == 0)
			status = true;
		else
			status = false;
		return status;
	}
public:
	//Default constructor
	LinkedList() {
		mHead = nullptr;			//Shows empty list.
		mTail = nullptr;			//Shows empty list.
		mSize = 0;					//Shows empty list.
	}
	//Copy constructor
	LinkedList(const LinkedList& list) {
		if (this != &list) {
			clear();
			copy(list);
		}
		return *this;
	}
	//Destructor that performs pop_front on the list while the list is not empty.
	~LinkedList() {
		while (!isEmpty())
			pop_front();
	}
	//Overloaded assignment operator. Deletes current array and replaces it with copy of passed list
	LinkedList& operator=(const LinkedList& list) {
		if (this != &list) {
			clear();
			copy(list);
		}
		return *this;
	}
	//Returns sizeof the LinkedList
	int size() const {
		return mSize;
	}
	//Insert new node to front of linked list
	void push_front(const T value) {
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		if (isEmpty()) {
			mHead = newNode;
			mHead->next = mTail;
			mHead->prev = nullptr;
			mTail = newNode;
			mTail->prev = mHead;
			mTail->next = nullptr;
		}
		else {
			newNode->next = mHead;
			mHead->prev = newNode;
			mHead = newNode;
			mHead->prev = nullptr;
		}
		mSize++;
	}
	//Insert new node to end of linked list
	void push_back(const T value) {
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		if (isEmpty()) {
			mHead = newNode;
			mHead->next = mTail;
			mHead->prev = nullptr;
			mTail = newNode;
			mTail->prev = mHead;
			mTail->next = nullptr;
		}
		else {
			newNode->prev = mTail;
			mTail->next = newNode;
			mTail = newNode;
			mTail->next = nullptr;
		}
		mSize++;
	}
	//Deletes 1st node in linked list
	T pop_front() {
		T value = mHead->data;
		if (mSize == 0) {
			throw "Error! List is empty!";
		}
		else if (mSize == 1) {
			delete mHead;
			mHead = nullptr;
			mTail = nullptr;
		}
		else {
			Node<T>* temp = new Node<T>;
			temp = mHead->next;
			temp->prev = nullptr;
			delete mHead;
			mHead = temp;
		}
		mSize--;
		return value;
	}
	//Deletes last node in linked list.
	T pop_back() {
		T value = mTail->data;
		if (mSize == 0)
			throw "Error! List is empty!";
		else if (mSize == 1) {
			delete mTail;
			mHead = nullptr;
			mTail = nullptr;
		}
		else {
			Node<T>* temp = new Node<T>;
			temp = mTail->prev;
			temp->next = nullptr;
			delete mTail;
			mTail = temp;
		}
		mSize--;
		return value;
	}
	//Used to find nodes.
	T get(int i) {
		int j = 0;
		Node<T>* nodePtr = mHead;
		while (j < i) {
			nodePtr = nodePtr->next;
			j++;
		}
		return nodePtr->data;
	}
	//Clears the entire linked list.
	void clear() {
		while (!isEmpty()) {
			pop_front();
		}
	}
};

#endif
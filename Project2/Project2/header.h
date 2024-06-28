#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>

struct Node {

	T data;
	Node* next;

	Node(const T& value) : data(value), next(nullptr) {}

};


template <typename T>
class LinkedList {

private:
	Node<T>* head;
	Node<T>* tail;
	int numItems;

public:

	LinkedList() : head(nullptr), tail(nullptr), numItems(0) {}

	void push_front(const T& item);
	void push_back(const T& item);
	T pop_front();
	T pop_back();
	T front() const;
	T back() const;
	void empty();
	void insert(int index, const T& item);
	bool remove(const T& item);
	int find(const T& item) const;
	void printValues() const;
	void findAverage();

	int getNumItems() { return numItems; }


};



template <typename T>
void LinkedList<T>::push_front(const T& item) {

	Node<T>* newHead = new Node<T>(item);

	if (head == nullptr) { //if list is empty
		head = newHead;
		tail = head;
	}

	else {
		newHead->next = head;
		head = newHead;
	}

	numItems++;

}

template <typename T> //start fixing this
void LinkedList<T>::push_back(const T& item) {

	Node<T>* newTail = new Node<T>(item);

	if (head == nullptr) { //if list is empty 
		tail = newTail;
		head = tail;
	}

	else {
		newTail->next = tail;
		tail = newTail;
	}

	numItems++;
}
template <typename T>
T LinkedList<T>::pop_front() {

	if (head == NULL) {
		throw exception("The list is empty");
	}

	if (head == tail) {
		T toReturn = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		numItems--;
		return toReturn;
	}


	else {

		

		Node<T>* ptr = head;
		head = head->next;
		int toReturn = ptr->data;
		delete ptr;
		numItems--;
		return toReturn;
	}
}

template <typename T>

T LinkedList<T>::pop_back() {

	if (head == NULL) {
		throw runtime_error("The list is empty");
	}

	if (head == tail) {
		T toReturn = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		numItems--;
		return toReturn;
	}

	Node<T>* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	T toReturn = tail->data;

	delete tail;
	tail = current;
	tail->next = nullptr;
	numItems--;
	return toReturn;

}

template <typename T>

T LinkedList<T>::front() const {
	return head->data;
}

template <typename T>
T LinkedList<T>::back() const {
	return tail->data;
}

template <typename T>
void LinkedList<T>::empty() {

	if (head == nullptr) {
		cout << "The list is already empty." << endl;
	}

	else if (head == tail) {
		delete head;
		cout << endl << "Linked list has been emptied." << endl;
	}

	else {
		Node<T>* current = head;

		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
		cout << endl << "Linked list has been emptied." << endl;

	}

	head = nullptr;
	tail = nullptr;
	numItems = 0;
}

template <typename T>
void LinkedList<T>::insert(int index, const T& item) { //error handle


	Node<T>* toAdd = new Node<T>(item);

	if (index == 0) {
		toAdd->next = head;
		head = toAdd;
		if (tail == nullptr) {
			tail = toAdd;
		}
	}

	Node<T>* current = head;

	int currIndex = 0;

	while (currIndex < index - 1 && current->next != nullptr) {
		currIndex++;
		current = current->next;
	}

	if (currIndex != index - 1) {
		delete toAdd;
		throw out_of_range("Index out of bounds");
	}

	toAdd->next = current->next;
	current->next = toAdd;

	if (toAdd->next == nullptr) {
		tail = toAdd;
	}

}

template <typename T>
bool LinkedList<T>::remove(const T& item) {

	if (numItems == 0) { //if list is empty
		return false;
	}

	Node<T>* current = head;
	Node<T>* previous = nullptr;

	if (head->data == item) { //if item is the first in the list, delete & reassign head
		head = head->next;
		delete current;
		numItems--;
		return true;
	}

	else {
		while (current != nullptr && current->data != item) { //while we haven't reached the end or item to delete
			previous = current;
			current = current->next;
		}

		if (current == nullptr) { //if item wasn't found
			return false;
		}

		previous->next = current->next;
		delete current;
		numItems--;
		return true;


	}




}

template <typename T>
int LinkedList<T>::find(const T& item) const {

	Node<T>* current = head;

	int currIndex = 0;

	while (current->data != item) {
		currIndex++;
		current = current->next;
	}

	return currIndex;

}

template <typename T>
void LinkedList<T>::printValues() const {

	Node<T>* current = head;

	if (head != nullptr) {
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}

	else {
		cout << endl << "The list is empty." << endl;
	}

}

template <typename T>
void LinkedList<T>::findAverage() {

	Node<T>* current = head;

	int total = 0;

	if (numItems == 0) {
		cout << "There is no average." << endl;
		return;
	}

	if (head != nullptr) {
		while (current != nullptr) {
			total += current->data;
			current = current->next;
		}
	}

	double numitems = numItems;
	double average = total / numitems;
	cout << "The average is " << average << setprecision(2) << endl;
	return;



}

//template class LinkedList<int>;




#pragma once
#include "Node.h"
#include <string>

/**
 * Class that will create and manage a linked list
 */
class LinkedList
{
public:
	LinkedList() { head = NULL; }     // Empty constructor, creates empty linked list
	~LinkedList() { delete head; }    // Destructor
	LinkedList(std::string val);      // Creates linked list with head "val"
	void display();                   // Displays the entire linked list
	void add(std::string val);        // Add a new node to the linked list with value "val"
	bool remove(std::string val);     // Remove a node from the linked list with value "val" if present
	bool search(std::string val);     // Finds node with value "val" in linked list if present
	void reverse();                   // Reverses the linked list in-place

private:
	Node* head;                       // Pointer to the first node in the linked list
};


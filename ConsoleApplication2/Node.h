#pragma once
#include <string>

/**
 * Class that will create a node for use with the linked list
 */
class Node
{
	// Linked List needs access to private members for remove function
	friend class LinkedList;

public:
	Node(std::string val);                        // Constructor, creates new node with value "val"
	~Node() { if (next != NULL) delete next; }    // Destructor
	void display();                               // Displays this node
	void add(Node* node);                         // Add a new node to the linked list 
	Node* remove(std::string val);				  // Remove a node from the linked list
	bool search(std::string val);                 // Search for a node in the linked list
	Node* reverse(Node* node);                    // Reverse linked list

private:
	std::string value;                            // Value of the node
	Node* next;                                   // Pointer to the next node in the linked list
};


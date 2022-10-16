#include "pch.h"
#include "LinkedList.h"
#include<iostream>

using namespace std;

/**
 * Constructor
 * 
 * Creates linked list with head "val"
 *
 * @param val String that will become the head of the new linked list
 */
LinkedList::LinkedList(string val) 
{

	// Create new node dynamically and set the head to the new node
	Node* newNode;
	newNode = new Node(val);
	head = newNode;
}

/**
 * Add
 * 
 * Adds a new node to the linked list with value "val"
 *
 * @param val String of the node to add to linked list
 */
void LinkedList::add(string val)
{
	// Create memory for new node
	Node* newNode;
	newNode = new Node(val);

	// If head is not present, linked list is empty so we are adding to a empty list, becomes head
	if (head == NULL)
		head = newNode;

	// Otherwise, append to the end of the linked list
	else
		head->add(newNode);
}

/**
 * Display
 *
 * Will display the entire linked list
 */
void LinkedList::display()
{
	// If head is not present, empty linked list, cannot display
	if (head == NULL)
	{
		cout << "Empty Linked List!" << endl;
		return;
	}

	// Otherwise, print out linked list
	cout << endl;
	cout << "Current Linked List: " << endl;
	head->display();
	cout << endl;
}

/**
 * Remove
 *
 * Will attempt to remove a node with value "val" from linked list. If no node with value "val" is found, function does
 * not modify the linked list. If duplicates are present, function will only remove the one closest to the head
 *
 * @param val String of the value of the node being attempted to remove from the list
 * @return True if node was found and removed, False if not
 */
bool LinkedList::remove(string val)
{
	// If linked list is empty, cannot remove from an empty linked list
	if (head == NULL)
	{
		cout << "Cannot remove from an empty Linked List!" << endl;
		return false;
	}
	
	// Create temporary pointer to hold node that we want to remove
	Node* p;

	// Special case: If removing the head
	if (head->value == val)
	{
		head = head->next;
		return true;
	}

	// Otherwise, call node remove function and hold node that is returned
	p = head->remove(val);


	// P is null if not found
	if (p == NULL)
		return false;

	// Otherwise, we successfully removed a node, rearrange pointers
	p->next = p->next->next;
	return true;
}

/**
 * Search
 * 
 * Will search the linked list for node with value "val"
 *
 * @param val String of node we want to find
 * @return True if node found, false if not
 */
bool LinkedList::search(string val)
{

	// If list is empty, cannot search
	if (head == NULL)
	{
		cout << "Cannot search an empty Linked List!" << endl;
		return false;
	}

	// Otherwise, use node search function
	return head->search(val);
}

/**
 * Reverse
 * 
 * Will reverse the linked list in place
 */
void LinkedList::reverse()
{
	// If Linked List is empty, cannot reverse
	if (head == NULL)
	{
		cout << "Cannot reverse an empty Linked List!" << endl;
		return;
	}

    // Otherwise, reverse the linked list
	Node* p;
	p = head->reverse(NULL);
	head = p;
}
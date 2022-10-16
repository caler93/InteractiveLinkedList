#include "pch.h"
#include "Node.h"
#include<iostream>

using namespace std;

/**
 * Constructor
 * 
 * Will create a new node with value "val"
 * 
 * @param val String that will become the value for the new node
 */
Node::Node(string val)
{
	value = val;
	next = NULL;
}

/**
 * Add
 *
 * Will add a new node at the end of the linked list, using recursion
 *
 * @param node Node pointer to add to the end of the linked list
 */
void Node::add(Node* node)
{
	// If next pointer is not present, we are at the end of the linked list
	if (next == NULL)
	{
		next = node;
		return;
	}

	// Otherwise, recurse through linked list
	next->add(node);
}

/**
 * Display
 *
 * Displays every node in the linked list
 */
void Node::display()
{
	// Print current node
	cout << "[ " << value << " ] ";

	// If next is present, recursively call all nodes in linked list
	if (next != NULL)
	{
		cout << "----> ";
		next->display();
	}
}

/**
 * Remove
 *
 * Will remove a node from the linked list with value "val"
 *
 * @param val String of node we want to remove
 * @return Node pointer to the node that we are removing, returns null if not found
 */
Node* Node::remove(string val)
{
	// Find node where the next one is the one we want to remove
	if (next != NULL)
	{
		if (next->value == val)
			return this;
		return next->remove(val);
	}

	// Otherwise we are at end, so we didn't find it, return null
	return next;
}

/**
 * Search
 *
 * Will search the linked list for node with value "val"
 *
 * @param val String of node we want to find
 * @return True if node found, false if not
 */
bool Node::search(string val)
{
	// If found, return true
	if (value == val)
		return true;

	// If at end, did not find
	if (next == NULL)
		return false;

	// Otherwise, recursively search the linked list
	return next->search(val);
}

/**
 * Reverse
 *
 * Will reverse the linked list in place
 *
 * @param node Pointer to the previous node in the linked list
 * @return Pointer to the node at the end of the linked list that will become the new head 
 */
Node* Node::reverse(Node* node)
{
	// If at end, return this node since it will become the new head
	if (next == NULL)
	{
		next = node;
		return this;
	}

	// Otherwise, send next node our pointer and update our next pointer to the previous one in the list
	Node* p = next;
	next = node;
	return p->reverse(this);

}
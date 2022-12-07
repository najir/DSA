/* DSA, Data Structures and Algorithms
 * Isaac Perks
 * 12/5/22
 */

#include "Application.h"
#include "stdio.h"

// Global Variables


int main() {

	return 0;
}


// Function Definitions
/*
 * Node Functions
 */
Application::bNode(int x = 0)() {
	value = x;
}
bool bNode::setNext(bNode* refNode) {
	bool returnValue = 0;
	if (refNode) {
		next = refNode;
		returnValue = 1;
	}
	return returnValue;
}
bool bNode::setPrevious(bNode* refNode) {
	bool returnValue = 0;
	if (refNode) {
		previous = refNode;
		returnValue = 1;
	}
	return returnValue;
}
int bNode::viewValue() {
	return value;
}

/*
 * Stack Functions
 */
Application::bStack() {
	head = void;
}
int bStack::peek() {
	int returnValue = 0;
	if (head) {
		returnValue = head->viewValue;
	}
	return returnValue;
}
int bStack::pop(){
	int returnValue = 0;
	if (head) {
		bNode* prevNode = head;
		head = head->viewNext;
		returnValue = prevNode->viewValue;
	}
	return returnValue;
}
bool bStack::push(int x) {
	int returnValue = 0;
	if (head) {
		bNode* prevNode = head;
		head = bNode(x);
		head->setNext(prevNode);
		returnValue = 1;
	}
	else {
		head = bNode(x);
		returnValue = 1;
	}
	return returnValue;
}

/*
 * Queue Functions
 */
Application::bQueue() {
	head = void;
	tail = void;
}
int bQueue::peek() {
	int returnValue = 0;
	if (head) {
		returnValue = head->viewValue;
	}
	return returnValue;
}
int bQueue::dequeue() {
	int returnValue = 0
	if (head) {
		bNode* prevNode = head;
		head = prevNode->viewPrevious;
		head->setNext = void;
		returnValue = 1
	}
	return returnValue;
}
bool bQueue::queue(int x) {
	int returnValue = 0;
	if (head) {
		bNode* refNode = head;
		head = bNode(x);
		head->setPrevious = refNode;
		refNode->setNext = head;
		returnValue = 1;
	}
	else {
		head = bNode(x);
		returnValue = 1;
	}
	return returnValue;
}
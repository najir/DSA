/* DSA, Data Structures and Algorithms
 * Isaac Perks
 * 12/5/22
 */

#include "Application.h"
#include "stdio.h"

// Global Variables
int ARRSIZE = 16;      // Initial Array size for all current arrays


int main() {
	return 0;
}


// Function Definitions

/******************************
 * Dynamic Array Functions, Unsorted Array
 ******************************/
APPLICATION_H::dynArray() {
	size = ARRSIZE;
	myArray = new int[size];
};

bool dynArray::insertValue(int x) {
	int loopValue;
	int iter, returnValue = 0;
	while (!loopValue || iter >= size) {     // If loop value is ever 0 or empty, and/or if we iterate beyond the size of the array
		iter += 1;                           // it will end the loop, check the location and insert the data if it's within bounds
		loopValue = myArray[iter-1];
	}
	if !(iter - 1 >= size) {
		myArray[iter - 1] = x;
		returnValue = 1
	}
	return returnValue;

}

bool dynArray::deleteValue(int x){
	int loopValue = 0;
	int iter, returnValue = 0;
	while (loopValue == x || iter >= size) {  // loopValue is the data contained at iter location of the array, if we go out
		iter += 1;                            // of bounds, or find the exact location, the loop ends and we replace the data with 0
		loopValue = myArray[iter - 1];
	}
	if (loopValue == x) {
		myArray[iter - 1] = 0;
		returnValue = 1
	}
	return returnValue;

}

bool dynArray::expandArray() {
	int returnValue = 0;
	int arraySize = sizeof(myArray)*2;

	int* tempArray = new int[arraySize];

	for (int i = 0; i < iter - 1; i++) {
		tempArray[i] = myArray[i];
	}
	delete[] myArray;
	myArray = tempArray;

	return returnValue;
}

bool dynArray::compressArray() {
	int returnValue = 0;



	return returnValue;
}


/******************************
 * Node Functions
 ******************************/
APPLICATION_H::bNode(int x = 0)() {
	value = x;
};

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

/******************************
 * Stack Functions
 ******************************/
APPLICATION_H::bStack() {
	head = void;
};

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

/******************************
 * Queue Functions
 ******************************/
APPLICATION_H::bQueue() {
	head = void;
	tail = void;
};

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



/******************************
*  Binary Search Tree Functions
******************************/
APPLICATION_H::bsLeaf(int x = 0) {
	value = x;
	left = nullptr;
	right = nullptr;
};

int bsLeaf::viewValue() {
	return value;
}

void bsLeaf::setLeft(bsLeaf* refLeaf) {
	left = refLeaf;
}

void bsLeaf::setRight(bsLeaf* refLeaf) {
	right = refLeaf;
}

APPLICATION_H::bsTree() {
	root = nullptr;
};

bool bsTree::insertLeaf(int x) {

}

int bsTree::viewDepth() {

}


/******************************
*  Red Black Search Tree Functions
******************************/
// Leaf initial color is always red(0)
APPLICATION_H::rbLeaf() {
	left = nullptr;
	right = nullptr;
	color = 0;
};

APPLICATION_H::rbTree() {
	root = nullptr;
};

bool rbTree::insertLeaf(int x){

}

int rbTree::viewDepth() {

}
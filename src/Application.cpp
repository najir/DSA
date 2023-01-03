/* DSA, Data Structures and Algorithms
 * Isaac Perks
 * 12/5/22
 * 
 * Important Notes: If any written "tasks" or goals are still posted below, they are not finished but
 * intend to be done at some point.
 *
 * I've avoided using parent classes for nodes and methods between each structure
 * due to each type of structure have vastly different requirments, forcing me to create overrides anyways.
 * This may be looked at again, and I may refactor this code with more class inheritence - 12/22/22
 * 
 * R/B tree rotations have showed me that some online resources may provide a lack of certain info,
 * or ineffecient information. This is a reminder to myself to ask what the best practice is on some
 * forum or with others - 12/22/22
 */

#include "Application.h"
#include "stdio.h"

// Global Variables
int ARRSIZE = 16;      // Initial Array size for all current arrays


int main() {
	return 0;
}


/******************************
 * Dynamic Array Functions, Unsorted Array
 ******************************/
APPLICATION_H::dynArray::dynArray() {
	size = ARRSIZE;
	myArray = new int[size];
};

bool dynArray::insertValue(int x) {
	int loopValue = 0, iter = 0, returnValue = 0;
	while (!loopValue || iter >= size) {     // If loop value is ever 0 or empty, and/or if we iterate beyond the size of the array
		iter += 1;                           // it will end the loop, check the location and insert the data if it's within bounds
		loopValue = myArray[iter - 1];
	}
	if !(iter - 1 >= size) {
		myArray[iter - 1] = x;
		returnValue = 1;
	}
	return returnValue;

}

bool dynArray::deleteValue(int x){
	int loopValue = 0;
	int iter = 0, returnValue = 0;
	while (loopValue == x || iter >= size) {  // loopValue is the data contained at iter location of the array, if we go out
		iter += 1;                            // of bounds, or find the exact location, the loop ends and we replace the data with 0
		loopValue = myArray[iter - 1];
	}
	if (loopValue == x) {
		myArray[iter - 1] = 0;
		returnValue = 1;
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
	int arraySize = sizeof(myArray) / 2;
	int* tempArray = new int[arraySize];

	for (int i = 0; i < arraySize - 1; i++) {
		tempArray[i] = myArray[i];
	}
	delete[] myArray;
	myArray = tempArray;
	
	return returnValue;
}	


/******************************
 * Node Functions
 ******************************/
APPLICATION_H::bNode::bNode(int x = 0) {
	value = x;
};
APPLICATION_H::qNode::qNode(int x = 0)() {
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

int bNode::viewValue() {
	return value;
}

bNode* bNode::viewNext() {
	return next;
}

bool qNode::setPrevious(bNode* refNode) {
	bool returnValue = 0;
	if (refNode) {
		previous = refNode;
		returnValue = 1;
	}
	return returnValue;
}

qNode* qNode::viewPrevious() {
	return previous;
}


/******************************
 * Stack Functions
 ******************************/
APPLICATION_H::bStack::bStack() {
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
APPLICATION_H::bQueue::bQueue() {
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
	int returnValue = 0;
	if (head) {
		qNode* prevNode = head;
		head = prevNode->viewPrevious;
		head->setNext = void;
		returnValue = 1;
	}
	return returnValue;
}

bool bQueue::queue(bNode* refNode) {
	int returnValue = 0;
	if (refNode) {
		if (head) {
			qNode* prevNode = head;
			head = refNode;
			head->setPrevious = prevNode;
			prevNode->setNext = head;
			returnValue = 1;
		}
		else {
			head = refNode;
			returnValue = 1;
		}
	}
	return returnValue;
}


/******************************
*  Base Tree/Leaf Functions
******************************/
APPLICATION_H::baseLeaf::baseLeaf(int x = 0) {
	value = x;
	left = nullptr;
	right = nullptr;
};

APPLICATION_H::searchNode::searchNode(baseLeaf* leafRef) {
	node = leafRef;
	value = leafRef->viewValue;
};

void baseLeaf::setValue(int x) {
	value = x;
}

int baseLeaf::viewValue() {
	return value;
}

bsLeaf baseLeaf::viewLeft() {
	return right;
}

bsLeaf baseLeaf::viewRight() {
	return left;
}

void baseLeaf::setLeft(bsLeaf* refLeaf) {
	left = refLeaf;
}

void baseLeaf::setRight(bsLeaf* refLeaf) {
	right = refLeaf;
}


/******************************
*  Binary Search Tree Main Functions
******************************/
APPLICATION_H::bsTree::bsTree() {
	root = nullptr;
};

void bsTree::bsInsert(int x) {
	baseLeaf* child = nullptr;
	if (root) {
		child = root;
		while (child) {
			if (x > child->viewValue) {
				child = child.viewLeft;
			}
			else {
				child = child.viewRight
			}
		}
		child = baseLeaf(int x);
	}
	else {
		root = baseLeaf(int x);
	}
}

baseLeaf* bsTree::bsSearch(int x) {
	int returnValue = 0;
	baseLeaf* nodeRef = root;
	int valueRef = 0;
	if (root) {
		while (!returnValue || nodeRef) {
			valueRef = nodeRef->viewValue;
			if (x == valueRef) {
				returnValue = nodeRef;
			}
			else if (x < valueRef) {
				nodeRef = nodeRef->viewLeft;
			}
			else {
				nodeRef = nodeRef->viewRight;
			}
		}
	}
	return returnValue;
}

void bsTree::bsDelete(int x) {
	baseLeaf* nodeRef = bsTree::bsSearch(x);
	baseLeaf* leftChild = nodeRef->viewLeft;
	baseLeaf* rightChild = nodeRef->viewRight;
	if (nodeRef) {
		if (leftChild) {
			if (rightChild) {					// 2 Children in deleted node
				baseLeaf* tempNode = nullptr;
				while (nodeRef) {
					tempNode = nodeRef->viewRight;
					if (tempNode) {
						while (tempNode) {
							if (tempNode->viewLeft) { tempNode = tempNode->viewLeft }
							else {
								nodeRef->setValue(tempNode->viewValue);
								nodeRef = tempNode;
								tempNode = nullptr;
							}
						}
					}
					else { delete nodeRef }
				}
			}
			else {								// 1 Child in deleted node and it's left
				// Replace with Child
				nodeRef->setValue(leftChild->setValue);
				nodeRef->setLeft(nullptr);
				delete leftChild;
			}
		}
		else if (rightChild) {					// 1 Child in deleted node and it's right
			// Replace with Child
			nodeRef->setValue(rightChild->setValue);
			nodeRef->setRight(nullptr);
			delete rightChild;
		}
		else {									// 0 Children in deleted node
			// Delete node
			delete nodeRef;
		}
	}
}

void bsInorder(baseLeaf* leafRef, bStack* bstStack) {
	if (node) {
		bsInorder(leafRef->viewLeft, bstStack);
		bstStack->push(leafRef->viewValue);
		bsInorder(leafRef->viewRight, bstStack);
	}

}

void bsPreorder(baseLeaf* leafRef, bStack* bstStack) {
	if (node) {
		bstStack->push(leafRef->viewValue);
		bsPreorder(leafRef->viewLeft, bstStack);
		bsPreorder(leafRef->viewRight, bstStack);
	}

}

void bsPostorder(baseLeaf* leafRef, bStack* bstStack) {
	if (leafRef) {
		bsPostorder(leafRef->viewLeft, bstStack);
		bsPostorder(leafRef->viewRight, bstStack);
		bstStack->push(leafRef->viewValue);
	}
}

void bsLevel(baseLeaf* leafRef, bQueue* bstQueue) {
	if (leafRef && bstQueue) {
		searchNode* rootNode = searchNode(leafRef);
		bQueue* tempQueue = bQueue();
		tempQueue->queue(rootNode);
		while (tempQueue->peek) {
			baseLeaf* oldNode = tempQueue->dequeue();
			tempQueue->queue(oldNode->viewLeft);      // If child does not exist, the queue function will not input anything
			tempQueue->queue(oldNode->viewRight);
			bstQueue->queue(oldNode);                 // Adding nodes from dequeue to a new queue for output.
		}
	}
}

void bsZigzag(baseLeaf* leafRef, bQueue* bstQueue) {  // Going to come back to this when I complete r/b Trees
	if (leafRef) {

	}
}


/******************************
*  Red Black Search Tree Leaf Functions
*  Red = 0, Black = 1
******************************/
APPLICATION_H::rbLeaf::rbLeaf(int x = 0) {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	color = 0;
	value = x;
};

void rbLeaf::setColor(bool x) {
	color = x;
}

void rbLeaf::setParent(rbLeaf* refParent) {
	parent = refParent;
}

bool rbLeaf::viewColor() {
	return color;
}

rbLeaf* rbLeaf::viewParent() {
	return parent;
}


/******************************
*  Red Black Search Tree Main Functions
*  Red = 0 Black = 1
******************************/
APPLICATION_H::rbTree::rbTree	() {
	root = nullptr;
};

rbLeaf* rbTree::rbSearch(int x){
	return returnValue;
}

void rbTree::rightRotation(rbLeaf* parentRef) {
	rbLeaf* grandRef = parentRef->viewParent();
	rbLeaf* uncleRef = grandRef->viewRight();
	rbLeaf* tempLeaf = rbleaf(grandRef->viewValue());

	grandRef->setLeft(parentRef->viewLeft);
	grandRef->setRight(tempLeaf);
	grandRef->setValue(parentRef->viewValue());
	grandRef->setColor(1);

	tempLeaf->setParent(grandRef);
	tempLeaf->setRight(uncleRef);
	tempLeaf->setLeft(parentRef->viewRight());
	tempLeaf->setColor(0);

	uncleRef->setParent(tempLeaf);
}

void rbTree::leftRotation(rbLeaf* parentRef) {
	rbLeaf* grandRef = parentRef->viewParent();
	rbLeaf* uncleRef = grandRef->viewLeft();
	rbLeaf* tempLeaf = rbleaf(grandRef->viewValue());

	grandRef->setLeft(parentRef->viewRight);           // Replacing values in GP node, rather then switch parents
	grandRef->setRight(tempLeaf);                      // This is a faster then checking GGP L/R child for GP
	grandRef->setValue(parentRef->viewValue());
	grandRef->setColor(1);

	tempLeaf->setParent(grandRef);
	tempLeaf->setRight(uncleRef);
	tempLeaf->setLeft(parentRef->viewLeft());
	tempLeaf->setColor(0);

	uncleRef->setParent(tempLeaf);
}

// Performs a BST search to find next empty position and enters new red node. Then calls helper function to swap colors and rotate
void rbTree::rbInsert(int x) {
	rbLeaf* tempLeaf = root;
	rbLeaf* tempParent = nullptr;
	int tempValue = 0;
	while (tempLeaf) {
		tempValue = tempLeaf->viewValue();
		if (tempValue >= x) {
			tempParent = tempLeaf;
			tempLeaf = tempLeaf->viewLeft();
		}
		else {
			tempParent = tempLeaf;
			tempLeaf = tempLeaf->viewRight();
		}
	}
	if (!tempLeaf) {                                 // if the node already exists the function simply does not add a new node
		tempLeaf = rbLeaf(x);
		tempLeaf->setColor(0);
		tempLeaf->setParent(tempParent);
		if (!tempParent) { tempLeaf->setColor(1); }  // If no parent exists for the new node it is the root and needs to be set black
		else { rbColorSwap(rbPosition); }            // If it is not the root then a colors need to be checked
	}
}

// Helper function for inserts, determins what rotations need to be done and what color swaps are needed
void rbTree::rbColorSwap(rbLeaf* refLeaf) {
	rbLeaf* parentRef = refLeaf->viewParent();
	rbLeaf* uncleRef = nullptr;
	rbLeaf* grandRef = parentRef->viewParent();
	if (parentRef->viewLeft() == refLeaf) { uncleRef = parentRef->viewRight(); }
	else { uncleRef = parentRef->viewLeft(); }
	if (parentRef->viewColor() == 0) {
		if (!uncleRef) {
			parentRef->setColor(1);
			grandRef->setColor(0);
			rbColorSwap(parentRef);
		}
		else if (uncleRef->viewColor() == 0) {
			parentRef->setColor(1);
			uncleRef->setColor(1);
			grandRef->setColor(0);
			rbColorSwap(parentRef);
		}
		else if (uncleRef->viewColor() == 1) {
			// 4 cases of rotations, find out what direction the parent and child are in
			if (parentRef == grandRef->viewLeft()) {
				if (refLeaf == parentRef->viewLeft) {    // LL rotation
					rightRotation(parentRef);
				}
				else {									 // LR rotation
					leftRotation(refLeaf);
					rightRotation(parentRef);
				}
			}
			else {
				if (refLeaf == parentRef->viewRight) {	 // RR rotations
					leftRotation(parentRef);
				}
				else {					                 // RL rotations, parent right of gp, child left of parent
					rightRotation(refLeaf);
					leftRotation(parentRef);
				}
			}
		}
	}
}

void rbTree::rbDelete(int x) {
	//BST DELETE


	//RECOLOR

	//CHECK SIMPLE CASE

	//CALL FOR DOUBLE B CASE

}

void rbTree::rbDoubleBlack(rbLeaf* refLeaf) {
	//Check root case

	//Sibling Black, Child red case
		//LL
		//LR
		//RR
		//RL

	//Sibling Black, Child black case
		//check parent and recur

	//Sibling Red Case
		//Rotate, recolor, then call function again on same same node. Will perform one if first 2 options

}
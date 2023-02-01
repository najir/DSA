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

bool qNode::setPrevious(qNode* refNode) {
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

void baseLeaf::setLeft(baseLeaf* refLeaf) {
	left = refLeaf;
}

void baseLeaf::setRight(baseLeaf* refLeaf) {
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
			if (rightChild) {					// 2 Children in deleted node, successor
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
					else { bsTree::bsDelete(nodeRef->viewValue); }
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

void bsTree::bsInorder(baseLeaf* leafRef, bStack* bstStack) {
	if (node) {
		bsInorder(leafRef->viewLeft, bstStack);
		bstStack->push(leafRef->viewValue);
		bsInorder(leafRef->viewRight, bstStack);
	}

}

void bsTree::bsPreorder(baseLeaf* leafRef, bStack* bstStack) {
	if (node) {
		bstStack->push(leafRef->viewValue);
		bsPreorder(leafRef->viewLeft, bstStack);
		bsPreorder(leafRef->viewRight, bstStack);
	}

}

void bsTree::bsPostorder(baseLeaf* leafRef, bStack* bstStack) {
	if (leafRef) {
		bsPostorder(leafRef->viewLeft, bstStack);
		bsPostorder(leafRef->viewRight, bstStack);
		bstStack->push(leafRef->viewValue);
	}
}

void bsTree::bsLevel(baseLeaf* leafRef, bQueue* bstQueue) {
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

void bsTree::bsZigzag(baseLeaf* leafRef, bQueue* bstQueue) {  // Going to come back to this when I complete r/b Trees
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
*  Red = 1 Black = 0
******************************/
APPLICATION_H::rbTree::rbTree() {
	root = nullptr;
};

rbLeaf* rbTree::rbSearch(int x){
	int returnValue = 0;
	rbLeaf* nodeRef = root;
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

void rbTree::rightRotation(rbLeaf* parentRef) {
	rbLeaf* grandRef = parentRef->viewParent();
	rbLeaf* uncleRef = grandRef->viewRight();
	rbLeaf* tempLeaf = rbleaf(grandRef->viewValue());

	tempLeaf->setColor(grandRef->viewColor);
	grandRef->setLeft(parentRef->viewLeft);
	grandRef->setRight(tempLeaf);
	grandRef->setValue(parentRef->viewValue());
	grandRef->setColor(parentRef->viewColor);

	tempLeaf->setParent(grandRef);
	tempLeaf->setRight(uncleRef);
	tempLeaf->setLeft(parentRef->viewRight());

	uncleRef->setParent(tempLeaf);
}

void rbTree::leftRotation(rbLeaf* parentRef) {
	rbLeaf* grandRef = parentRef->viewParent();
	rbLeaf* uncleRef = grandRef->viewLeft();
	rbLeaf* tempLeaf = rbleaf(grandRef->viewValue());

	tempLeaf->setColor(grandRef->viewColor);
	grandRef->setLeft(parentRef->viewRight);			// Replacing values in GP node, rather then switch parents
	grandRef->setRight(tempLeaf);						// This is a faster then checking GGP L/R child for GP
	grandRef->setValue(parentRef->viewValue());
	grandRef->setColor(parentRef->viewColor);

	tempLeaf->setParent(grandRef);
	tempLeaf->setRight(uncleRef);
	tempLeaf->setLeft(parentRef->viewLeft());

	uncleRef->setParent(tempLeaf);
}
bool rbTree::rbColorCheck(rbLeaf* refNode) {			// Return 1 if either child is red
	int returnValue = 0;
	if (refNode) {
		rbLeaf* nodeLeft = refNode->viewLeft;
		rbLeaf* nodeRight = refNode->viewRight;
		if (nodeLeft) {
			if (nodeLeft->viewColor == 1) {
				returnValue = 1
			}
		}
		if (nodeRight) {
			if (nodeRight->viewColor == 1) {
				returnValue = 1;
			}
		}
	}
	return returnValue;
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
void rbTree::rbInsertHelper(rbLeaf* refLeaf) {
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
					rbTree::rightRotation(parentRef);
				}
				else {									 // LR rotation
					rbTree::leftRotation(refLeaf);
					rbTree::rightRotation(parentRef);
				}
			}
			else {
				if (refLeaf == parentRef->viewRight) {	 // RR rotations
					rbTree::leftRotation(parentRef);
				}
				else {					                 // RL rotations, parent right of gp, child left of parent
					rbTree::rightRotation(refLeaf);
					rbTree::leftRotation(parentRef);
				}
			}
		}
	}
}

void rbTree::rbDelete(int x) {
	//BST DELETE
	rbLeaf* nodeRef = bsTree::bsSearch(x);
	rbLeaf* leftChild = nodeRef->viewLeft;
	rbLeaf* rightChild = nodeRef->viewRight;
	rbLeaf* deletedNode = nullptr;
	rbLeaf* nodeSibling = nullptr;
	if (nodeRef) {
		if (leftChild) {
			if (rightChild) {					// 2 Children in deleted node
				rbLeaf* tempNode = nullptr;
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
					else { rbTree::rbDelete(nodeRef->viewValue) }		// Final node to be deleted, use this for rb deletion reference
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
			rbDoubleBlack(nodeRef);
			delete nodeRef;
		}
	}
}

// Recursive function that needs to be called again for certain cases
void rbTree::rbDoubleBlack(rbLeaf* refLeaf) {
	rbLeaf* refParent = refLeaf->viewParent;
	rbLeaf* refSibling = nullptr;
	rbLeaf* siblingLeft = nullptr;
	rbLeaf* siblingRight = nullptr;
	if (refParent->viewLeft == refLeaf) { sibling = refParent->viewRight; }
	else { sibling = refParent->viewLeft; }
	if (refSibling) {
		siblingLeft = refSibling->viewLeft;
		siblingRight = refSibling->viewRight;s
	}
	if (root != refLeaf) {
		if (refLeaf->viewColor == 0 && rbTree::rbColorCheck(refLeaf) == 0) {
			// Checks if siblings children is red
			if (rbTree::rbColorCheck(refSibling)) {
				if (refSibling == refParent->viewLeft) {
					if (siblingLeft && siblingLeft->viewColor == 1) {			// LL
						rbTree::rightRotation(refParent);
						siblingLeft->setColor(0);
					}
					else {														// LR
						rbTree::leftRotation(refLeaf);
						rbTree::rightRotation(refParent);
						siblingLeft->setColor(0);
					}
				}
				else {
					if (siblingRight && siblingLeft->viewColor == 1) {			// RR
						rbTree::leftRotation(refParent);
						siblingRight->setColor(0);
					}
					else {														// RL
						rbTree::rightRotation(refLeaf);
						rbTree::leftRotation(refParent);
						siblingRight->setColor(0);
					}
				}

			}
			// Checks if sibling is red
			else if (rbTree::rbColorCheck(refLeaf->viewParent)) {
				if (refLeaf == refParent->viewLeft) {
					rbTree::leftRotation(refSibling);
					refSibling->setColor(1);
				}
				else {
					rbTree::rightRotation(refSibling);
					refSibling->setColor(1);
				}
			}
			// Everything is black
			else {
				if (refSibling) { 
					refSibling->setColor(1); 
					if (refParent->viewColor == 0) { rbTree::rbDoubleBlack(refParent); }
					else { refParent->setColor(0); }
				}
				else {
					if (refParent->viewColor == 0) { rbTree::rbDoubleBlack(refParent); }
					else { refParent->setColor(0); }
				}

			}
		}
	}
}



/******************************
*  AVL Node functions
******************************/
avlLeaf::avlLeaf(int x) {
	this->balanceFactor = 0;
	this->setValue(x);
}
void avlLeaf::setBalance(int x) {
	this->balanceFactor = x;
}
int avlLeaf::viewBalance() {
	return this->balanceFactor;
}


/******************************
*  AVL Tree functions
******************************/
avlTree::avlTree(int x) {
	this->root = new avlLeaf(x);
}
void avlTree::avlInsert(int x) {
	this->avlInsertHelper(this->viewRoot, x);
}
void avlTree::avlInsertHelper(avlLeaf* refNode, int x) {
	if(refNode){
		if (x > refNode->viewValue) {
			refNode->setBalance(refNode->viewBalance() - 1);
			if (!refNode->viewRight()) { refNode->setRight(new avlLeaf(x)); }
			else { this->avlInsertHelper(refNode->viewRight(), x); }
		}
		else {
			refNode->setBalance(refNode->viewBalance() + 1);
			if (!refNode->viewLeft()) { refNode->setLeft(new avlLeaf(x)); }
			else { this->avlInsertHelper(refNode->viewLeft(), x); }
		}
		// Left unbalance
		if (refNode->viewBalance() > 1) {
			if (refNode->viewLeft()->viewLeft()) {
				this->leftRotation(refNode);
			}
			else {
				this->rightRotation(refNode);
				this->leftRotation(refNode);
			}
		}
		// Right unbalance
		else if (refNode->viewBalance < 1) {
			if (refNode->viewRight()->viewRight()) {
				this->rightRotation(refNode);
			}
			else {
				this->leftRotation(refNode);
				this->rightRotation(refNode);
			}
		}
	}
}
void avlTree::avlDelete(int x) {
	//BST delete, check balances and rotate
	this->avlDeleteHelper(this->viewRoot, x);
}
void avlTree::avlDeleteNode(avlLeaf* refNode) {

}
void avlTree::avlDeleteHelper(avlLeaf* refNode, int x) {
	if (refNode) {
		if (x == refNode->viewValue) {
			this->avlDeleteHelper(refNode);
		}
		if (x > refNode->viewValue) {
			refNode->setBalance(refNode->viewBalance() + 1);
			this->avlInsertHelper(refNode->viewRight(), x);
		}
		else {
			refNode->setBalance(refNode->viewBalance() - 1);
			this->avlInsertHelper(refNode->viewLeft(), x);
		}
		// Left unbalance
		if (refNode->viewBalance() > 1) {
			if (refNode->viewLeft()->viewLeft()) {
				this->leftRotation(refNode);
			}
			else {
				this->rightRotation(refNode);
				this->leftRotation(refNode);
			}
		}
		// Right unbalance
		else if (refNode->viewBalance < 1) {
			if (refNode->viewRight()->viewRight()) {
				this->rightRotation(refNode);
			}
			else {
				this->leftRotation(refNode);
				this->rightRotation(refNode);
			}
		}
	}
}
// Going to rewrite this to not use to ptr's and use an iter value instead.
avlLeaf* avlTree::avlSearch(int x) {
	avlLeaf* returnNode = nullptr;
	avlLeaf* tempNode = this->viewRoot();
	while (tempNode) {
		if (tempNode->viewValue == x) {
			returnNode = tempNode;
			tempNode = nullptr;
		}
		if (tempNode->viewValue > x) { tempNode = tempNode->viewLeft(); }
		else{ tempNode = tempNode->viewRight() }
	}
	delete tempNode;
	return returnNode;
}
avlLeaf* avlTree::viewRoot() {
	return this->root;
}
//Rotations are done at the highest edge, as we do not have access to parent data
void avlTree::leftRotation(avlLeaf* refLeaf) {
	avlLeaf* grandparentTemp = new avlLeaf(refLeaf->viewValue());
	avlLeaf* parentRef = refLeaf->viewLeft();
	avlLeaf* childRef = parentRef->viewLeft();

	grandparentTemp->setRight(refLeaf->viewRight());
	grandparentTemp->setLeft(parentRef->viewRight());
	refLeaf->setValue(parentRef->viewValue());
	refLeaf->setLeft(childRef);
	refLeaf->setRight(grandparentTemp);
	delete parentRef;
}
void avlTree::rightRotation(avlLeaf* refLeaf) {
	avlLeaf* grandparentTemp = new avlLeaf(refLeaf->viewValue());
	avlLeaf* parentRef = refLeaf->viewRight();
	avlLeaf* childRef = parentRef->viewRight();

	grandparentTemp->setLeft(refLeaf->viewLeft();
	grandparentTemp->setRight(parentRef->viewLeft());
	refLeaf->setValue(parentRef->viewValue());
	refLeaf->setRight(childRef);
	refLeaf->setLeft(grandparentTemp);
	delete parentRef;
}
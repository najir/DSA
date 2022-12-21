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
*  Binary Search Tree Leaf Functions
******************************/
APPLICATION_H::bsLeaf(int x = 0) {
	value = x;
	left = nullptr;
	right = nullptr;
};

void bsLeaf::setValue(int x) {
	value = x;
}
int bsLeaf::viewValue() {
	return value;
}

bsLeaf bsLeaf::viewLeft() {
	return right;
}
bsLeaf bsLeaf::viewRight() {
	return left;
}

void bsLeaf::setLeft(bsLeaf* refLeaf) {
	left = refLeaf;
}

void bsLeaf::setRight(bsLeaf* refLeaf) {
	right = refLeaf;
}

/******************************
*  Binary Search Tree Main Functions
******************************/
APPLICATION_H::bsTree() {
	root = nullptr;
};

bool bsTree::bsInsert(int x) {
	bsLeaf* child = nullptr;
	returnValue = 0;

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
		child = bsLeaf(int x);
	}
	else {
		root = bsLeaf(int x);
		returnValue = 1;
	}
	return returnValue;
}

bsLeaf* bsTree::bsSearch(int x) {
	int returnValue = 0;
	bsLeaf* nodeRef = root;
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

bool bsTree::bsDelete(int x) {
	int returnValue = 0;
	bsLeaf* nodeRef = root;
	bsLeaf* childRef = nullptr;
	int valueRef = 0;
	
	returnValue = bsTree::bsSearch(x);
	if (returnValue) {
		if (nodeRef->viewRight()) {
			childRef = nodeRef->viewRight();
		}
		else {
			childRef = nodeRef->viewLeft();
		}
		while (childRef) {
			nodeRef->setValue(childRef->viewValue());
			nodeRef->setLeft(childRef->viewLeft());
			nodeRef->setRight(childRef->viewRight());
			if (nodeRef->viewRight()) {
				childRef = nodeRef->viewRight();
			}
			else {
				childRef = nullptr;
			}
		}
	}
	return returnValue;
}


/******************************
*  Red Black Search Tree Leaf Functions
******************************/
// Leaf initial color is always red(0)
APPLICATION_H::rbLeaf() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	color = 0;
	value = 0;
};

void rbLeaf::setColor(bool x) {
	color = x;
}

void rbLeaf::setLeft(rbLeaf* refLeaf) {
	left = refLeaf;
}

void rbLeaf::setRight(rbLeaf* refLeaf) {
	right = refLeaf;
}

void rbLeaf::setValue(int x) {
	value = x;
}

void rbLeaf::setParent(rbLeaf* refParent) {
	parent = refParent;
}

bool rbLeaf::viewColor() {
	return color;
}

rbLeaf* rbLeaf::viewLeft() {
	return left;
}

rbLeaf* rbLeaf::viewRight() {
	return right;
}

rbLeaf* rbLeaf::viewParent() {
	return parent;
}

int rbLeaf::viewValue() {
	return value;
}

/******************************
*  Red Black Search Tree Main Functions
******************************/
APPLICATION_H::rbTree() {
	root = nullptr;
};

rbLeaf* rbTree::rbSearch(int x){
	//replace this with parent tree object BST search that returns position pointer
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
	tempLeaf->setColor(0);
	uncleRef->setParent(tempLeaf);
}

void rbTree::leftRotation(rbLeaf* refLeaf) {
	rbLeaf* grandRef = parentRef->viewParent();
	rbLeaf* uncleRef = grandRef->viewLeft();
	rbLeaf* tempLeaf = rbleaf(grandRef->viewValue());
	grandRef->setLeft(parentRef->viewRight);
	grandRef->setRight(tempLeaf);
	grandRef->setValue(parentRef->viewValue());
	grandRef->setColor(1);
	tempLeaf->setParent(grandRef);
	tempLeaf->setRight(uncleRef);
	tempLeaf->setColor(0);
	uncleRef->setParent(tempLeaf);
}


bool rbTree::rbInsert(int x) {
	bool returnValue = 0;
	//perform bst
	rbLeaf* rbParent = rbSearch(x);
	if (rbParent) {
		rbLeaf* rbChild = rbLeaf(x);
		rbChild->viewParent(rbParent);
		if (rbParent->viewValue() <= x) {
			rbParent->setRight(rbChild);
		}
		else {
			rbParent->setLeft(rbChild);
		}
		rbColorSwap(rbPosition);
		returnValue = 1;
	}
	else {
		root = rbLeaf(x);
		root->setColor(1);
		returnValue = 1;
	}
	return returnValue;
}

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

				}
				else {									 // LR rotation

				}
			}
			else {
				if (refLeaf == parentRef->viewRight) {	 // RR rotations

				}
				else {					                 // RL rotations, parent right of gp, child left of parent

				}
			}
		}
	}
}

bool rbTree::rbDelete(int x) {

}
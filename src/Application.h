#ifndef APPLICATION_H
#define APPLICATION_H


/*******************************
 * Dynamic Array class/method initalization, unsorted array
 *******************************/
class dynArray {
private:
	int size;
	int* myArray = nullptr;
public:
	bool insertValue(int x);
	bool deleteValue(int x);
	bool expandArray();
	bool compressArray();
};


/*******************************
 * Queue and Stack class/method initialzing
 * Node class contains data and methods for both queue and stack use
 *******************************/
class bNode {
private:
	int value;
	bNode* next;
public:
	bool setNext(bNode* refNode);
	int viewValue();
	bNode* viewNext();
};

class qNode : public bNode {
private:
	qNode* previous;
public:
	bool setPrevious(qNode* refNode);
	qNode* viewPrevious();
};

class bStack {
private:
	bNode* head;
public:
	int peek();
	int pop();
	bool push(int x);
};

class bQueue {
private:
	qNode* head;
	qNode* tail;
public:
	int peek();
	bool queue(bNode* refNode);
	int dequeue();
};

/*******************************
 * Tree class initalization
 * Currently contains leaf and basic tree functions. Will be adding
 * 
 * Base tree class will provide traversals and search functions. 
 * Individual tree classes will contain their insert/delete operations
 * Search/insert Algorithms and creating seperate tree/leaf classes
*******************************/
class baseLeaf {
private:
	int value;
	baseLeaf* left;
	baseLeaf* right;
public:
	int viewValue();
	void setValue(int x);
	void setLeft(baseLeaf* refLeaf);
	void setRight(baseLeaf* refLeaf);
	baseLeaf* viewLeft();
	baseLeaf* viewRight();
};

class bsTree {
private:
	baseLeaf* root;
public:
	void bsDelete(int x);
	void bsInsert(int x);
	baseLeaf* bsSearch(int x);
	void bsInorder(baseLeaf* leafRef, bStack* bstStack);
	void bsPreorder(baseLeaf* leafRef, bStack* bstStack);
	void bsPostorder(baseLeaf* leafRef, bStack* bstStack);
	void bsLevel(baseLeaf* leafRef, bQueue* bstQueue);
	void bsZigzag(baseLeaf* leafRef, bQueue* bstQueue);
};

class rbLeaf : public baseLeaf {
private:
	rbLeaf* parent;
	int color;                             // Red = 1 Black = 0
public:
	void setColor(bool x);                 // 0 for red swap and 1 for black swap
	void setParent(rbLeaf* rbParent);
	bool viewColor();                      // Red = 1 Black = 0
	rbLeaf* viewParent();
};

class rbTree {
private:
	rbLeaf* root;
public:
	void rbInsert(int x);
	void rbDelete(int x);
	rbLeaf* rbSearch(int x);
	bool rbColorCheck(rbLeaf* refNode);
	void rbInsertHelper(rbLeaf* refLeaf);
	void rightRotation(rbLeaf* parentRef);
	void leftRotation(rbLeaf* parentRef);
	void rbDoubleBlack(rbLeaf* refLeaf);
};

class avlLeaf : public baseLeaf {
private:
	int balanceFactor;
public:
	void setParent(avlLeaf* refLeaf);
	int viewBalance(avlLeaf* refLeaf);
};

class avlTree {
private:

public:
	void avlInsert(int x);
	void avlDelete(int x);
	avlLeaf* avlSearch(int x);
	void leftRotation(avlLeaf* refLeaf);
	void rightRotation(avlLeaf* refLeaf);
};
#endif
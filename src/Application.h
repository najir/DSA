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
	bNode* previous;
public:
	bool setNext(bNode* refNode);
	bool setPrevious(bNode* refNode);
	int viewValue();
	bNode viewNext();
	bNode viewPrevious();
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
	bNode* head;
	bNode* tail;
public:
	int peek();
	bool queue(int x);
	int dequeue();
};

/*******************************
 * Tree class initalization
 * Currently contains leaf and basic tree functions. Will be adding
 * Search/insert Algorithms and creating seperate tree/leaf classes
*******************************/

class bsLeaf {
private:
	int value;
	bsLeaf* left;
	bsLeaf* right;
public:
	int viewValue();
	void setValue(int x);
	void setLeft(bsLeaf* refLeaf);
	void setRight(bsLeaf* refLeaf);
	bsLeaf viewLeft();
	bsLeaf viewRight();
};

class bsTree {
private:
	bsLeaf* root;
public:
	bool bsDelete(int x);
	bool bsInsert(int x);
	bsLeaf* bsSearch(int x);
};

class rbLeaf {
private:
	int value;
	rbLeaf* left;
	rbLeaf* right;
	rbLeaf* parent;
	int color;                             // Red = 0 Black = 1
public:
	int setValue(int x);
	void setLeft(rbLeaf* refLeaf);
	void setRight(rbLeaf* refLeaf);
	void setColor(bool x);                 // 0 for red swap and 1 for black swap
	void setParent(rbLeaf* rbParent);
	bool viewColor();                      // Red = 0 Black = 1
	int viewValue();
	rbLeaf* viewLeft();
	rbLeaf* viewRight();
	rbLeaf* viewParent();
};

class rbTree {
private:
	rbLeaf* root;
public:
	bool rbInsert(int x);
	bool rbDelete(int x);
	rbLeaf* rbSearch(int x);
	void rbColorSwap(rbLeaf* refLeaf);
	void rightRotation(rbLeaf* refLeaf);
	void leftRotation(rbLeaf* refLeaf);

};
#endif
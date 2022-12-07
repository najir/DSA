#ifndef APPLICATION_H
#define APPLICATION_H

/* Queue and Stack class/method initialzing
 * Node class contains data and methods for both queue and stack use
 */
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

/* Tree class initalization
 * Currently contains leaf and basic tree functions. Will be adding
 * Search/insert Algorithms and creating seperate tree/leaf classes
*/

class bsLeaf {
private:
	int value;
	bsLeaf* left;
	bsLeaf* right;
public:
	int viewValue();
	bool setLeft();
	bool setRight();
};

class bsTree {
private:
	bsLeaf* root;
public:
	int viewDepth();
	bool insertLeaf(int x);
};

class rbLeaf {
private:
	int value;
	rbLeaf* left;
	rbLeaf* right;
	int color;         // Red = 0 Black = 1
public:
	int viewvalue();
	bool setLeft();
	bool setRight();
	bool swapColor();  // Bool will return 0 for red swap and 1 for black swap
};

class rbTree {
private:
	rbLeaf* root;
public:
	bool insertLeaf(int x);
	int viewDepth();

};
#endif
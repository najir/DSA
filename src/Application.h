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

/* Future Tree info
 *
*/

#endif
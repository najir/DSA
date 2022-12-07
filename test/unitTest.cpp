/* Unit Testing for DSA functions and classes
 * Isaac Perks
 * 12/5/22
*/

#include "unitTest.h"
#include "../src/Application.h"

// Global Variables
int QTANSWER1 = ;


int main() {


}

// Function Definitions

/*******************************
 *  Dynamic Array unit tests
 *******************************/
int UNITTEST_H::dynTest1(int x) {

}
int UNITTEST_H::dynTest2(int x) {

}
int UNITTEST_H::dynTest3(int x) {

}
int UNITTEST_H::dynTest4(int x) {

}

/******************************* 
 *  Queue unit tests
 *******************************/
int UNITTEST_H::qTest1(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.queue(x);
	qObject.queue(x + 2);
	qObject.queue(x + 4);
	qObject.dequeue();
	return qObject.peek();
}

int UNITTEST_H::qTest2(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.dequeue();
	return qObject.peek();
}

int UNITTEST_H::qTest3(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.queue(x);
	qObject.dequeue();
	qObject.queue(x + 4);
	return qObject.peek();
}

int UNITTEST_H::qTest4(int x) {

}

/******************************* 
*  Queue unit tests
*******************************/

int UNITTEST_H::sTest1(int x) {

}

int UNITTEST_H::sTest2(int x) {

}

int UNITTEST_H::sTest3(int x) {

}

int UNITTEST_H::sTest4(int x) {

}

/******************************* 
*  BS Tree Unit Tests
*******************************/
int UNITTEST_H::bsTest1(int x) {

}
int UNITTEST_H::bsTest2(int x) {

}
int UNITTEST_H::bsTest3(int x) {

}
int UNITTEST_H::bsTest4(int x) {

}

/******************************* 
*  RB Tree Unit Tests
*******************************/
int UNITTEST_H::rbTest1(int x) {

}
int UNITTEST_H::rbTest2(int x) {

}
int UNITTEST_H::rbTest3(int x) {

}
int UNITTEST_H::rbTest4(int x) {

}

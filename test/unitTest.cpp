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

int unitTest::qTest1(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.queue(x);
	qObject.queue(x + 2);
	qObject.queue(x + 4);
	qObject.dequeue();
	return qObject.peek();
}
int unitTest::qTest2(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.dequeue();
	return qObject.peek();
}
int unitTest::qTest3(int x) {
	APPLICATION_H::bQueue qObject = APPLICATION_H::bQueue();
	qObject.queue(x);
	qObject.dequeue();
	qObject.queue(x + 4);
	return qObject.peek();
}
int unitTest::qTest4(int x) {

}

int unitTest::sTest1(int x) {

}
int unitTest::sTest2(int x) {

}
int unitTest::sTest3(int x) {

}
int unitTest::sTest4(int x) {

}
# DSA
Isaac Perks 12/5/22
<br />
# Description
_____________________
DS(Data Structures) is a simple project created to serve as practice for myself and proof of work for others.
	<br />
	Originally the goal was to write a set of Data Structures and Algorithms, but due to size this project is now a point of
	practice and education on all the datastructures I can find info on.
	<br />
	The Exactly types of data structures, a few short details, and other relevant info are seperate and listed below.
	<br />
Important updates and notes will also be found here as neccessary:
- Splitting the project into 2 seperate ones due to size, it's compliment will be an algorithms project here: "N/A"

## Data Structures
______________________
### Stack
Standard stack implementation with a single head node that reference the next node in the form of a linked list. 
Stack contains pop and push functions to add and remove from the stack, along with a peek function for viewing.
### Queue
Standard Queue structure, a head and tail node in the form of a doubly linked list.
Contains functions for queuing and dequeuing, along with peeking at the top of the queue.
### Dynamic Array
Basic Array structure which will use c++ new/delete and pointers to create an array that can increase
and decrease in size as needed. Current implementation is simple int array. A pointer array would include
a special delete function for clearing individual pointers.
### Binary search tree
Basic implementation of core functions and leaf node for a  binary search tree. Includes left/right access to leafs
and currently incomplete insert/delete functions.
12/26/22: Implementing Pre/In/Post, Level, zigzag, odd/even traversals before completing my r/b tree due to the
use of traversals and BST deletion operations needed in rb deletions.
### Red/Black Tree
Created tree and leaf class for a red/black sorting tree. Leaf contains left/right nodes along with a set color of 
red(0) or black(1)
### AVL Tree
Set up tree and AVL leaf class using leaf base. Leaf contains left/right and balance factor. Code itself is recursive
to remove parent variable and parent calls.


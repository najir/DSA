# DSA
Isaac Perks 12/5/22
<br />
# Description
_____________________
DS(Data Structures) is a simple project created to serve as practice.
	<br />
	Originally the goal was to write a set of Data Structures and Algorithms, but due to size this project is now a point of
	practice and education on any data structure I find interesting or worth learning.
	<br />
	A current list of Data Structure and small details/info are provided below.
	<br />
Other Comments:
- I tend to lean towards iterative functions where a recursive one may have been simpler. This is inconsistent between
seperate structures
- With AVL tree's nearing completion, I plan to step away from this for a moment and shift to other projects. This project
has taken more time then I expected as it was extremely dry in nature.

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
Created tree and leaf class for a red/black sorting tree. Leaf contains left/right/parent nodes along with a set color of 
red(0) or black(1).
### AVL Tree
Inherited Leaf Node with added balance variable. Balance is checked at each pass of recursion and rotations are applied
as a recursion ends.
### Spanning Tree
N/A


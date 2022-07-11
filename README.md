# Algorithms & data structures
"Having a solid base of algorithmic knowledge and technique is one characteristic that separates the truly skilled programmers from the novices. With modern computing technology, you can accomplish some tasks without knowing much about algorithms, but with a good background in algorithms, you can do much, much more." (Cormen et al. 14)

This repository's goal is to demonstrate how to implement common data structures and algorithms in the C programming language.

## Contributing
If you'd like to add or improve an algorithm your contribution is welcome!

## Data Structures
- [Dynamic Array](./src/main/c/algorithms/datastructures/dynamic-array/dynamic-array.c)	 
- [Linked List](./src/main/c/algorithms/datastructures/linked-list)
	- [Singly Linked List](./src/main/c/algorithms/datastructures/linked-list/linked-list.c)
	- [Doubly Linked List](./src/main/c/algorithms/datastructures/linked-list/doubly-linked-list.c)
- [Queue](./src/main/c/algorithms/datastructures/queue)
	- [Queue (linked list)](./src/main/c/algorithms/datastructures/queue/queue-with-linked-list.c)
	- [Queue (array)](./src/main/c/algorithms/datastructures/queue/queue-with-array.c)
- [Stack](./src/main/c/algorithms/datastructures/stack/stack.c)

## Search Algorithms
- [Binary search (integers)](./src/main/c/algorithms/search/binary-search.c) **- O(log(n))**

## Sort Algorithms
- [Insertion Sort](./src/main/c/algorithms/sort/insertion-sort.c) **- O(n<sup>2</sup>)**
- [Selection Sort](./src/main/c/algorithms/sort/selection-sort.c) **- O(n<sup>2</sup>)**

## Interview Questions
#### Linked-list
- [Reverse a linked list iterativetly](./src/main/c/algorithms/interview-questions/linked-list/reverse-linked-list-iterative-method.c) **- O(n)**
- [Reverse a linked list recursively](./src/main/c/algorithms/interview-questions/linked-list/reverse-linked-list-recursive-method.c) **- O(n) time and space**
- [Return kth to last element of a linked list](./src/main/c/algorithms/interview-questions/linked-list/kth-to-last.c) **- O(n)**
- [Delete the middle node of a linked list](./src/main/c/algorithms/interview-questions/linked-list/delete-middle-node.c) **- O(n)** 
- [Check if a linked list is a palindrome](./src/main/c/algorithms/interview-questions/linked-list/is-palindrome.c) **- O(n) time and space**
- [Given two (singly) linked lists, determine if the two lists intersect](./src/main/c/algorithms/interview-questions/linked-list/intersect.c) **- O(n + m)**
- [Given a circular linked list, implement an algorithm that returns the node at the beginnig of the loop](./src/main/c/algorithms/interview-questions/linked-list/loop-detection.c) **- O(n)**
- [Partition a linked list around a value x](./src/main/c/algorithms/interview-questions/linked-list/partition.c) **- O(n)**
- [Sum two linked lists that represent two numbers in foward order](./src/main/c/algorithms/interview-questions/linked-list/sum-lists-forward-order.c) **- O(n + m) time and space**
- [Sum two linked lists that represent two numbers in reverse order](./src/main/c/algorithms/interview-questions/linked-list/sum-lists-reverse-order.c) **- O(n + m)**

#### Stack
- [Reverse a given string](./src/main/c/algorithms/interview-questions/stack/reverse-string.c)  **- O(n) time and space**
- [Check if a given expression has balanced brackets](./src/main/c/algorithms/interview-questions/stack/has-balanced-brackets.c)  **- O(n) time and space**
- [Convert infix expression to postfix](./src/main/c/algorithms/interview-questions/stack/infix-to-postfix.c) **- O(n) time and space**
- [Evaluate a postfix expression](./src/main/c/algorithms/interview-questions/stack/evaluate-postfix.c)  **- O(n) time and space**
- [Evaluate a prefix expression](./src/main/c/algorithms/interview-questions/stack/evaluate-prefix.c)  **- O(n) time and space**
- [Stack of plates](./src/main/c/algorithms/interview-questions/stack/set-of-stacks.c)

#### Queue
- [Implement a queue with two stacks](./src/main/c/algorithms/interview-questions/queue/queue-with-two-stacks.c)

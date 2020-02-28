// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <iostream>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	// Top of the stack Node.
	Node *top;

	// Integers for size of the Node.
	int maxSize;
	int currentSize;

	Stack(int max){
		top = NULL;
		maxSize = max;
		currentSize = 0;
	}

	void initStack(int s);
	bool isEmpty();
	bool isFull();
	void Push(int data);
	int Pop();
	void Status();
}Stack;


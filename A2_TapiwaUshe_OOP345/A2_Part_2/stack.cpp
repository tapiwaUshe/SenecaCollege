// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <iostream>
#include "stack.h"

void Stack::initStack(int max){
	top = nullptr;
	maxSize = max;
	currentSize = 0;
}

bool Stack::isEmpty(){
	return top == nullptr;
}

bool Stack::isFull() {
	return maxSize == currentSize;
}

void Stack::Push(int data) {
	if(isFull()){
		std::cout << "Stack is Full" << std::endl;
		return;
	}

	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	now->next = top;
	top = now;

	currentSize++;
}

int Stack::Pop(){
	Node *now;
	int re;

	if(isEmpty()) return 0;
	now = top;
	re = now->data;
	top = now->next;
	free(now);

	currentSize--;

	return re;
}


void Stack::Status() {
	Node *now;
	if(isEmpty()) return;
	while (top != nullptr){
		now = top;
		std::cout << now->data;
		top = now->next;
		std::cout << ", ";
	}
	std::cout << "[End of Data]" << std::endl;
}

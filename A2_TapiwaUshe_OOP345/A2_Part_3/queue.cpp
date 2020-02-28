// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <iostream>
#include "queue.h"

void Queue::enQueue(int value)
{
	if(isFull()){
		std::cout << std::endl;
		std::cout << "Queue is Full" << std::endl;
		return;
	}else if(front == -1){
		front = rear = 0;
		arr[rear] = value;
	}else if(rear == size - 1 && front != 0){
		rear = 0;
		arr[rear] = value;
	}else{
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue()
{
	if(isEmpty()){
		std::cout << std::endl;
		std::cout << "Queue is Empty" << std::endl;
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else if(front == size - 1){
		front = 0;
	}else{
		front++;
	}
	return data;
}

void Queue::displayQueue()
{
	if (isEmpty()){
		std::cout << std::endl;
		std::cout << "Queue is Empty" << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << "Elements in Circular Queue are: ";

	if(rear >= front)
		for(int i = front; i <= rear; i++)
			std::cout << arr[i];
	else{
		for(int i = front; i < size; i++)
			std::cout << arr[i];
		for(int i = 0; i <= rear; i++)
			std::cout << arr[i];
	}
	std::cout << std::endl;
}

bool Queue::isEmpty()
{
	return(front == -1);
}


bool Queue::isFull()
{
	return(front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
}

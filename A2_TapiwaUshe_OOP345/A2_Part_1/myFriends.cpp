// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myFriends.h"

void initialize(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}

void insert(void)
{
	Node *node = (Node*)malloc(sizeof(Node));

	char name[10];
	char birthday[8];
	char address[50];
	char num[20];
	inputData(name, birthday, address, num);

	strcpy(node->name, name);
	strcpy(node->birthday, birthday);
	strcpy(node->address, address);
	strcpy(node->num, num);

	if(head->next == tail){
		head->next = node;
		node->prev = head;
		node->next = tail;
		tail->prev = node;
		return;
	}
	else{
		tail->prev->next = node;
		node->prev = tail->prev;
		node->next = tail;
		tail->prev = node;
		return;
	}
}

void display(void)
{
	Node *tmp = head->next;
	std::cout << std::endl;
	std::cout << "Display Friends Contact Information" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	while (tmp != tail)
	{
		std::cout << "Name: " << tmp->name << " ";
		std::cout << "Birthday: " << tmp->birthday << " ";
		std::cout << "Address: " << tmp->address << " ";
		std::cout << "Number: " << tmp->num << std::endl;
		tmp = tmp->next;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	puts("");
}

void deleteData(void)
{
	char name[10];
	Node *node;
	std::cout << std::endl;
	std::cout << "Delete Friend: " << std::endl;
	std::cout << "Enter Your Friend's Name: ";
	std::cin >> name;
	std::cout << std::endl;

	node = head->next;
	while(strcmp(node->name, name) != 0 && node != tail){
		node = node->next;
	}
	if(node == tail) std::cout << " No name matched";
	
	else{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
	}
}

void search(char *input)
{
	Node *tmp;
	tmp = head->next;

	while (strcmp(tmp->name, input) != 0 && tmp != tail)
	{
		tmp = tmp->next;
	}

	if (tmp == tail){	
		std::cout << "There Are No Information" << std::endl;
		std::cout << std::endl;
	}
	else{
		std::cout << "Serach Result" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "Name: " << tmp->name;
		std::cout << " / Birthday: " << tmp->birthday;
		std::cout << " / Address: " << tmp->address;
		std::cout << " / Number: " << tmp->num << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void inputData(char* name, char* birthday, char* address, char* num)
{
	std::cout << std::endl;
	puts("Name:");
	std::cin >> name;
	puts("Birth Day:");
	std::cin >> birthday;
	puts("Address:");
	std::cin >> address;
	puts("Contact Number:");
	std::cin >> num;
	std::cout << std::endl;
}

// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <iostream>
#include "stack.h"

int main()
{
	int selectMenu, stackSize, data;

	std::cout << "Stack Size: ";
	std::cin >> stackSize;

	Stack s(stackSize);

	while (1)
	{
		std::cout << "1. Push" << std::endl;
		std::cout << "2. Pop" << std::endl;
		std::cout << "3. Status" << std::endl;
		std::cout << "4. isEmpty" << std::endl;
		std::cout << "5. isFull" << std::endl;

		std::cout << "9. End of Program" << std::endl;
		std::cout << "----------------" << std::endl;

		std::cin >> selectMenu;

		switch (selectMenu)
		{
			case 1:
				std::cout << "Push Data(int): ";
				std::cin >> data;
				s.Push(data);
			break;
			case 2:
				std::cout << "Pop Data: ";
				std::cout << s.Pop() << std::endl;
			break;
			case 3:
				std::cout << "Status: ";
				s.Status();
			break;
			case 4:
				if(s.isEmpty() == true) std::cout << "Stack is Empty" << std::endl;
				else std::cout << "Stack is not Empty" << std::endl;
			break;
			case 5:
				if(s.isFull() == true) std::cout << "Stack is Full" << std::endl;
				else std::cout << "Stack is not Full" << std::endl;
			break;
			case 9:
				return 0;
			default:
				std::cout << "Wrong Menu Number" << std::endl;
		}
	}
	return 0;
}

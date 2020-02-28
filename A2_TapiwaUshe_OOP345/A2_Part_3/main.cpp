// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <iostream>
#include "queue.h"

int main()
{
	int selectMenu, data;
	Queue q(10);
	while (1)
	{
		std::cout << "1. enQueue" << std::endl;
		std::cout << "2. deQueue" << std::endl;
		std::cout << "3. Status" << std::endl;
		std::cout << "4. isEmpty" << std::endl;
		std::cout << "5. isFull" << std::endl;

		std::cout << "9. End of Program" << std::endl;
		std::cout << "----------------" << std::endl;

		std::cin >> selectMenu;

		switch (selectMenu)
		{
			case 1:
				std::cout << "Insert Data(int): ";
				std::cin >> data;
				q.enQueue(data);
			break;
			case 2:
				printf("\nDeleted value = %d", q.deQueue());
			break;
			case 3:
				q.displayQueue();
			break;
			case 4:
				if (q.isEmpty() == true) std::cout << "Queue is Empty" << std::endl;
				else std::cout << "Queue is not Empty" << std::endl;
			break;
			case 5:
				if(q.isFull() == true) std::cout << "Queue is Full" << std::endl;
				else std::cout << "Queue is not Full" << std::endl;
			break;
			case 9:
				return 0;
		default:
			std::cout << "Wrong Menu Number" << std::endl;
		}
	}
	return 0;
}

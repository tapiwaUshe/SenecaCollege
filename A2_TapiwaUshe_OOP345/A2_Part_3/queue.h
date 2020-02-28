// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

struct Queue
{
	int rear, front, size;
	int *arr;

	Queue(int sZ)
	{
		front = rear = -1;
		size = sZ;
		arr = new int[sZ];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
	bool isFull();
	bool isEmpty();
};

// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

/*
	Typedef safe definition of public user-defined type 'Node'
	Node contains 4 char variables (the data for each Node,) and a pointer of
	type Node to the previous, and next node.
*/

typedef struct Node {
	char name[10];
	char birthday[8];
	char address[50];
	char num[20];
	struct Node* next;
	struct Node* prev;
} Node;

static Node *head;
static Node *tail;

void initialize(void);
void insert(void);
void deleteData(void);	
void display(void);	
void search(char* input);
void inputData(char* name, char* birthday, char* address, char* num);

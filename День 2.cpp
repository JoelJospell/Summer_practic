#include <iostream>
using namespace std;

struct Node 
{
	int val;
	Node* next;
};

void init(int n, Node** node) 
{
	if (n > 0) 
	{
		(*node) = new Node;
		(*node)->val = 0;
		(*node)->next = NULL;
		init(n - 1, &((*node)->next));
	}
}

void init3_2(int n, Node** node) 
{
	if (n > 0) 
	{
		(*node) = new Node();
		cin >> (*node)->val;
		(*node)->next = NULL;
		init3_2(n - 1, &((*node)->next));
	}
}

int show(Node* head) 
{
	cout << head->val << endl;
	if (head->next == NULL) 
	{
		cout << endl;
		return 0;
	}
	show(head->next);
}

void pushNode(Node* head, Node* node) 
{
	Node* current = head;
	for (int i = 1; current->next != NULL; i++) 
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
}

int compareMas(Node* source, Node* dest, int b) 
{
	for (int i = 1; i <= b; i++) 
	{
		if (source->val != dest->val) return -1;
		source = source->next;
		dest = dest->next;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "задача 3.1: " << endl;
	Node* Head;
	Head = new Node;
	Head->next = NULL;
	Head->val = 0;
	Node* node;
	node = new Node;
	node->next = NULL;
	node->val = 1;
	int n;
	cout << "Введите кол-во элементов: ";
	cin >> n;
	init(n - 1, &((Head)->next));
	if (n != 0) show(Head);
	pushNode(Head, node);
	if (n != 0) show(Head);
	cout << "задача 3.2" << endl;
	int m, k;
	cout << "Введите кол-во элементов списка source: ";
	cin >> m;
	cout << "введите элементы списка source: " << endl;
	Node* source;
	source = new Node;
	cin >> source->val;
	source->next = NULL;
	init3_2(m - 1, &((source)->next));
	cout << "Введите кол-во элементов списка dest: ";
	cin >> k;
	cout << "введите элементы списка dest: " << endl;
	Node* dest;
	dest = new Node;
	cin >> dest->val;
	dest->next = NULL;
	init3_2(k - 1, &((dest)->next));
	if (k == m) 
	{
		if (compareMas(source, dest, k) == 0) cout << "EQUAL";
		else cout << " NOT EQUAL";
	}
	else cout << " NOT EQUAL";
}
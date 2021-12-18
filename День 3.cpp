#include <iostream>
#include <math.h>

using namespace std;
const double g = 9.8;

struct Node 
{
	double m;
	double t;
	double h;
	double v;
	Node* next;
};

void Kordinat(double t, double h, double v1, double* v, double* hnew) 
{
	if (h > v1 * t + (g * t * t) / 2) 
	{
		(*hnew) = h - ((g * t * t) / 2);
		(*v) = v1 + g * t;
	}
	if (abs(h - (v1 * t + (g * t * t) / 2)) < 0.00001) 
	{
		(*hnew) = 0;
		(*v) = v1 + g * t;
	}
	if (h < (v1 * t + (g * t * t) / 2)) 
	{
		(*v) = 0;
		(*hnew) = 0;
	}
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

int testPushNode() 
{
	Node* Head;
	Head = new Node;
	Head->next = NULL;
	Head->m = 0;
	Head->t = 0;
	Head->h = 0;
	Head->v = 0;
	Node* ded;
	ded = new Node;
	ded->next = NULL;
	ded->m = 1;
	ded->t = 1;
	ded->h = 1;
	ded->v = 1;
	pushNode(Head, ded);
	if ((Head->m != 0) || (Head->t != 0) || (Head->h != 0) || (Head->v != 0)) return -1;
	Head = Head->next;
	if ((Head->m != 1) || (Head->t != 1) || (Head->h != 1) || (Head->v != 1)) return -1;
	return 0;
}

int testKordinat() 
{
	double v = 0, hnew = 0, v1 = 0;
	Kordinat(0, 10, v1, &v, &hnew);
	if ((v != 0) || (hnew != 10)) return -1;
	Kordinat(1, 4.9, v1, &v, &hnew);
	if (((9.6 - v) > 0.00001) || (hnew != 0)) return -1;
	Kordinat(4, 5, v1, &v, &hnew);
	if ((v != 0) || (hnew != 0)) return -1;
	return 0;
}

int show(Node* head) 
{
	cout << "масса " << head->m << endl;
	cout << "время " << head->t << endl;
	cout << "высота " << head->h << endl;
	cout << "скорость " << head->v << endl;
	if (head->next == NULL) 
	{
		cout << endl;
		return 0;
	}
	show(head->next);
}

void runTest(int (*testfunction)(), string testname) 
{
	if (testfunction() == 0)
		cout << "TEST " << testname << " COMPLETED SUCCSESSFULLY " << endl;
	else
		cout << "TEST " << testname << " FAILD" << endl;
}

int main()
{
	cout.precision(6);
	setlocale(LC_ALL, "Russian");
	bool b = 0;
	Node* Head;
	Head = new Node;
	Head->next = NULL;
	Head->m = 0;
	Head->t = 0;
	Head->h = 0;
	Head->v = 0;
	Node* node;
	node = new Node;
	node->next = NULL;
	node->m = 0;
	node->t = 0;
	node->h = 0;
	node->v = 0;
	double m, h, v, t, hnew, v1;
	runTest(testPushNode, "testPushNode");
	runTest(testKordinat, "testKordinat");
	while (true) 
	{
		cout << "Введите массу шарика в граммах: ";
		cin >> m;
		cout << "Введите высоту шарика в метрах: ";
		cin >> h;
		cout << "Введите время прошедшее после начала полета в секундах: ";
		cin >> t;
		cout << "Введите начальную скорость в метрах в секунду(если скорость направлена вверх, то с -, если вниз, то с +): ";
		cin >> v1;
		Kordinat(t, h, v1, &v, &hnew);
		cout << "скорость: " << v << " высота: " << hnew << endl;
		cout << "добавить резульат в список? Yes: 1, No: 0: ";
		int k, o, r = 0;
		cin >> k;
		if (k == 1) 
		{
			if (b == 0) 
			{
				Head->next = NULL;
				Head->m = m;
				Head->t = t;
				Head->h = hnew;
				Head->v = v;
				b = 1;
			}
			else {
				node->next = NULL;
				node->m = m;
				node->t = t;
				node->h = hnew;
				node->v = v;
				pushNode(Head, node);
			}
		}
		cout << "вывести список? Yes: 1, No: 0: ";
		cin >> r;
		if (r == 1) show(Head);
		double t2, v2, hnew2;
		cout << "Введите промежуток времени между t1 и t2 в секундах: ";
		cin >> t;
		cin >> t2;
		Kordinat(t, h, v1, &v, &hnew);
		Kordinat(t2, h, v1, &v2, &hnew2);
		cout << "изменение скорости: " << abs(v - v2);
		if (v - v2 < 0) cout << " скорость направлена вверх ";
		else cout << " скорость направлена вниз ";
		cout << " изменение высоты: ";
		if (hnew - hnew2 > 0) cout << " шарик опустился на " << abs(hnew - hnew2) << endl;
		else cout << " шарик поднялся на " << abs(hnew - hnew2) << endl;
	}
}

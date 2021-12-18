#include <iostream>
using namespace std;

int TestCompareMas() {
	int source[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int dest[6] = { 0,1,2,3,4,5 };
	if (CompareMas(source, dest, 6) == 0)
		return 0;
	else
		return -1;
}
int CompareMas(int* source[10], int* dest[6], int size) {
	int i = 0;
	if (source[i] = dest[i]) {
		while (i <= size) {
			i++;
		}
	}
	else {
		break;
		return 1
	}
	return 0
}
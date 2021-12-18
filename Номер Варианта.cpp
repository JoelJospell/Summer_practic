#include <iostream>
using namespace std;

void myvariant(int number, int maxvar)
{
	cout << number % maxvar + 1;
}
int main()
{
	int number, maxvar;
	cin >> number;
	cin >> maxvar;
	myvariant(number, maxvar);
}
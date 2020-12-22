#include <iostream>
#include <fstream>

void ReturnTest(int&, int*);

using namespace std;
int main() 
{
	int x = 5, y = 7;
	ReturnTest(x, &y);
	cout << x << " " << y << endl;
	return 0;
}

void ReturnTest(int& x, int* y)
{
	x += 1;
	*y += 1;
	cout << x << " " << *y << endl;
}


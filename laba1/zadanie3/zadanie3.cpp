#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a;
	b = a;
	c = 0;
	for (int i = 1; i < 5; i++)
	{
		c = (c * 10) + (b % 10);
		b = (b / 10);

	}
	cout << c << endl;

	if (a == c)
	{
		cout << "DA" << endl;
	}
	else
	{
		cout << "NET" << endl;
	}

}

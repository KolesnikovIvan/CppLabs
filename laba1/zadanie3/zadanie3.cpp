#include <iostream>
using namespace std;
int main()
{
	int a, b, c, i;
	cin >> a;
	b = a;
	c = 0;
	i = 1;
	for (int i = 1; i < 5; i++)
	{
		c = (c * 10) + (b % 10);
		b = (b / 10);

	}
	cout << c;

	if (a == c)
	{
		cout << "   da";
	}
	else
	{
		cout << "   no";
	}

}

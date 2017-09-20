#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int  n;
	double s=1;
	cin >> (n);
	for (double i = 1; i <= n; i++)
	{
		s *=  1 + 1 / (i*i);
	}
	cout << (s) << endl;
	return (0);
}
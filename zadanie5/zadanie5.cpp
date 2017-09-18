#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i, n, k;
	double s;
	cin >> (n);
	k = 1;
	s = 1;
	for (int i = 1; i < n; i++) {
		k *= i;
		s = s * (1 + 1 / pow(k, 2));
	}
	cout << (s);//ne robit ewe
}
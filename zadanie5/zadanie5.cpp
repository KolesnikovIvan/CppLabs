#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int  n;
	double s=1.0;
	cin >> (n);
	s = 1;
	for (int i = 1; i <= n; i++) {
		s *=  1 + 1 / (double)(i*i);
	}
	cout << (s) << endl;
}
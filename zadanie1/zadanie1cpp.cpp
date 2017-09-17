#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
	const double e = 2.78;
	double x, y, z, a, b;
	cin >> x;
	cin >> y;
	cin >> z;

	a = (3 + pow(e, y - 1)) / (1 + x*x)*abs(y - tan(z));
	b = 1 + abs(y - x) + (pow(y - x, 2) / 2) + (pow(abs(y - x), 3) / 3);
	cout << a;
	cout << "    ";
	cout << b;






}
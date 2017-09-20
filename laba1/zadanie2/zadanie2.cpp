#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, x;
	const double PI = 3.1415926535897;
	cin >> a;
	if (a <= 0)
	{
		cout << "0";

	}
	else
	{
		if ((a > 0) && (a <= 1))
		{
			x = pow(a, 2) - a;
		}
		else

			x = pow(a, 2) - sin(pow(a, 2))*PI;
		{
			cout << (x) << endl;

		}
	}
	return (0);
}
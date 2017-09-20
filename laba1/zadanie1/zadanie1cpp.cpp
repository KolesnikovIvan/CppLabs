#include <iostream> //variant1
#include <cmath>
using namespace std;
int main()
{
	const double e = 2.71;
	double  x,y,a,z, b;
	cout << "vvedite x" << endl;
	cin >> x;
	cout << "vvedite y" << endl;
	cin >> y;
	cout << "vvedite z" << endl;
	cin >> z;

	a = (3 + pow(e, y - 1)) / (1 + x*x)*abs(y - tan(z));
	b = 1 + abs(y - x) + (pow(y - x, 2) / 2) + (pow(abs(y - x), 3) / 3);
	cout <<"a= "<< a << endl;
	cout<<"b=" << b << endl;

	return (0);
}
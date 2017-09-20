#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double z, p;
	cin >>  z;
	double s = 1;
	double x = 1;
	do {
		x++;
		 p = 1 / pow(x, 2);
		s += p;
	} 
	while (abs(p)>z);
	cout << s << endl;
	return(0);

}
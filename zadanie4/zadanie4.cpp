#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int k;
	int c;
	k = 0;
	c = 1;
	while (i != 0) {
		cin >> i;
		if (i == 0)break;
		if (i % 2 == 0) {
			k++;
			c *= i;
		}
	}

	cout << k << endl;
	cout << c << endl;

}




#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	char* i = new char[256];

	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "oshibka";
	}
	int k = 0, count = 0, a[256];
	for (int j = 0; j < 256; j++)
	{
		ifile.get(i, 2);
		if (atoi(i) != 0)
		{
			a[k] = atoi(i);
			cout << "a[" << k << "]=" << a[k] << "\n";
			count = ++count;
			k = ++k;
		}
	}
	delete i;
	ifile.close();

}
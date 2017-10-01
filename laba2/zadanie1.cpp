#include <iostream>
#include <cmath>
using namespace std;
void main()

{
	int arr[10];
	int k = 0;
	for (int i = 1; i < 10; i++)
	{
		cin >> arr[10];
	}
	for (int i = 1; i < 10; i++)
	{
	if (arr[i] > k)
	
		k = i;

	}
	for (int i = 1; i < 10; i++)
	{
		if (abs(arr[i]) == k)
			arr[i] = 1;
		else
			arr[i] = 0;

	}
}
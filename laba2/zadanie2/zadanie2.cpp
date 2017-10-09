/*Дан массив целых чисел размерности n
Изменить этот массив так,
что все элементы, модуль которых не равен максимальному элементу массива,
заменить нулем,
а равные – единицей.
*/

#include <iostream> 
#include <cmath>
using namespace std;
int main()

{
	const int n = 10;
	int i;
	int arr[n];
	int max = 0;
	for (i = 1; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)

			max = arr[i];
		else
			continue;

	}
	for (i = 1; i < n; i++)
	{
		if (abs(arr[i]) != max)
			arr[i] = 0;

		else
			arr[i] = 1;

	}
	for (i = 1; i < n; i++)
		cout << arr[i] << "   ";
	return 0;
}
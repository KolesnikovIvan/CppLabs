/* VARIANT 11
ZADANIE 1
Дан массив действительных чисел а размерности n (n вводится с клавиатуры).
Сформировать массив b, каждый элемент которого bi – среднее арифметическое элементов массива а, исключая ai.
*/

#include <iostream> 
#include <cmath>
using namespace std;

void main()

{

	int n = 1;

	int *a = new int[n];
	double *b = new double[n];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = (sum - a[i]) / (n - 1.0);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "  " << b[i];
	}
	delete[] a;
	delete[] b;


}

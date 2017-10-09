/*Дан массив размерности n (четное). 
В случае если элементы массива упорядочены по возрастанию, удалить элементы массива через один, начиная с первого,
иначе - вставить в середину массива элемент, равный первому,
«нарушающему» условие возрастания.
Дополнительный массив использовать нельзя.
*/

#include <iostream> 


using namespace std;
 int main()
{
	int i, j, n=1;
	int nomer;
	cout << "vvedite chetnoe kollichestvo elementov";
	cin >> n;
	int*Mass = new int[n];
	for (i = 0; i < n; i++)
		cin >> Mass[i];
	for (i = 1; i < n; i++)
		if (Mass[i] < Mass[i - 1])    
		{
			nomer = Mass[i];
			for (j = n; j > n / 2; j--)
				Mass[j] = Mass[j - 1];
			Mass[j] = nomer;
			n++;
			break;
		}
	if (i == n)
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
				Mass[j] = Mass[j+1];
			n--;
		}
	for (i = 0; i < n; i++)
		cout << Mass[i] << ' ';
	delete[] Mass;
	return 0;
}







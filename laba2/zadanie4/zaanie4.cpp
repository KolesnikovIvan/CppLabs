/*4.	Дана матрица размерности nxm. 
Получить одномерный массив a[m], 
хранящий сумму элементов соответствующих столбцов матрицы, 
являющихся простыми числами.*/
#include <iostream>
#include <cmath>
using namespace std;
//Проверка числа на простоту
int prost(int a)
{
	int i, sq = (int)sqrt((double)a);	
	if (a < 2) 
	{
		return 0;
	} 
	for (i = 2; i <= sq; i++) 
	if ((int)a % i == 0) break;	
	if (i == sq + 1) 
		return 1;		//если проверка дошла до числа больше чем корень квадратный из исходного => оно точно простое.		
	else
	{
		return 0;
	}
}

int main()
{
	int n, m;
	int **Matr;	//матрица введенная пользователем	
	int *A;		// полученный массив
	cout << "n: ";		
	cin >> n;	
	cout << "m: ";		
	cin >> m;	
	A = new int[m];	
	Matr = new int*[n];	
	for (int i = 0; i<n; i++)	
	{
		Matr[i] = new int[m];	
		for (int j = 0; j<m; j++)						
		{
			cout << "Matr[" << i + 1 << "][" << j + 1 << "] = ";	
			cin >> Matr[i][j];		
		}
	}
	

	cout << "vasha  Matr:" << endl;	
	for (int i = 0; i < n; i++)			
	{
		for (int j = 0; j < m; j++)						
		{
					
			cout << Matr[i][j] << " ";			
		}
		cout << endl;		
	}

	for (int i = 0; i<m; i++)	
	{
		A[i] = 0;		//изначально сумма простых = 0
		for (int j = 0; j<n; j++)	
		{
			if (prost(Matr[j][i]))	
				A[i] += Matr[j][i];	
		}
	}
	cout << "A:" << endl;


	for (int i = 0; i < m; i++)						
	{
				
		cout << A[i] << " ";		
	}
	cout << endl;


	delete[] Matr;		
	delete[] A;		
	system("pause");	
	return 0;	
}

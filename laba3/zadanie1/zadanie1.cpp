/*В текстовом файле INPUT.TXT записаны целые числа через пробел,
возможно, в несколько строк.
За один просмотр файла, 
без использования сортировки сформировать список этих чисел, 
упорядоченный по неубыванию (каждый следующий элемент списка больше или равен предыдущему).
Значения полученного списка занести в текстовый файл OUTPUT.TXT.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	int m[10000] = {};

	int n;
	while (fin >> n)
		m[n]++;


	ofstream fout("output.txt");
	for (int i = 0; i<10000; i++)
		for (int j = 0; j<m[i]; j++)
			fout << i << " ";
	fin.close();

	fout.close();

	return 0;
}
/*3.	В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.
Проверить наличие в списке заданного числа. Результат (ЕСТЬ или НЕТ) занести в текстовый файл OUTPUT.TXT.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("INPUT.txt");
	ofstream fout("Output.txt");
	int pr;
	int k = 0;
	cin >> pr;

	int* mas = new int[255];
	for (int i = 0; i < 255; i++)
	{
		mas[i] = 0;
	}
	int j = 0;
	while (!fin.eof())
	{
		char* buf = new char[255];
		fin.getline(buf, 255);

		for (int i = 0; i < 255; i++)
		{
			while (isspace(static_cast<unsigned char>(buf[i])))
				++i;
			if (buf[i] == '\0')
				break;
			mas[j] = atoi(buf + i);
			++j;
			while (buf[i] != '\0' && !isspace(static_cast<unsigned char>(buf[i])))
				++i;
			k++;
		}
		bool trr = false;
	
		for (int j = 0; j <k; j++)
		{
			if (mas[j] == pr)
			{
				trr = true;
				break;
			}
		}

		if (trr == true)
		{
			fout << "ЕСТЬ";
			break;
		}

		else
		{
			fout << "HET";
			break;
		}
		
		
	}
	fin.close();
	fout.close();

	return 0;
}



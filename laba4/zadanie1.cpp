#include <iostream>

using namespace std;


struct students
{
	char surname[100];
	char name[10];
	char otch[10];
	int group;
	int mark[5];
};

int main()
{
	setlocale(LC_ALL, "Russian");
	const int k = 2;
	int n = 0;
	students *student = new students[k];
	double *average = new double[k];
	int x = 0;

	for (int i = 1; i <= k; i++)
	{

		cout << "Введите Фaмилию студента №" << i << endl;
		cin >> student[i].surname;

		cout << "Введите имя студента №" << i << endl;
		cin >> student[i].name;
		cout << "Введите отчество студента №" << i << endl;
		cin >> student[i].otch;

		cout << "Введите номер группы студента № " << i << endl;
		cin >> student[i].group;
		cout << "Введите оценки по 5 предметам студента №" << i << endl;

		for (int predmet = 1; predmet <= 5; predmet++)
		{
			cin >> student[i].mark[predmet];

			x += student[i].mark[predmet];

		}
		average[i] = x / 5;
		x = 0;
		n++;

	}
	for (int i = 1; i < n; i++)
	{
		for (int i = 1; i < n; i++)
		{
			if (student[i - 1].group > student[i].group)
			{
				swap(student[i].surname, student[i - 1].surname);
				swap(student[i].name, student[i - 1].name);
				swap(student[i].otch, student[i - 1].otch);
				swap(student[i].mark, student[i - 1].mark);
				swap(student[i].group, student[i - 1].group);

			}
		}
	}
	int z = 0;
	cout << "ученики со средним баллом больше 4-х" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (average[i] >= 4)
		{
			cout << student[i].name << "   ";
			cout << student[i].surname << "   ";
			cout << student[i].otch << "   ";

			cout << student[i].group << endl;
		}

	}
	delete[] student;
	return 0;
}









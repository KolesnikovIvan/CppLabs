/*¬ариант 1
ќписать структуру с именем student, содержащую следующие пол€:
Х	фамили€, им€, отчество;
Х	номер группы;
Х	успеваемость по 5 предметам (массив оценок).

Ќаписать программу, выполн€ющую следующие действи€:
Х	ввод с клавиатуры данных в массив, состо€щий из максимум 10 элементов типа student, 
причем сделать возможность прервать ввод, чтобы можно было не вводить все 10 элементов;
после окончани€ ввода отсортировать элементы массива по возрастанию номера группы;

Х	вывод в консоль фамилий и инициалов, а также номеров групп всех студентов, 
включенных в массив, если средний балл студента больше 4.0;
Х	если таких студентов нет, вывести соответствующее сообщение;
*/

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
	int k;
	cout << "¬ведите кол-во студннтов" << endl;
	cin >> k;
	int cnt = 0;
	students *student = new students[k];
	double *average = new double[k];
	int x = 0;


	for (int i = 1; i <= k; i++)
	{

		cout << "¬ведите ‘aмилию студента є" << i << endl;
		cin >> student[i].surname;

		cout << "¬ведите им€ студента є" << i << endl;
		cin >> student[i].name;
		cout << "¬ведите отчество студента є" << i << endl;
		cin >> student[i].otch;

		cout << "¬ведите номер группы студента є " << i << endl;
		cin >> student[i].group;
		cout << "¬ведите оценки по 5 предметам студента є" << i << endl;

		for (int predmet = 1; predmet <= 5; predmet++)
		{
			cin >> student[i].mark[predmet];

			x += student[i].mark[predmet];

		}
		average[i] = x / 5;
		x = 0;
		cnt++;

	}
	for (int i = 1; i < cnt; i++)
	{
		for (int i = 1; i < cnt; i++)
		{
			if (student[i + 1].group < student[i].group)
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
	cout << " ученики со средним баллом больше 4-х" << endl;
	for (int i = 1; i <= cnt; i++)
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
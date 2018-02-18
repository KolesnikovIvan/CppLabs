
/*Вариант 1
Описать структуру с именем student, содержащую следующие поля:
•	фамилия, имя, отчество;
•	номер группы;
•	успеваемость по 5 предметам (массив оценок).
Написать программу, выполняющую следующие действия:
•	ввод с клавиатуры данных в массив, состоящий из максимум 10 элементов типа student,
причем сделать возможность прервать ввод, чтобы можно было не вводить все 10 элементов;
после окончания ввода отсортировать элементы массива по возрастанию номера группы;
•	вывод в консоль фамилий и инициалов, а также номеров групп всех студентов,
включенных в массив, если средний балл студента больше 4.0;
•	если таких студентов нет, вывести соответствующее сообщение;
*/

#include <iostream>

using namespace std;


struct students
{
	char surname[100];
	char name[10];
	char otch[10];
	short int group;
	short int mark[5];
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	int dv = 0;
	cout << "Введите кол-во студннтов" << endl;
	cin >> k;
	int cnt = 0;
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
		cnt++;

	}
	for (int i = 1; i < cnt; i++)
	{
		for (int i = 1; i < cnt; i++)
		{
			if (student[i + 1].group < student[i].group)
			{

				swap(student[i], student[i - 1]);

			}
		}
	}
	
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
		if (average[i] < 4)
		{
			dv++;
		}
		if (dv == 0)
		{
			cout << "ошибка нет хорошистов";
		}


	}
	delete[] student;
	delete[] average;
	return 0;
}
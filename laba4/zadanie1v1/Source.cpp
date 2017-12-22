/*������� 1
������� ��������� � ������ student, ���������� ��������� ����:
�	�������, ���, ��������;
�	����� ������;
�	������������ �� 5 ��������� (������ ������).

�������� ���������, ����������� ��������� ��������:
�	���� � ���������� ������ � ������, ��������� �� �������� 10 ��������� ���� student, 
������ ������� ����������� �������� ����, ����� ����� ���� �� ������� ��� 10 ���������;
����� ��������� ����� ������������� �������� ������� �� ����������� ������ ������;

�	����� � ������� ������� � ���������, � ����� ������� ����� ���� ���������, 
���������� � ������, ���� ������� ���� �������� ������ 4.0;
�	���� ����� ��������� ���, ������� ��������������� ���������;
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
	cout << "������� ���-�� ���������" << endl;
	cin >> k;
	int cnt = 0;
	students *student = new students[k];
	double *average = new double[k];
	int x = 0;


	for (int i = 1; i <= k; i++)
	{

		cout << "������� �a����� �������� �" << i << endl;
		cin >> student[i].surname;

		cout << "������� ��� �������� �" << i << endl;
		cin >> student[i].name;
		cout << "������� �������� �������� �" << i << endl;
		cin >> student[i].otch;

		cout << "������� ����� ������ �������� � " << i << endl;
		cin >> student[i].group;
		cout << "������� ������ �� 5 ��������� �������� �" << i << endl;

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
	cout << " ������� �� ������� ������ ������ 4-�" << endl;
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
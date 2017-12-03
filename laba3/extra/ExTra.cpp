/*Дан файл INPUT.txt. В нем записаны данные работников компании: ФИО, год рождения и зарплата. 
За один просмотр файла найдите ФИО и возраст самого высокооплачиваемого работника, который младше 35 лет. Ответ выведите в файл OUTPUT.txt
Примечание: Возраст это разница текущего года 2017 и года рождения.

Файл INPUT.txt:
Иванов;Иван;Иванович;1952;10000
Петров;Петр;Петрович;1995;8000
Сидоров;Сидр;Сидорович;1991;15000
Богатырев;Богатырь;Богатырович;1993;12000

Файл OUTPUT.txt:
Сидоров Сидр Сидорович
возраст: 26
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct rabotnik
{
	string surname;
	string firstname;
	string otch;
	int date;
	int pay;
};

int main()
{

	const int god = 2017;
	const int maxold = 35;

	ifstream infile("input.txt");
	ofstream outfile("output.txt");

	{
		bool flag = false;
		rabotnik *temp = new rabotnik();
		rabotnik  *osn= nullptr;
		int age = 0;
		string buf;
		while (infile >> buf)
		{
			stringstream Sstream;
			for (const char &Ch : buf)
			{
				Sstream << (Ch == ';' ? ' ' : Ch);
			}
			Sstream >> temp->surname >> temp->firstname >> temp->otch >> temp->date >> temp->pay;
			{
				int tmpold = (god - temp->date);
				if (tmpold < maxold)
				{
					if (!flag)
					{
					    flag = true;
						osn = new rabotnik();
						swap(temp, osn);
						swap(tmpold, age);
					}
					else
					{
						if (temp->pay > osn->pay)
						{
							swap(temp, osn);
							swap(tmpold, age);
						}
					}
				}
			}
		}
		delete temp;
		if (osn != nullptr)
		{

			outfile << osn->surname << "  " << osn->firstname << "  " << osn->otch<<
				endl<< "  " << "VOZRAST= " << age << endl;
		}
	}
}
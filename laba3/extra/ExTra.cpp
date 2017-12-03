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
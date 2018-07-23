#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std;

template <class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *Prev, *Next;
	};
	int quantity = 0;
	Node *Head, *Tail;
public:
	List() {
		Head = NULL;
		Tail = NULL;
	};
	~List() {
		while (Head) {
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	};
	T operator[](int _id) {
		Node *Temp = Head;
		int count = 0;
		while (Temp != NULL) {
			if (count == _id) return Temp->data;
			Temp = Temp->Next;
			count++;
		}
		return {};
	};
	void Add(T _data) {
		Node* newNode = new Node;
		newNode->data = _data;
		newNode->Next = NULL;

		if (Head == NULL) {
			newNode->Prev = NULL;
			Head = Tail = newNode;
		}
		else {
			newNode->Prev = Tail;
			Tail->Next = newNode;
			Tail = newNode;
		}

		quantity++;
	};
	void DeleteById(int _id) {
		if (_id < 0 || _id >= quantity)
			return;
		Node *Temp = Head;
		Node *Helping = Head;

		for (int i = 0; i < _id; i++) {
			Helping = Temp;
			Temp = Temp->Next;
		}

		if (Temp == Head) Head = Temp->Next;
		else if (Temp == Tail) Tail = Helping;
		else Helping->Next = Temp->Next;

		delete Temp;
		quantity--;
	};
	int size() {
		return quantity;
	};



};
class MyString
{
	char *str;
};


struct flightData {
	string destination;
	int num;
	string fio;
	string date;
	//char* destination = new char[100]; 
	//int num; 
	//char* fio = new char[100]; 
	//char* date = new char[100]; 
};

class Despetcher
{

private:List<flightData> flightlist;

		// string _str; int num; 
		//добавить сюда flightdata 
		//убрать flightdata из поиска 
		//убрать string не библиотеку ( оставить getline) 

public:
	flightData parseFlightData(string _str)
	{
		int pos1 = _str.find(",");
		string first = _str.substr(0, pos1);
		int pos2 = _str.find(",", pos1 + 2);
		int second = stoi(_str.substr(pos1 + 2, pos2 - pos1 - 2));
		int pos3 = _str.find(",", pos2 + 2);
		string third = _str.substr(pos2 + 2, pos3 - pos2 - 2);
		int pos4 = _str.find(",", pos3 + 2);
		string fourth = _str.substr(pos3 + 2, pos4 - pos3 - 2);
		return { first, second, third, fourth };
	}
	void search(int num)
	{
		for (int i = 0; i < flightlist.size(); i++)
		{
			if (flightlist[i].num == num)
				cout << flightlist[i].destination << ", "
				<< flightlist[i].num << ", " << flightlist[i].fio
				<< ", " << flightlist[i].date << endl;
		}
	}

};



int main()
{
	setlocale(LC_ALL, "Russian");
	Despetcher FlightDate;
	Despetcher SearchDate;
	List<flightData> flightlist;

	ifstream fin("data.txt");
	if (fin) {
		while (fin) {
			string entry;
			getline(fin, entry);
			if (entry == "") break;
			flightlist.Add(FlightDate.parseFlightData(entry));
		}
	}
	fin.close();

	while (true)
	{
		cout << "\nУчет заявок на авиабилеты:";
		cout << "\n0 -> Выход";
		cout << "\n1 -> Добавить заявку";
		cout << "\n2 -> Удалить заявку";
		cout << "\n3 -> Все заявки";
		cout << "\n4 -> Поиск заявки по номеру рейса \n";
		int input;
		cin >> input;
		if (input == 0) break;
		switch (input)
		{
		case 1:
		{
			cout << "Введите пункт назначения, номер рейса, ";
			cout << "фамилию с инициалами и желаемую дату ";
			cout << "вылета через запятую:\n";
			cin >> ws;
			string entry;
			getline(cin, entry);
			flightlist.Add(FlightDate.parseFlightData(entry));
			cout << "Заявка добавлена.\n";
			break;
		}
		case 2:
		{
			cout << "Введите номер заявки для удаления:\n";
			int id;
			cin >> id;
			flightlist.DeleteById(id);
			cout << "Заявка удалена.\n";
			break;
		}
		case 3: {
			cout << "Все заявки (" << flightlist.size() << "):\n";
			for (int i = 0; i < flightlist.size(); i++)
			{
				cout << i << ". " << flightlist[i].destination
					<< ", " << flightlist[i].num
					<< ", " << flightlist[i].fio
					<< ", " << flightlist[i].date << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите номер рейса :\n";
			int n;
			string date;
			cin >> n >> date;
			SearchDate.search(n);
			break;
		}
		}

	}

	ofstream of("data.txt");
	if (of)
	{
		string entry;
		for (int i = 0; i < flightlist.size(); i++) 
		{
			of << flightlist[i].destination
				<< ", " << flightlist[i].num
				<< ", " << flightlist[i].fio
				<< ", " << flightlist[i].date << endl;
		}
	}
	of.close();
}
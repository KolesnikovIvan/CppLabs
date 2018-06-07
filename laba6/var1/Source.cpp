#include<iostream>
#include<conio.h>

using namespace std;


class Complex
{
private:
	double real, image;

public:

	void Set()
	{
		double Re, Im;
		cout << "������� ����� ����� : ";
		cin >> Re;
		cout << "������� ������ ����� : ";
		cin >> Im;
		this->real = Re;
		this->image = Im;
	}

	Complex()
	{

		this->real = 0;
		this->image = 0;
	}

	Complex(const Complex &other)
	{
		this->real = other.real;
		this->image = other.image;
	}

	Complex & operator = (const Complex &other)
	{
		this->real = other.real;
		this->image = other.image;
		return *this;
	}

	Complex operator - (const Complex &other)
	{
		Complex temp;
		temp.real = this->real - other.real;
		temp.image = this->image - other.image;
		return temp;
	}

	Complex operator * (const Complex &other)
	{
		Complex temp;
		temp.real = this->real * other.real - this->image * other.image;
		temp.image = this->real * other.image + this->image * other.real;
		return temp;

	}

	Complex operator + (const Complex &other)
	{
		Complex temp;
		temp.real = this->real + other.real;
		temp.image = this->image + other.image;
		return temp;
	}





	friend ostream &operator <<(ostream &out, Complex &p)

	{
		out << "��������� : " << p.real << " + " << p.image << " * -i" << endl;
		return out;
	}




};

int main()
{
	setlocale(LC_ALL, "Russian");
	Complex x, y, z;
	bool the_end = false;
	while (the_end == false)
	{
		cout << "��� �� ������ �������?" << endl;
		cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ " << endl;
		cout << "1.������ ����������� �����" << endl;
		cout << "2.�������� ����������� �����" << endl;
		cout << "3.��������� ������������ �����" << endl;
		cout << "4.��������� ����������� �����" << endl;
		cout << "5.����� �� ����." << endl;
		cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ " << endl;

		switch (_getch())
		{
		case '1':
		{
			cout << "������ �����." << endl;
			x.Set();
			cout << endl;
			cout << "������ �����." << endl;
			y.Set();
			break;

		}

		case '2':
		{
			z = x + y;
			cout << z;

			break;

		}

		case '3':
		{
			z = x - y;
			cout << z;

			break;
		}

		case '4':
		{
			z = x * y;
			cout << z;

			break;
		}

		case '5':
		{

			the_end = true;
			break;
		}

		default:
		{
			cout << "������� ��� ���." << endl;
			break;

		}

		}


	}



}
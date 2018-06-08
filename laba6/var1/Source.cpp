/*Составить описание класса для представления комплексных чисел. 
Обеспечить выполнение операций сложения, 
вычитания и умножения комплексного числа на вещественное число.
Предусмотреть поддержку числа в алгебраической форме. 
Все операции реализовать в виде перегрузки операторов.
Программа должна содержать меню, 
позволяющее осуществлять проверку всех методов.
*/

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
		cout << "Введите целую часть : ";
		cin >> Re;
		cout << "Введите мнимую часть : ";
		cin >> Im;
		this->real = Re;
		this->image = Im;
	}

	Complex()
	{

		this->real = 0;
		this->image = 0;
	}

	Complex(const Complex &n_this)
	{
		this->real = n_this.real;
		this->image = n_this.image;
	}

	Complex & operator = (const Complex n_this)
	{
		this->real = n_this.real;
		this->image = n_this.image;
		return *this;
	}

	Complex operator - (const Complex &n_this)
	{
		Complex temp;
		temp.real = this->real - n_this.real;
		temp.image = this->image - n_this.image;
		return temp;
	}

	Complex operator * (const Complex &n_this)
	{
		Complex temp;
		temp.real = this->real * n_this.real - this->image * n_this.image;
		temp.image = this->real * n_this.image + this->image * n_this.real;
		return temp;

	}

	Complex operator + (const Complex &n_this)
	{
		Complex temp;
		temp.real = this->real + n_this.real;
		temp.image = this->image + n_this.image;
		return temp;
	}





	friend ostream &operator <<(ostream &out, Complex &p)

	{
		out << "Результат : " << p.real << " + " << p.image << " * -i" << endl;
		return out;
	}




};

int main()
{
	setlocale(LC_ALL, "Russian");
	Complex x, y, answer;
	bool the_end = false;
	while (the_end == false)
	{
		cout << "Что вы хотите сделать?" << endl;
		cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ " << endl;
		cout << "1.Задать комплексное число" << endl;
		cout << "2.Вычитание" << endl;
		cout << "3.Cложение " << endl;
		cout << "4.Умножение" << endl;
		cout << "5.Выход из меню." << endl;
		cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ " << endl;

		switch (_getch())
		{
		case '1':
		{
			cout << "Первое число." << endl;
			x.Set();
			cout << endl;
			cout << "Второе число." << endl;
			y.Set();
			break;

		}

	
		case '2':
		{
			answer= x - y;
			cout << answer;

			break;
		}
		case '3':
		{
			answer = x + y;
			cout << answer;

			break;

		}

		case '4':
		{
			answer = x * y;
			cout << answer;

			break;
		}

		case '5':
		{

			the_end = true;
			break;
		}

		default:
		{
			cout << "Введите ещё раз." << endl;
			break;

		}

		}


	}



}
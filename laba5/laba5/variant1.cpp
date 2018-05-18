/*
Вариант 1
Построить систему классов для описания плоских геометрических фигур: 
круга, квадрата, прямоугольника. Предусмотреть методы для создания объектов,
перемещения на плоскости на заданный вектор, изменения размеров относительно геометрического центра фигуры,
вращения на заданный угол и определение факта пересечения (наложения) двух выбранных фигур. Программа должна содержать меню,
позволяющее осуществлять проверку всех методов.
*/

#include <iostream>
#include <conio.h>
using namespace std;

class Figure
{
public:

	virtual void Create()
	{

	}
	virtual void Move()
	{

	}
	virtual void Size()
	{

	}
	virtual void Output()
	{

	}
	virtual void Turn()
	{

	}
protected:
	int x, y, rad, movex, movey, drad;
};
class Circle : public Figure// круг
{
	void Create()
	{
		cout << endl;
		cout << " oooooooo" << endl;
		cout << "oooooooooo" << endl;
		cout << "oooooooooo" << endl;
		cout << "oooooooooo" << endl;
		cout << " oooooooo" << endl;
		cout << endl;
		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите радиус" << endl;
		cout << "Радиус = ";
		cin >> rad;
	}
	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
	}
	void Size()
	{
		bool temp;
		cout << "Увеличить или уменьшить фигуру?" << endl;
		cout << "1 - Увеличить." << endl;
		cout << "2 - Уменьшить." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "Увеличить на: ";
			cin >> drad;
			rad += drad;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "Уменьшить на: ";
				cin >> drad;
				if (drad > rad)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
					continue;
				}
				rad -= drad;
				temp = true;
			}
			break;
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Радиус = " << rad << endl;
	}
};
class Square : public Figure //квадрат
{
	int x, y, movex, movey, edge, sizedge;
	double degree;
public:
	void Create()
	{
		cout << endl;
		cout << "   oooooooooo" << endl;
		cout << "   oooooooooo" << endl;
		cout << "   oooooooooo" << endl;
		cout << "   oooooooooo" << endl;
		cout << "   oooooooooo" << endl;
		cout << endl;
		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите длину стороны: " << endl;
		cout << "Длина стороны = ";
		cin >> edge;
	}

	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
	}
	void Size()
	{
		bool temp;
		cout << "Увеличить или уменьшить фигуру?" << endl;
		cout << "1 - Увеличить." << endl;
		cout << "2 - Уменьшить" << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "Увеличить на: ";
			cin >> sizedge;
			edge += sizedge;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "Уменьшить на: ";
				cin >> sizedge;
				if (sizedge > edge)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
					continue;
				}
				edge -= sizedge;
				temp = true;
			}
			break;
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Turn()
	{
		double degree;

		cout << "Введите угол поворота фигуры: ";
		cin >> degree;
	
	


	}
	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Длина стороны = " << edge <<" Повернуто на = " << degree << endl;
	}
};
class Rect/* rectangle */ : public Figure
{
	int x, y, movex, movey, height, width, sheight, swidth, perim, x1, x2, y1, y2;
	double degree;
public:
	void Create()
	{
		cout << endl;
		cout << "   oooooooooooooooooooo" << endl;
		cout << "   oooooooooooooooooooo" << endl;
		cout << "   oooooooooooooooooooo" << endl;
		cout << "   oooooooooooooooooooo" << endl;
		cout << "   oooooooooooooooooooo" << endl;
		cout << endl;

		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите ширину:" << endl;
		cout << "Ширина = ";
		cin >> width;
		cout << "Введите длину:" << endl;
		cin >> height;
		x1 = x - width / 2;
		x2 = x - width / 2;
		y1 = y - height / 2;
		y2 = y - height / 2;
	}
	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
		x1 += movex;
		x2 += movex;
		y1 += movey;
		y2 += movey;
	}
	void Size()
	{
		cout << "1 - Увеличить размер." << endl;
		cout << "2 - Уменьшить размер." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "1 - Увеличить ширину." << endl;
			cout << "2 - Увеличить длину." << endl;
			cout << "3 - Увеличить и ширину и длину." << endl;
			switch (_getch())
			{
			case'1':
			{
				cout << "Увеличить ширину на ";
				cin >> swidth;
				width += swidth;
				break;
			}
			case '2':
			{

				cout << "Увеличить длину на ";
				cin >> sheight;
				height += sheight;
				break;

			}
			case '3':
			{
				cout << "Увеличить и ширину и длину на";
				cin >> sheight;
				height += sheight;
				width += swidth;
				break;
			}
			default:
			{
				cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
				_getch();
				system("cls");
				Size();
			}
			}
			break;
		}
		case'2':
		{
			bool temp;
			cout << "1 - Уменьшить ширину." << endl;
			cout << "2 - Уменьшить длину." << endl;
			cout << "3 - Уменьшить и ширину и длину." << endl;
			switch (_getch())
			{
			case'1':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить ширину на ";
					cin >> swidth;
					if (swidth > width)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					width -= swidth;
					temp = true;
				}
				break;
			}
			case '2':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить длину на ";
					cin >> sheight;
					if (sheight > height)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					height -= sheight;
					temp = true;
				}
				break;
			}
			case '3':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить и ширину и длину на ";

					cin >> sheight;
					if (sheight > height || swidth > width)
					{
						cout << "Ошибка.уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					height -= sheight;
					width -= swidth;
					temp = true;
				}
				break;
			}
			default:
			{
				cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
				_getch();
				Size();
			}
			}
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Turn()
	{
		double degree;

		cout << "Введите угол поворота фигуры: ";
		cin >> degree;

	}

	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Длина = " << height << " Ширина = " << width << " Повернуто на = " << degree/180  <<"*PI" <<endl;

	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Figure **mainF = new Figure *[5];
	int next = -1;
	Circle *c = new Circle;
	Figure *cir = c;
	Square *s = new Square;
	Figure *sq = s;
	Rect *r = new Rect;
	Figure *rect = r;
	bool check = false;
	int type;
	while (1)
	{
		while (!check)
		{
			check = false;
			cout << "Выберите Фигуру: " << endl;
			cout << "1 - Квадрат" << endl;
			cout << "2 - Круг" << endl;
			cout << "3 - Прямоугольник" << endl;
			switch (_getch())
			{
			case '1':
			{
				type = 2;
				next++;
				sq = s;
				mainF[next] = sq;
				check = true;
				break;
			}
			case '2':
			{
				type = 1;
				next++;
				cir = c;
				mainF[next] = cir;
				check = true;
				break;
			}
		
			case '3':
			{
				type = 3;
				next++;
				rect = r;
				mainF[next] = rect;
				check = true;
				break;
			}
			default:
			{
				cout << "Ошибка.Введите цирфы." << endl;
				system("cls");
				break;
			}
			}
		}

		mainF[next]->Create();
		int type2;
		bool check1 = false;
		while (!check1)
		{

			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			cout << "Что вам от меня нужно?" << endl;
			cout << "1 - Cдвинуть?" << endl;
			cout << "2 - Изменить размер?" << endl;
			cout << "3 - Повернуть?" << endl;
			cout << "4 - Характеристики (текущие)." << endl;
			cout << "5 - Выйти." << endl;
			cout << "6 - Ввести новую фигуру." << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			switch (_getch())
			{
			case'1':
			{
				type2 = 2;
				cout << "Сдвинуть на: " << endl;
				cout << "По X и Y ";
				mainF[next]->Move();
				mainF[next]->Output();
				break;
			}
			case'2':
			{
				type2 = 1;
				mainF[next]->Size();
				mainF[next]->Output();
				break;
			}
		
			case'3':
			{
				type2 = 3;
				if (type == 1)
				{
					cout << endl << "Зачем вращать круг???" << endl << endl;
					break;
				}
				else
				{
					cout << "Повернуть на: " << endl;
					mainF[next]->Turn();
					break;
				}
			}
			case '4':
			{
				mainF[next]->Output();
				break;
			}
			case'5':
			{
				exit(0);
			}
			case'6':
			{
				system("cls");
				main();
			}
			default:
			{
				cout << "Ошибка.Введите цирфы." << endl;

				break;
			}
			}
		}
	}

}
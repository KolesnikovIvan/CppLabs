/*
������� 1
��������� ������� ������� ��� �������� ������� �������������� �����: 
�����, ��������, ��������������. ������������� ������ ��� �������� ��������,
����������� �� ��������� �� �������� ������, ��������� �������� ������������ ��������������� ������ ������,
�������� �� �������� ���� � ����������� ����� ����������� (���������) ���� ��������� �����. ��������� ������ ��������� ����,
����������� ������������ �������� ���� �������.
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
class Circle : public Figure// ����
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
		cout << "������� ���������� ������: " << endl;
		cout << "����� X = ";
		cin >> x;
		cout << "����� Y = ";
		cin >> y;
		cout << "������� ������" << endl;
		cout << "������ = ";
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
		cout << "��������� ��� ��������� ������?" << endl;
		cout << "1 - ���������." << endl;
		cout << "2 - ���������." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "��������� ��: ";
			cin >> drad;
			rad += drad;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "��������� ��: ";
				cin >> drad;
				if (drad > rad)
				{
					cout << "������������ ����, ����������� �������� ������ ���� ������ �������� ����������." << endl;
					continue;
				}
				rad -= drad;
				temp = true;
			}
			break;
		}
		default:
		{
			cout << "������������ ����. ���������� ��� ���." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Output()
	{
		cout << "����� x = " << x << " ����� y = " << y << " ������ = " << rad << endl;
	}
};
class Square : public Figure //�������
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
		cout << "������� ���������� ������: " << endl;
		cout << "����� X = ";
		cin >> x;
		cout << "����� Y = ";
		cin >> y;
		cout << "������� ����� �������: " << endl;
		cout << "����� ������� = ";
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
		cout << "��������� ��� ��������� ������?" << endl;
		cout << "1 - ���������." << endl;
		cout << "2 - ���������" << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "��������� ��: ";
			cin >> sizedge;
			edge += sizedge;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "��������� ��: ";
				cin >> sizedge;
				if (sizedge > edge)
				{
					cout << "������������ ����, ����������� �������� ������ ���� ������ �������� ����������." << endl;
					continue;
				}
				edge -= sizedge;
				temp = true;
			}
			break;
		}
		default:
		{
			cout << "������������ ����. ���������� ��� ���." << endl;
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

		cout << "������� ���� �������� ������: ";
		cin >> degree;
	
	


	}
	void Output()
	{
		cout << "����� x = " << x << " ����� y = " << y << " ����� ������� = " << edge <<" ��������� �� = " << degree << endl;
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

		cout << "������� ���������� ������: " << endl;
		cout << "����� X = ";
		cin >> x;
		cout << "����� Y = ";
		cin >> y;
		cout << "������� ������:" << endl;
		cout << "������ = ";
		cin >> width;
		cout << "������� �����:" << endl;
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
		cout << "1 - ��������� ������." << endl;
		cout << "2 - ��������� ������." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "1 - ��������� ������." << endl;
			cout << "2 - ��������� �����." << endl;
			cout << "3 - ��������� � ������ � �����." << endl;
			switch (_getch())
			{
			case'1':
			{
				cout << "��������� ������ �� ";
				cin >> swidth;
				width += swidth;
				break;
			}
			case '2':
			{

				cout << "��������� ����� �� ";
				cin >> sheight;
				height += sheight;
				break;

			}
			case '3':
			{
				cout << "��������� � ������ � ����� ��";
				cin >> sheight;
				height += sheight;
				width += swidth;
				break;
			}
			default:
			{
				cout << "������������ ����. ���������� ��� ���." << endl;
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
			cout << "1 - ��������� ������." << endl;
			cout << "2 - ��������� �����." << endl;
			cout << "3 - ��������� � ������ � �����." << endl;
			switch (_getch())
			{
			case'1':
			{
				temp = false;
				while (temp == false)
				{
					cout << "��������� ������ �� ";
					cin >> swidth;
					if (swidth > width)
					{
						cout << "������������ ����, ����������� �������� ������ ���� ������ �������� ����������." << endl;
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
					cout << "��������� ����� �� ";
					cin >> sheight;
					if (sheight > height)
					{
						cout << "������������ ����, ����������� �������� ������ ���� ������ �������� ����������." << endl;
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
					cout << "��������� � ������ � ����� �� ";

					cin >> sheight;
					if (sheight > height || swidth > width)
					{
						cout << "������.����������� �������� ������ ���� ������ �������� ����������." << endl;
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
				cout << "������������ ����. ���������� ��� ���." << endl;
				_getch();
				Size();
			}
			}
		}
		default:
		{
			cout << "������������ ����. ���������� ��� ���." << endl;
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

		cout << "������� ���� �������� ������: ";
		cin >> degree;

	}

	void Output()
	{
		cout << "����� x = " << x << " ����� y = " << y << " ����� = " << height << " ������ = " << width << " ��������� �� = " << degree/180  <<"*PI" <<endl;

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
			cout << "�������� ������: " << endl;
			cout << "1 - �������" << endl;
			cout << "2 - ����" << endl;
			cout << "3 - �������������" << endl;
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
				cout << "������.������� �����." << endl;
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
			cout << "��� ��� �� ���� �����?" << endl;
			cout << "1 - C�������?" << endl;
			cout << "2 - �������� ������?" << endl;
			cout << "3 - ���������?" << endl;
			cout << "4 - �������������� (�������)." << endl;
			cout << "5 - �����." << endl;
			cout << "6 - ������ ����� ������." << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			switch (_getch())
			{
			case'1':
			{
				type2 = 2;
				cout << "�������� ��: " << endl;
				cout << "�� X � Y ";
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
					cout << endl << "����� ������� ����???" << endl << endl;
					break;
				}
				else
				{
					cout << "��������� ��: " << endl;
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
				cout << "������.������� �����." << endl;

				break;
			}
			}
		}
	}

}
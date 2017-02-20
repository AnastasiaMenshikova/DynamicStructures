#include "stdafx.h"
#include "stack.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int mn, data, range, amount, error; // data - информационное поле
	Stack a;
	Stack::iterater iter;

	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "1)Добавить один элемент в стек" << endl;
		cout << "2)Добавить рандомный(ые) элемент(ы)" << endl;
		cout << "3)Удалить элемент из стека" << endl;
		cout << "4)Очистить стек" << endl;
		cout << "5)Поиск элемента в стеке по значению" << endl;
		cout << "6)Просмотр элементов стека" << endl;
		cout << "Нажмите 0 для выхода из программы" << endl;
		cin >> mn;

		if (mn < 0 || mn>6)
		{
			cout << "Ошибка! Необходимо ввести число от 1 до 6 или 0 для выхода." << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
		}
		switch (mn)
		{


			case 1:
			{
				system("cls");
				error = 1;
				for (;;)
				{
					cout << "Введите одно значение для добавления в стек:" << endl;
					if ((cin >> data) && (cin.good()))
					{
						break;
					}
					else
					{
						if (error == 1)
						{
							error = 0;
							cout << "\n Некорректное значение. Введите число:" << endl;
							system("pause");
						}

						cin.clear();
						cin.ignore();
						system("cls");
					}
				}
				a.push(data);
				system("cls");
				cout << "Элемент был успешно добавлен." << endl;
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				for (;;)
				{
					cout << "Введите количество элементов:" << endl;
					if ((cin >> amount) && (cin.good()))
					{
					}
					else
					{
						if (error == 1)
						{
							error = 0;
							cout << "\n Некорректное значение.Введите число:" << endl;
							system("pause");
						}
						cin.clear();
						cin.ignore();
						system("cls");
						continue;
					}

					cout << "Введите максимальное значение:" << endl;
					if ((amount > 0) && (cin >> range) && (cin.good()))
					{
						if (amount == 1)
						{
							a.RandPush(amount, range);
							cout << "Элемент был успешно добавлен." << endl;
							system("pause");
							system("cls");
							break;
						}
						else
						{
							a.RandPush(amount, range);
							cout << "Элементы были успешно добавлены." << endl;
							system("pause");
							system("cls");
							break;
						}
					}
					else
					{
						if (error == 1)
						{
							error = 0;
							cout << "\n Некорректное значение.Введите число:" << endl;
							system("pause");
						}
						cin.clear();
						cin.ignore();
					}
					system("cls");
					}
				system("cls");
				break;
				}

			case 3:
			{

				system("cls");
				if (a.IsEmpty())
				{
					system("cls");
					cout << "Невозможно удалить элемент, стек пуст. Добавьте элементы в стек." << endl;
					system("pause");
				}
				else
				{
					a.Del();
					cout << "Элемент был успешно удален." << endl;
					system("pause");
				}
				system("cls");
				break;
			}

			case 4:
			{
				system("cls");
				if (a.IsEmpty())
				{
					cout << "Элементов нет." << endl;
					system("pause");
				}
				else
				{
					a.Clear();
					cout << "Стек был успешно очищен." << endl;
					system("pause");
				}
				system("cls");
				break;
			}
			
			case 5:
			{
				system("cls");
				error = 1;
				if (a.IsEmpty())
				{
					system("cls");
					cout << "Невозможно удалить элемент, стек пуст. Добавьте элементы в стек." << endl;
					system("pause");
				}
				else
				{
					cout << "Введите элемент для поиска:" << endl;
					if ((cin >> data) && (cin.good()))
					{
						if (a.Search(data) == false)
						{
							cout << "Элемент не был найден." << endl;
						}
						else
						{
							cout << "Элемент " << data << " находится в стеке." << endl;
						}

					}
					else
					{
						if (error == 1)
						{
							error = 0;
							cout << "\n Некорректное значение. Введите число:" << endl;
							system("pause");
						}

						cin.clear();
						cin.ignore();
						system("cls");
					}



					system("pause");
				}
				system("cls");
				break;
			}
			

			case 6:
			{
				system("cls");
				iter = a.getTop();
				if (a.IsEmpty())
				{
					cout << "В стеке нет элементов." << endl;
					system("pause");
				}
				else
				{
					cout << "Элементы стека:" << endl;
					while (iter) 
					{
						cout << a.getInf(iter) << ' ';
						iter = a.getNext(iter);
						
					}
					cout << endl;
					system("pause");
				}
		
				system("cls");
				break;

			}


		}
	} while (mn != 0);

	system("pause");
	return 0;
}

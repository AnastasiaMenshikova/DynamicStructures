#include "stdafx.h"
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
	int mn, data, range, amount, error; // data - информационное поле
	queue a;
	queue::iterater iter;

	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "1)Добавить один элемент в конец очереди" << endl;
		cout << "2)Заполнить очередь рандомными значениями" << endl;
		cout << "3)Удалить элемент из начала очереди" << endl;
		cout << "4)Очистить очередь" << endl;
		cout << "5)Поиск элемента в очереди по значению" << endl;
		cout << "6)Просмотр элементов очереди" << endl;
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
				cout << "Введите одно значение для добавления в очередь:" << endl;
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
					a.RandPush(amount, range);
					system("cls");
					cout << "Элементы были успешно добавлены." << endl;
					system("pause");
					system("cls");
					break;
					break;
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
			if (a.IsEmpty() == NULL)
			{
				system("cls");
				cout << "Невозможно удалить элемент, очередь пуста. Добавьте элементы." << endl;
				system("pause");
			}
			else
			{
				int p = a.pop();
				cout << "Элемент" << p << "был успешно удален" << endl;
				system("pause");
			}
			system("cls");
			break;
		}

		case 4:
		{
			system("cls");
			if (a.IsEmpty() == NULL)
			{
				cout << "Элементов нет." << endl;
				system("pause");
			}
			else
			{
				a.Clear();
				cout << "Очередь была успешно очищена." << endl;
				system("pause");
			}
			system("cls");
			break;
		}

		case 5:
		{
			system("cls");
			error = 1;
			if (a.IsEmpty() == NULL)
			{
				system("cls");
				cout << "Очередь пуста. Добавьте элементы для поиска." << endl;
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
						cout << "Элемент " << data << " находится в очереди." << endl;
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
			iter = a.getBegin();
			if (a.IsEmpty() == NULL)
			{
				cout << "В очереди нет элементов." << endl;
				system("pause");
			}
			else
			{
				cout << "Элементы очереди:" << endl;
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

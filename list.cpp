#include "list.h" 
#include <iostream>

using namespace std;

node *first(int value)
{
	node *pv = new node; //выделяем место в ячейке памяти под новый элемент списка
 	pv->value = value;  //записываем значение в информационное поле
 	pv->next = NULL; // присваиваем ноль указателю на следующий элемент
 	return pv; // возвращаем указатель на первый элемент списка
}

void add(node *pbeg, int value)
{
 	node *pv = new node;//выделяем место в ячейке памяти под указатель
 	pv->value = value;//записываем значение в информационное поле
 	pv->next = NULL;//обнуляем указатель на следующий элемент
 	node *p = pbeg; //выделяем место в ячейке памяти и присваиваем указатель на начало списка
 	while (p->next) //связываем список
	p = p->next;
 	p->next = pv;
}
node* find(node *const pbeg, int value)
{
	node *pv = pbeg; //выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
 	while (pv) //пока список не пуст
 	{
 		if (pv->value == value) //если значение в структуре совпало с введённым, прерываем цикл
 		{
 			break;
 		}
 		pv = pv->next; // переходим к следующему элементу списка
 	} 
 	return pv; //возвращаем указатель на найденный элемент
}
int del(node **pbeg)
{
 	node *pv = *pbeg; //выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
	* pbeg = (*pbeg)->next; //меняем указатель текущего на следующий элемент
 	delete pv; // удаляем элемент из списка
}
void print(node *pbeg)
{
 	node *pv = pbeg;//выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
 	while (pv != NULL) //пока список не пуст
 	{
		cout << pv->value << " ";//печатаем значение
		pv = pv->next;//переходим к следующему элементу
 	}
}
bool isEmpty(node *pbeg) //сходная проверка с проверкой на пустоту в стеке
{
	if (pbeg == NULL)
		return false;
	else
		return true;
}
node* find(node *const pbeg, int value)
{
	node *pv = pbeg;//выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
 	while (pv)  //пока список не пуст 
	{
		if (pv->value == value)  //если нашли элемент, прерываем цикл
 		{
			break;
		}
 		pv = pv->next;//переходим к следующему элементу, если не найдено совпадений
 	}
	return pv;//возвращаем адрес на найденный элемент
}
bool del_key(node **pbeg, int key)
{
 	node *pkey = find(*pbeg, key);//выделяем место в ячейке памяти и присваиваем ему указатель на найденный элемент

 	if (pkey != NULL) //если существует ключ в списке 
 	{
 		if (pkey == *pbeg) //Ключ равен первому элементу 
			* pbeg = (*pbeg)->next; //двигаем начало на второй элемент 
		else
		{
 			node*p = *pbeg;//выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
	 		while (p->next != pkey) // находим адрес ключа 
				p = p->next;//переходим к следующему элементу
 			p->next = pkey->next; // связываем два соседних элемента ключа 
		}
		delete pkey; //освобождаем место в ячейке памяти
 		return true; //если удалили элемент
	}
 	return false; //если элемент не удалён
}
void insert_after(node*const pbeg, int key, int value)
{
 	node*pkey = find(pbeg, key);//выделяем место в ячейке памяти и присваиваем ему указатель на найденный элемент
	
 	if (pkey  != NULL) //если существует такой элемент в списке
 	{
		node *pv = new node;//выделяем место в ячейке памяти 
 		pv->value = value;//записываем значение в ячейку
 		pv->next = pkey->next;// связываем два соседних элемента ключа 
 		pkey->next = pv; //в указателе ключа записываем указатель на следующий элемент, который хотим добавить
 	}
}
void insert_before(node**pbeg, int key, int value)
{
 	node*pkey = find(*pbeg, key);//выделяем место в ячейке памяти и присваиваем ему указатель на найденный элемент(ключ)
 	if (pkey != NULL)//если существует такой элемент в списке
 	{
 		node*pv = new node;//выделяем место в ячейке памяти 
 		pv->value = value;//записываем значение в ячейку
		if (pkey == *pbeg) //если ключ находится в начале 
 		{
 			pv->next = *pbeg;//указетелю на следующий элемент присваиваем указатель начала
			* pbeg = pv; //указателю начала присваиваем указатель на новый элемент

 		}
 		else
 		{       //если ключ находится не в начале 
 			pv->next = pkey;//указателю на следующий элемент присваиваем указатель на ключ
			node*p = *pbeg; //выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
			while (p->next != pkey)//пока указатель на следующий элемент не совпадёт с указателем на ключ
 				p = p->next;//переходим на следующий элемент
 			p->next = pv;//меняем указатель на следующий элемент
 		}
 	}
}

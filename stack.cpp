#include "stdafx.h"
#include "stack.h"
#include <iostream>
#include <time.h>

using namespace std;

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	Clear();
}

void Stack::push(int a)		// Функция добавления элемента в вершину стека
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->next = top;			//меняем указатель вершины
	top = pv;				//определение новой вершины
}

int Stack::pop()			// Функция удаления элемента из вершины стека, возвращает целочисленное значение
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	if (Stack::IsEmpty())	//Если стек пуст
	{
		return NULL;		//возвращаем 0, т.к. нечего удалять
	}
	else
	{
		int a;				//в переменную запишем значение удаленного элемента из вершины стека
		a = pv->value;
		pv = top; // возможно лишняя строчка
		top = pv->next;		//меняем указатель на вершину стека
		delete pv;			//удаляем элемент из стека
		return a;			//возвращаем значение удалённого элемента стека
	}
}

bool Stack::Search(int key)	//Функция поиска элемента из стека по ключу
{
	node *pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	while (pv)				// проходим по стеку пока вершина не ноль
	{
		if (pv->value == key)//если значение совпадает с ключом, возвращаем true, иначе false
		{
			return true;
		}
		pv = pv->next;		//меняем указатель, тем самым проходим по стеку
	}
	return false;
}

void Stack::Del() 
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	top = pv->next;			//меняем указатель вершины
	delete pv;				//удаляем элемент
}

void Stack::RandPush(int amount, int range) 
{
	int random, i = 0;
	node* elem = new node();
	srand(time(NULL));
	while (i != amount)
	{
		random = rand() % range;
		push(random);
		i++;
	}
}

void Stack::Clear()	//Функция очистки стека
{
	while (top != NULL)		// пока указатель на вершину не ноль 
	{
		Del();		//удаляем элементы из стека
	}
}

Stack::iterater Stack::getTop()	//Возвращает указатель на вершину стека
{ 
	return top;
}

Stack::iterater Stack::getNext(iterater a)	//Возвращает указатель на следующий элемент
{ 
	if (Stack::IsEmpty()) 
	{
		return NULL;
	}
	return a->next;
}

int Stack::getInf(iterater a)	//Возвращает значение элемента стека или 0, если стек пуст
{
	if (Stack::IsEmpty()) 
	{
		return NULL;
	}
	return a->value;
}

bool Stack::IsEmpty() //Возращает false, если стек пуст и true, если стек заполнен хотя бы одним элементом
{ 
	if (top)
		return false;
	else 
		return true;
}

#include "stdafx.h"
#include "queue.h"
#include <iostream>
#include <time.h>

using namespace std;

queue::queue()
{
	pbeg = NULL;
	pend = NULL;
}

queue::~queue()
{
	Clear();
}

void queue::push(int a)		// Функция добавления элемента в конец очереди
{
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->next = pend;		//меняем указатель вершины
	pend = pv;				//определение новой вершины
}

int queue::pop()			// Функция удаления элемента из начала очереди, возвращает целочисленное значение
{
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = pbeg;				//присваиваем pv указатель на вершину стека
	if (queue::IsEmpty())	//Если стек пуст
	{
		return NULL;		//возвращаем 0, т.к. нечего удалять
	}
	else
	{
		int a;				//в переменную запишем значение удаленного элемента из вершины стека
		a = pv->value;
		pv = pbeg;			//
		pbeg = pv->next;		//меняем указатель на вершину стека
		delete pv;			//удаляем элемент из стека
		return a;			//возвращаем значение удалённого элемента стека
	}
}

bool queue::Search(int key)	//Функция поиска элемента из стека по ключу
{
	node *pv = new node();	//выделяем место в ячейке памяти 
	pv = pbeg;				//присваиваем pv указатель на начало очереди
	while (pv)				// проходим по стеку пока вершина не ноль
	{
		if (pv->value == key)//если значение совпадает с ключом, возвращаем true, иначе false
		{
			return true;
		}
		pv = pv->next;		//меняем указатель, тем самым проходим по очереди
	}
	return false;
}

void queue::Del()
{
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = pbeg;				//присваиваем pv указатель на вершину стека
	pbeg = pv->next;		//меняем указатель начала очереди
	delete pv;				//удаляем элемент
}

void queue::RandPush(int amount, int range)
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

void queue::Clear()	//Функция очистки стека
{
	while (pbeg)		// пока указатель на начало очереди не ноль 
	{
		Del();		//удаляем элементы из стека
	}
}

queue::iterater queue::getBegin()	//Возвращает указатель на начало очереди
{
	return pbeg;
}

queue::iterater queue::getNext(iterater a)	//Возвращает указатель на следующий элемент
{
	if (queue::IsEmpty())
	{
		return NULL;
	}
	return a->next;
}

int queue::getInf(iterater a)	//Возвращает значение элемента стека или 0, если стек пуст
{
	if (queue::IsEmpty())
	{
		return NULL;
	}
	return a->value;
}

bool queue::IsEmpty()	//сходная проверка с проверкой на пустоту в стеке
{
	if (pbeg == NULL)
		return false;
	else
		return true;
}

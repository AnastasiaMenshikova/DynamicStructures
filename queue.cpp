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
	if (queue::IsEmpty() == NULL)
	{
		pbeg = pv;
		pend = pv;
	}
	else
	{
		pv->next = pend;		//меняем указатель вершины
		pend = pv;				//определение новой вершины
	}

}

int queue::pop()			// Функция удаления элемента из начала очереди, возвращает целочисленное значение
{
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = pbeg;				//присваиваем pv указатель на вершину очереди
	if (queue::IsEmpty() == NULL)	//Если очередь пуста
	{
		return NULL;		//возвращаем 0, т.к. нечего удалять
	}
	else
	{
		int a;				// !!в переменную запишем значение удаленного элемента из начала очереди
		a = pv->value;
		if (pv != pend)
		{
			pbeg = pv->next;		//меняем указатель на начало очереди
			delete pv;				//удаляем элемент из очереди
			return a;				//возвращаем значение удалённого элемента очереди
		}
		else
		{
			pend = NULL;
			pbeg = pend;
			delete pv;
			return a;
		}
	}
}

bool queue::Search(int key)	//Функция поиска элемента из очереди по ключу
{
	node *pv = new node();	//выделяем место в ячейке памяти 
	pv = pbeg;				//присваиваем pv указатель на начало очереди
	while (pv)				// проходим по очереди пока конец очереди не ноль
	{
		if (pv->value == key)//если значение совпадает с ключом, возвращаем true, иначе false
		{
			return true;
		}
		pv = pv->next;		//меняем указатель, тем самым проходим по очереди
	}
	return false;
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
	node* pv = new node();
	pv = pbeg;
	while (pbeg)		// пока указатель на начало очереди не ноль 
	{
		pbeg = pv->next;		//меняем указатель начала очереди
		delete pv;				//удаляем элемент
		pv = pbeg;
	}
}

queue::iterater queue::getBegin()	//Возвращает указатель на начало очереди
{
	return pbeg;
}

queue::iterater queue::getEnd()	//Возвращает указатель на конец очереди
{
	return pend;
}

queue::iterater queue::getNext(iterater a)	//Возвращает указатель на следующий элемент
{
	if (queue::IsEmpty())
	{
		return NULL;
	}
	return a->next;
}

int queue::getInf(iterater a)	//Возвращает значение элемента очереди или 0, если стек пуст
{
	if (queue::IsEmpty())
	{
		return NULL;
	}
	return a->value;
}

bool queue::IsEmpty()	//проверка на пустоту очереди
{
	if (pbeg == NULL)
		return false;
	else
		return true;
}

#pragma once
#include <Windows.h>
#include <iostream>
#include <malloc.h>
//Создал новый класс Array, так как не нашёл домашней работы с ним
class Array
{
	int* arr;
public:
	//Обычные конструкторы
	Array(int size) : arr{ new int[size] } {}
	Array(int* newArr) : Array(_msize(newArr))
	{arr = newArr;}
	Array() : Array(0) {}
	//Конструктор переноса (noexcept лишь из красоты добавляю)
	Array(Array&& p) noexcept 
		: arr{ nullptr } 
	{
		arr = p.arr;

		p.arr = nullptr;
	}


	//Декструктор
	~Array() {
		delete[]arr;
	}
	//Функция get
	int* getArr() {
		return arr;
	}

};


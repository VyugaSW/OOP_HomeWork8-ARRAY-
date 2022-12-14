#pragma once
#include <Windows.h>
#include <iostream>
#include <malloc.h>
//������ ����� ����� Array, ��� ��� �� ����� �������� ������ � ���
class Array
{
	int* arr;
public:
	//������� ������������
	Array(int size) : arr{ new int[size] } {}
	Array(int* newArr) : Array(_msize(newArr))
	{arr = newArr;}
	Array() : Array(0) {}
	//����������� �������� (noexcept ���� �� ������� ��������)
	Array(Array&& p) noexcept 
		: arr{ nullptr } 
	{
		arr = p.arr;

		p.arr = nullptr;
	}


	//�����������
	~Array() {
		delete[]arr;
	}
	//������� get
	int* getArr() {
		return arr;
	}

};


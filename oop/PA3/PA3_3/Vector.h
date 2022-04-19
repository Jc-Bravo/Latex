#pragma once
#include "Node.h"
#include <iostream>

class Vector {
private:
	int capacity;
	int len;
	Node* array;
public:
	Vector(int n):capacity(n){}
	~Vector(){}
	Vector(const Vector & other);
	Vector(Vector && other);
	Vector & operator=(const Vector & other);
	Vector & operator=(Vector && other);
	Node& operator [] (int pos);
	void append(int value){
		array[++len].;
	}
	void insert(int pos, int value);
	void swap(int pos1, int pos2);
	void dilatation();
	int getlen();
};
class A{

};

A a;
a
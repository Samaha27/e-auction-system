#pragma once
#include"Product.h"
#include<queue>
#include<iostream>
using namespace std;
class Customer
{
	int ID;
	char Name[20];
	long phone;
	float points;
	queue<Product> biddProd;
	queue<Product> prProduct;
public:
	Customer(int i = 0,char* c=nullptr,  int r = 0, int con = 0)
	{
		ID = i;
		int j = 0;
		while (j<20)
		{
			Name[j] = '\0';
			j++;
		}
		phone = r;
		points = con;
	}
	void setID(int id);
	void setName(string n);
	void setPhone(long p);
	void setPoints(int point);
	int getID();
	char* getName();
	long getpPhone();
	int getPoints();
	void addBidProduct(Product& p);
	void addprProd(Product& p);
	void display();
	void insert();
	void Delete(queue<Customer>& l, int i);
	void modify(queue<Customer>& l, int id);
	Product& findbiddProduct(int id);
	Product& findprProduct(int id);
};


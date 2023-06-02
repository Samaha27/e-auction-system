#pragma once
#include<iostream>
#include"Product.h"
#include<queue>
using namespace std;
class Seller
{
	int ID;
	char name[20];
	int rating;
	int contact;
	queue<Product> pl;
	
public:
	Seller(int i = 0, char* c = nullptr, int r = 0, int con = 0)
	{
		ID = i;
		//name = new char[20];
		//name = "abc";
		rating = r;
		contact = con;
	}
	void setId(int id);
	void setname(string n);
	void setRating(int r);
	void setContact(int c);
	int getId();
	char* getName();
	int getRatings();
	int getContact();
	void insertProduct(Product& p);
	void display();
	void insert();
	void Delete(queue<Seller>& l,int i);
	Product& find(int id);
	void modify(queue<Seller>& l, int id);
};


#pragma once
#include<queue>
using namespace std;
class Product
{
	int barCode;
	int price;
	int quantity;
public:
	void setBarcode(int code);
	void setPrice(int p);
	void setQuantity(int q);
	int getBarCode();
	int getPrice();
	int getQuantity();
	void display();
	void insert();
	void Delete(queue<Product>& l, int i);
	void modify(queue<Product>& l, int id);
	
};


#include "Product.h"
#include<iostream>
#include<queue>
using namespace std;

void Product::setBarcode(int code)
{
    barCode = code;
}

void Product::setPrice(int p)
{
    price = p;
}

void Product::setQuantity(int q)
{
    quantity = q;
}

int Product::getBarCode()
{
    return barCode;
}

int Product::getPrice()
{
    return price;
}

int Product::getQuantity()
{
    return quantity;
}

void Product::display()
{
    cout << "BARCODE  : " << barCode << endl;
    cout << "BPRICE   : "<< price << endl;
    cout << "QUANTITY : " << quantity << endl;
}

void Product::insert()
{
	cout << " ENTER BARCODE OF PRODUCT : " << endl;
	cin >> barCode;
	cout << " ENTER PRICE OF PRODUCT  : " << endl;
	cin >> price;
	cout << " ENTER QUANTITY OF PRODUCT  : " << endl;
	cin >> quantity;
}


void Product::Delete(queue<Product>& l, int i)
{

	Product obj;
	queue<Product> s;
	while (!(l.empty()))
	{
		obj = l.front();
		l.pop();
		if (obj.getBarCode() == i)
		{
			obj.setBarcode(0);
			obj.setPrice(0);
			obj.setQuantity(0);
		}
		else
			s.push(obj);
	}
	int size = s.size();
	while (size > 0)
	{
		l.push(s.front());
		s.pop();
		--size;
	}
}

void Product::modify(queue<Product>& l, int id)
{
	Product obj;
	queue<Product> s;
	while (!(l.empty()))
	{
		obj = l.front();
		l.pop();

		if (obj.getBarCode() == id)
		{
			int ch=1, id, c;
			while (ch == 1)
			{
				cout << " WHAT DO YOU WANT TO WANT TO MODIFY  ??? " << endl;
				cout << "1. BARCODE \n2. PRICE\n3. QUANTITY\n";
				cin >> ch;
				if (ch == 1)
				{
					cout << " ENTER NEW BARCODE OF PRODUCT \n";
					cin >> id;
					obj.setBarcode(id);
				}
				if (ch == 2)
				{
					cout << " ENTER NEW PRICE OF THIS PRODUCT :\n";
					cin >> id;
					obj.setPrice(id);
				}
				if (ch == 3)
				{
					cout << " ENTER NEW QUANTITY OF THIS PRODUCT :\n";
					cin >> id;
					obj.setQuantity(id);
				}
				cout << " IF YOU WANT TO MODIFY ANYTHING ELSE PRESS 1 ELSE PRESS 0 \n";
				cin >> ch;
			}
			
		}
		s.push(obj);
	}
}




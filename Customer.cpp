#include "Customer.h"
#include<iostream>
using namespace std;
void Customer::setID(int id)
{
	ID = id;
}
void Customer::setName(string n)
{ 
	int i = 0;
	while (!(n[i] == '\0'))
	{
		Name[i] = '\0';
		i++;
	}
	i = 0;
	while (!(n[i] == '\0'))
	{
		Name[i] = n[i];
		i++;
	}
}

void Customer::setPhone(long p)
{
	phone = p;
}

void Customer::setPoints(int point)
{
	points = point;
}

int Customer::getID()
{
	return ID;
}

char* Customer::getName()
{
	return Name;
}

long Customer::getpPhone()
{
	return phone;
}

int Customer::getPoints()
{
	return points;
}

void Customer::addBidProduct(Product& p)
{
	biddProd.push(p);
}

void Customer::addprProd(Product& p)
{
	prProduct.push(p);
}

void Customer::display()
{
	cout << " ID    :" <<	ID << endl;
	cout << " NAME  :" << Name << endl;
	cout << " PHONE :" << phone << endl;
	cout << " POINTS :" << points << endl;
	cout << " THE PURCHASED PRODUCTS OF THIS CUSTOMER ARE  : " << endl;
	if (prProduct.empty())
		cout << "DO NOT HAVE ANY PURCHASED PRODUCTS  " << endl;
	else
	{ 
		Product obj;
		queue<Product> cus;
		while(!(prProduct.empty()))
		{
			obj = prProduct.front();
			cus.push(obj);
			prProduct.pop();
			obj.display();
			cout << endl;
		}
		int size = cus.size();
		while (size > 0)
		{
			prProduct.push(cus.front());
			cus.pop();
			--size;
		}
	}
	cout << " THE BID PRODUCTS OF THIS CUSTOMER ARE  : " << endl;
	if (prProduct.empty())
		cout << "DO NOT HAVE ANY BID PRODUCTS  " << endl;
	else 
	{
		Product obj2;
		queue<Product> cus2;
		while (!(prProduct.empty()))
		{
			obj2 = biddProd.front();
			biddProd.pop();
			obj2.display();
			cout << endl;
		}

		int size = cus2.size();
		while (size > 0)
		{
			biddProd.push(cus2.front());
			cus2.pop();
			--size;
		}
	}
}

void Customer::insert()
{
	string s;
	cout << " ENTER ID      OF CUSTOMER : " << endl;
	cin >> ID;
	cout << " ENTER NAME    OF CUSTOMER  : " << endl;
	cin >> s;
	setName(s);
	cout << " ENTER PHONE  OF CUSTOMER  : " << endl;
	cin >> phone;
	cout << " ENTER POINTS OF CUSTOMER  : " << endl;
	cin >> points;

	//INSERT PRODUCT LIST OF SELLER
	int choice = 1;
	Product p;
	while (choice == 1)
	{
		cout << "ENTER YOUR PURCHASED PRODUCT DETAILS \n" << endl;
		p.insert();
		prProduct.push(p);
		cout << " IF YOU WANT TO ENTER MORE PRODUCTS PRESS 1 ELSE PRESS 0 \n";
		cin >> choice;
	}
	choice = 1;
	while (choice == 1)
	{
		cout << "ENTER YOUR BID PRODUCT DETAILS \n" << endl;
		p.insert();
		prProduct.push(p);
		cout << " IF YOU WANT TO ENTER MORE BID PRODUCTS PRESS 1 ELSE PRESS 0 \n";
		cin >> choice;
	}

}
void Customer::Delete(queue<Customer>& l, int i)
{
	Customer obj;
	queue<Customer> s;
	while(!(l.empty()))
	{
		obj = l.front();
		l.pop();
		if (obj.getID() == i)
		{
			obj.setID(0);
			obj.setPhone(0);
			obj.setPoints(0);
			obj.setName("");
			break;
		}
		else
			s.push(obj);
		int size = s.size();
		while (size > 0)
		{
			l.push(s.front());
			s.pop();
			--size;
		}
	}
}
void Customer::modify(queue<Customer>& l, int id)
{
	Customer obj;
	queue<Customer> s;
	while(!(l.empty()))
	{
		obj = l.front();
		l.pop();
		if (obj.getID() == id)
		{
			string s;
			int ch = 1, ch2, id, r, c, p, b;
			while (ch == 1)
			{
				cout << " WHAT DO YOU WANT TO WANT TO MODIFY  ??? " << endl;
				cout << "1. ID \n2. NAME\n3. POINTS\n4. CONTACT\n5. PRODUCTS \n";
				cin >> ch;

				if (ch == 1) {
					cout << "ENTER NEW ID OF CUSTOMER \n";
					cin >> id;
					obj.setID(id);
				}
				if (ch == 2) {
					cout << "ENTER NEW NAME OF CUSTOMER \n";
					cin >> s;
					obj.setName(s);
				}
				if (ch == 3) {
					cout << "ENTER NEW POINTS OF CUSTOMER \n";
					cin >> r;
					obj.setPoints(r);
				}
				if (ch == 4) {
					cout << "ENTER NEW CONTACT OF CUSTOMER \n";
					cin >> c;
					obj.setPhone(c);
				}
				if (ch == 5) {
					cout << "ENTER 1 IF YOU WANT TO FIND BID PRODUCTS  AND PRESS 2 IF YOU WANT TO FIND PURCHASED PRODUCT\n";
					cin >> c;
					cout << "BARCODE OF PRODUCT YOU WANT TO MODIFY  \n";
					cin >> b;

					Product p;
					if (c == 1)
						p = obj.findbiddProduct(c);
					else
						p = obj.findprProduct(c);
					cout << " NOW SELECT WHAT DO YOU WANY TO MODIFY ABOUT THIS PRODUCT\n ";
					cout << " 1. BARCODE\n2. PRICE\n3. QUANTITY \n";
					cin >> ch2;
					if (ch == 1)
					{
						cout << " ENTER NEW BARCODE OF PRODUCT \n";
						cin >> id;
						p.setBarcode(id);
					}
					if (ch == 2)
					{
						cout << " ENTER NEW PRICE OF THIS PRODUCT :\n";
						cin >> id;
						p.setPrice(id);
					}
					if (ch == 3)
					{
						cout << " ENTER NEW QUANTITY OF THIS PRODUCT :\n";
						cin >> id;
						p.setQuantity(id);
					}
				}
				cout << " IF YOU WANT TO MODIFY ANYTHING ELSE PRESS 1 ELSE PRESS 0 \n";
				cin >> ch;
			}

			
		}
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
Product& Customer::findbiddProduct(int id)
{
	queue<Product> s;
	Product obj,obj2;
	while(!(biddProd.empty()))
	{
		obj = biddProd.front();
		s.push(obj);
		biddProd.pop();
		if (obj.getBarCode() == id)
			obj2= obj;
	}
	int size = s.size();
	while (size > 0)
	{
		biddProd.push(s.front());
		s.pop();
		--size;
	}
	return obj2;
}
Product& Customer::findprProduct(int id) {
	queue<Product> s;
	Product obj, obj2;
	while (!(prProduct.empty()))
	{
		obj = prProduct.front();
		s.push(obj);
		prProduct.pop();
		if (obj.getBarCode() == id)
			obj2 = obj;
	}
	int size = s.size();
	while (size > 0)
	{
		prProduct.push(s.front());
		s.pop();
		--size;
	}
	return obj2;
}

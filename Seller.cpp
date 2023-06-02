#include "Seller.h"
#include<string>
#include<iostream>
using namespace std;
void Seller::setId(int id)
{
	ID = id;
}
void Seller::setname(string n)
{
	int i = 0;
	while (!(name[i] == '\0'))
	{
		name[i] = '\0';
		i++;
	}
	i = 0;
	while (!(n[i] == '\0'))
	{
		name[i] = n[i];
		i++;
	}
}

void Seller::setRating(int r)
{
	rating = r;
}

void Seller::setContact(int c)
{
	contact = c;
}

int Seller::getId()
{
	return ID;
}

char* Seller::getName()
{
	return name;
}

int Seller::getRatings()
{
	return rating;
}

int Seller::getContact()
{
	return contact;
}

void Seller::insertProduct(Product& p)
{
	pl.push(p);
}

void Seller::display()
{
	cout << " NAME    :";
	int i = 0;
	while (!(name[i] == '\0')) {
		cout << name[i];
		i++;
	}
	cout << " ID  :" << ID << endl;
	cout << " RATING  :" << rating << endl;
	cout << " CONTACT :" << contact << endl;
	cout << " THE PRODUCTS OF THIS SELLER ARE  : "  << endl;
	if (pl.empty())
		cout << "DO NOT HAVE ANY PRODUCTS TO SALE " << endl;
	else
	{
		Product obj;
		queue<Product> cus;
		while (!(pl.empty()))
		{
			obj = pl.front();
			pl.pop();
			cus.push(obj);
			obj.display();
			cout << endl;
		}
		int size = cus.size();
		while (size > 0)
		{
			pl.push(cus.front());
			cus.pop();
			--size;
		}
	}
}

void Seller::insert()
{
	string n;
	cout << " ENTER	ID OF SELLER : " << endl;
	cin >> ID;
	
	cout << " ENTER NAME OF SELLER  : " << endl;
	
	cin >> n;
	setname(n);
	
	cout << " ENTER RATING  OF SELLER  : " << endl;
	cin >> rating;
	
	cout << " ENTER CONTACT OF SELLER  : " << endl;
	cin >> contact;

	//INSERT PRODUCT LIST OF SELLER
	int choice = 1;
	Product p;
	while (choice == 1)
	{
	cout<<	"ENTER YOUR PRODUCT DETAILS \n" << endl;
	p.insert();
	pl.push(p);
	cout << " IF YOU WANT TO ENTER MORE PRODUCTS PRESS 1 ELSE PRESS 0 \n";
	cin >> choice;
	}
}

void Seller::Delete(queue<Seller>& l,int i)
{
	Seller obj;
	queue<Seller> s;
	while (!(l.empty()))
	{
		obj = l.front();
		l.pop();
		if (obj.getId() == i)
		{
			obj.setId(0);
			obj.setContact(0);
			obj.setRating(0);
			obj.setname("");
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


Product& Seller::find(int id)
{
	queue<Product> s;
	Product obj, obj2;
	while (!(pl.empty()))
	{
		obj = pl.front();
		s.push(obj);
		pl.pop();
		if (obj.getBarCode() == id)
			obj2 = obj;
	}
	int size = s.size();
	while (size > 0)
	{
		pl.push(s.front());
		s.pop();
		--size;
	}
	return obj2;
// TODO: insert return statement here
}

void Seller::modify(queue<Seller>& l, int id)
{
	Seller obj;
	queue<Seller> s;
	while (!(l.empty()))
	{
		obj = l.front();
		l.pop();
		if (obj.getId() == id)
		{
			string s;
			int ch = 1, ch2, id, r, c, p, b;
			while (ch == 1)
			{
				cout << " WHAT DO YOU WANT TO WANT TO MODIFY  ??? " << endl;
				cout << "1. ID \n2. NAME\n3. Contact\n4. RATING\n5. PRODUCTS \n";
				cin >> ch;

				if (ch == 1) {
					cout << "ENTER NEW ID OF SELLER \n";
					cin >> id;
					obj.setId(id);
				}
				if (ch == 2) {
					cout << "ENTER NEW NAME OF SELLER \n";
					cin >> s;
					obj.setname(s);
				}
				if (ch == 3) {
					cout << "ENTER NEW CONTACT OF SELLER \n";
					cin >> r;
					obj.setContact(r);
				}
				if (ch == 4) {
					cout << "ENTER NEW RATING OF SELLER \n";
					cin >> c;
					obj.setRating(c);
				}
				if (ch == 5) {
					cout << "BARCODE OF PRODUCT YOU WANT TO MODIFY  \n";
					cin >> b;

					Product p;
					p = obj.find(c);
					
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



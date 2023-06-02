#include"Product.h"
#include"Seller.h"
#include"Customer.h"
#include<queue>
#include"Auction.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename T>
void display(queue<T>& obj)
{
	T obj2;
	queue<T> cus;
	while (!(obj.empty()))
	{
		obj2 = obj.front();
		obj.pop();
		cus.push(obj2);
		obj2.display();
		cout << endl;
	}
	int size = cus.size();
	while (size > 0)
	{
		obj.push(cus.front());
		cus.pop();
		--size;
	}
}
template<typename T>
void Insert(queue<T>& obj)
{
	T obj2;
	obj2.insert();
	obj.push(obj2);
}
template<typename T,typename A>
void DeleteObjFromList(queue<T>& obj,A i)
{
	T obj2;
	obj2.Delete(obj,i);
}
template<typename T,typename A>
void Modify(queue<T>& obj, A i)
{
	T obj2;
	obj2.modify(obj, i);
}

void filereading(queue<Product>& prod, queue<Seller>& seller, queue<Customer>& customer)
{
	fstream file;
	file.open("product.txt",ios::out);
	int code, pr, quant;
	Product prd;
	while (!file.eof()){
		file >> code >> pr >> quant;
		prd.setBarcode(code);
		prd.setPrice(pr);
		prd.setQuantity(quant);
		prod.push(prd);
	}
	file.close();

	file.open("seller.txt", ios::out);
	int i, cont, rat;
	char* n=new char[20];

	Seller s;
	while (!file.eof()) {
		file >> i >> cont >> rat;
		file >> n;
		s.setId(i);
		s.setContact(cont);
		s.setRating(rat);
		s.setname(n);
		seller.push(s);
	}
	file.close();

	file.open("customer.txt", ios::out);
	int j, p,poi;
	Customer cu;
	char* na= new char[20];
	while (!file.eof()) {
		file >> j >> na >> p>>poi;
		cu.setID(j);
		cu.setName(na);
		cu.setPhone(p);
		cu.setPoints(poi);
		customer.push(cu);
	}
	file.close();
}

int main(){
	int ch = 1;
	queue<Product> prod;
	queue<Seller> seller;
	queue<Customer> customer;
	Auction auct;
	while (ch == 1) {
		int opt1;
		char opt2='\0';
		
	//filereading(prod, seller, customer);

		cout << " SELECT NUMBER \n";
		cout << " MAIN MENU     \n";
		cout << "1.Seller       \n";
		cout << "2.Product      \n";
		cout << "3.Customer     \n";
		cout << "4.Auction      \n";
		cin >> opt1;

		if (opt1 == 1 || opt1 == 2 || opt1 == 3) {
			cout << "Main Menu      \n";
			cout << "a.Display      \n";
			cout << "b.Insert       \n";
			cout << "c.Delete       \n";
			cout << "d.Modify       \n";
			cout << "e.Find         \n";
			cin >> opt2;
		}
		
//*****************************SELLER*******************************************//
		if (opt1 == 1) 
		{
			//DISPLAY SELLER
			if (opt2 == 'a') 
			{
				if (seller.empty())
					cout << "THERE ARE NO SELLERS ADDED YET TO DIPLAY . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER SELLERS\n ";
				else
					display(seller);
			}

			//INSERT SELLER
			else if (opt2 == 'b')
				Insert(seller);

			//DELETE ANY SELLER
			else if (opt2 == 'c') {
				if (seller.empty())
					cout << "THERE IS NO SELLER TO DELETE . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER SELLER\n ";
				else
				{
					int id;
					cout << " ENTER ID OF SELLER YOU WANT TO DELETE \n";
					cin >> id;
					DeleteObjFromList(seller, id);
				}
			}

			//MODIFY SELLER
			else if (opt2 == 'd') {
				if (seller.empty())
					cout << "THERE ARE NO SELLERS ADDED YET TO BE MODIFIED . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER SELLERS\n ";
				else {
					int ide;
					cout << "ENTER ID OF SELLE YOU WANT TO MODIFY\n";
					cin >> ide;
					Modify(seller, ide);
				}
			}		
			else if (opt2 == 'e') 
			{
				int id;
				cout << " ENTER ID OF SELLER YOU WANT TO FIND " << endl;
				cin >> id;
				if (seller.empty())
					cout << "THERE ARE NO SELLERS ADDED YET TO FIND . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER SELLERS\n ";
				else
				{
					Seller obj;
					queue<Seller> s;
					while (!(seller.empty()))
					{
						obj = seller.front();
						seller.pop();
						s.push(obj);
						if (obj.getId() == id)
							obj.display();
					}
					int size =s.size();
					while (size > 0)
					{
						seller.push(s.front());
						s.pop();
						--size;
					}
				}
			}
		}
//*****************************PRODUCT*******************************************//
		else if (opt1 == 2)
		{
			if (opt2 == 'a')
			{
				if(prod.empty())
					cout << "THERE ARE NO PRODUCTS ADDED YET TO DIPLAY . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER PRODUCTS\n ";
				else
					display(prod);
			}
			//INSERT PRODUCT
			else if (opt2 == 'b')
				Insert(prod);

			//DELETE PRODUCT
			else if (opt2 == 'c') {
				int id;
				if (prod.empty())
					cout << "THERE ARE NO PRODUCTS TO DELETE . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER PRODUCTS\n ";
				else
				{
					cout << " ENTER BARCODE OF PRODUCT YOU WANT TO DELETE \n";
					cin >> id;
					DeleteObjFromList(prod, id);
				}
			}
			//MODIFY PRODUCT
			else if (opt2 == 'd') {
				if (prod.empty())
					cout << "THERE ARE NO PRODUCTS ADDED YET TO BE MODIFIED . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER PRODUCT\n ";
				else {
					int ide;
					cout << "ENTER BARCODE OF PRODUCT YOU WANT TO MODIFY\n";
					cin >> ide;
					Modify(prod, ide);
				}
			}
			else if (opt2 == 'e')
			{
				int id;
				cout << " ENTER BARCODE OF PRODUCT YOU WANT TO FIND " << endl;
				cin >> id;

				Product obj;
				queue<Product> s;
				while (!(seller.empty()))
				{
					obj = prod.front();
					prod.pop();
					s.push(obj);
					if (obj.getBarCode() == id)
						obj.display();
				}
				int size = s.size();
				while (size > 0)
				{
					prod.push(s.front());
					s.pop();
					--size;
				}
			}
		}
//*****************************CUSTOMER*******************************************//
		else if (opt1 == 3) {
			//DISPLAY CUSTOMER
			if (opt2 == 'a')
			{
				if (customer.empty())
					cout << "THERE ARE NO CUSTOMERS ADDED YET TO DIPLAY . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER CUSTOMER\n ";
				else
					display(customer);

			}
			//INSERT CUSTOMER
			else if (opt2 == 'b')
				Insert(customer);

			//DELETE CUSTOMER
			else if (opt2 == 'c') 
			{
				if(customer.empty())
					cout << "THERE IS NO CUSTOMER TO DELETE . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER CUSTOMERS\n ";
				else 
				{
					int id;
					cout << " ENTER ID OF SELLER YOU WANT TO DELETE \n";
					cin >> id;
					DeleteObjFromList(customer, id);
				}
			}

			//MODIFY CUSTOMER
			else if (opt2 == 'd')
			{
				if (customer.empty())
					cout << "THERE ARE NO CUSTOMERS ADDED YET TO BE MODIFIED . GO BACK TO OPTIONS AND SELECT INSERT TO ENTER CUSTOMER\n ";
				else {
					int ide;
					cout << "ENTER ID OF CUSTOMER YOU WANT TO MODIFY\n";
					cin >> ide;
					Modify(customer, ide);
				}
			}

			//FIND CUSTOMER	
			else if (opt2 == 'e') {
				int id;
				cout << " ENTER ID OF CUSTOMER YOU WANT TO FIND " << endl;
				cin >> id;
				Customer obj;
				queue<Customer> s;
				while (!(customer.empty()))
				{
					obj = customer.front();
					customer.pop();
					s.push(obj);
					if (obj.getID() == id)
						obj.display();
				}
				int size = s.size();
				while (size > 0)
				{
					customer.push(s.front());
					s.pop();
					--size;
				}
			}
		}
		else if (opt1 == 4) {
			auct.setProduct(prod);
			auct.setCustomer(customer);
			auct.setSeller(seller);
			auct.ebidding();
		}
		cout << " IF YOU WANT TO CONTINUE PRESS 1 ELSE PRESS 0 \n";
		cin >> ch;
	}
	return 0;
}

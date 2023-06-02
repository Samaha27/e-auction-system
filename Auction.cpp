#include"Auction.h"
#include<iostream>
using namespace std;
void Auction::setProduct(queue<Product> p)
{
	prd = p;
}
void Auction::setSeller(queue<Seller> s)
{
	seller = s;
}
void Auction::setCustomer(queue<Customer> cus)
{
	customer = cus;
}
void Auction::ebidding()
{
	int bid,maxbid=0,id;
	Customer c;
	Product p;
	if (seller.empty()) {
		cout << "FIRST INSERT SELLER TO START BIDDING . GO BACK AND SELECT INSERT FROM OPTIONS \n";
		return;
	}
	if (customer.empty()) {
		cout << "FIRST INSERT CUSTOMERS TO START BIDDING AND ALE PRODUCT . GO BACK AND SELECT INSERT FROM OPTIONS \n";
		return;
	}
	cout << " ENTER YOUR SELLER ID IF YOU WANT TO BID YOUR PRODUCT " << endl;
	cin >> id;
	queue<Seller> st;
	Seller obj;
	while(!(seller.empty()))
	{ 
		obj=seller.front();
		seller.pop();
		st.push(obj);
		if (obj.getId() == id)
		{
			obj.display();
			cout << "\n ENTER YOUR PRODUCT BARCODE IF YOU WANT TO BID \n";
			cin >> id;
			p = obj.find(id);
		}
	}
	int size = st.size();
	while (size > 0)
	{
		seller.push(st.front());
		st.pop();
		--size;
	}
	p.display();
	cout << "\n ENTER TIME FOR BIDDING \n";
	cin >> Time;
	Customer obj2;
	queue<Customer> s;
	while(!(customer.empty()))
	{
		obj2=customer.front();
		s.push(obj2);
		customer.pop();
		cout << "HELLO " << obj2.getName()<<" YOUR ID IS "<<obj2.getID() << "\n " << " ENTER YOUR BIDDING AMOUNT " << endl;
		cin >> bid;
		obj2.addBidProduct(p);
		if (bid > maxbid)
		{
			maxbid = bid;
			c = obj2;
		}
	}
	int size1 = s.size();
	while (size1 > 0)
	{
		customer.push(s.front());
		s.pop();
		--size1;
	}
	c.addprProd(p);
	cout << "\n THE MAX BIDDING AMOUNT FOR PRODUCT " << p.getBarCode() << " IS : " << maxbid<<endl;
	cout << " THE BIDDING WINNER IS " << c.getID() << " " << c.getName() << endl;
}

void Auction::setTime(float t)
{
	Time = t;
}

queue<Product> Auction::getProduct()
{
	return prd;
	// TODO: insert return statement here
}

queue<Seller> Auction::getSeller()
{
	// TODO: insert return statement here
	return seller;
}

queue<Customer> Auction::getCustomer()
{
	return customer;
	// TODO: insert return statement here
}

float Auction::getTime()
{
	return Time;
}

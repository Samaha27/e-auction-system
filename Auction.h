#pragma once
#include"Product.h"
#include"Seller.h"
#include"Customer.h"
#include<queue>
using namespace std;
class Auction
{
	queue<Product> prd;
	queue<Seller> seller;
	queue<Customer> customer;
	queue<long> eBidding;
	float Time;
public:
	void setProduct(queue<Product> p);
	void setSeller(queue<Seller> s);
	void setCustomer(queue<Customer> customer);
	void ebidding();
	void setTime(float t);
	queue<Product> getProduct();
	queue<Seller> getSeller();
	queue<Customer> getCustomer();
	float getTime();
};


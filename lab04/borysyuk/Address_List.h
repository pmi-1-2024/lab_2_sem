#pragma once
#include "Address.h"
#include"List.h"
class Address_list : public List
{
public:
	void push(Address a);
	Address_link* top()const;
	Address_link* find(const Address& a);
	void insert(Address a, Address_link* after);
};
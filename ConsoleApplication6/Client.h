#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include "Validation.h"
#include "Person.h"
using namespace std;
#pragma once
class Client:public Person 
{
private:
	double balance;
public:
	Client(){
		balance = 0;
	}
	Client(int id, string pass, string name, double balance){
		if (Validation::checkBalance(balance), Validation::checkName(name), Validation::checkPassword(pass)) {
			this->balance = balance;
			this->name = name;
			this->id = id;
			this->pass = pass;
	}

		}
	void set_balance(double balance) {
		this->balance = balance;
	}
	double get_balance() {
		return balance;
	}
	//methods
	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (balance < amount) {
			cout << "balance not enough" << endl;
		}
		else {
			balance -= amount;
		}
	}
	void transferTo(double amount, Client& recipient) {
		if (amount > balance) {
			cout << "balance not enough" << endl;
	}
		else {
			balance -= amount;
			recipient.deposit(amount);
		}
	}
	void checkbalance() {
		cout << "balance = " << balance << endl;
	}
	
	void Display() {
		cout << "********** Client Info :  ***********" << endl;
		cout << "Name : " << name << endl;
		cout << "ID : " << id << endl;
		cout << "Password : " << pass << endl;
		cout << "Balance : " << balance << endl;
		cout << "**************************************" << endl;
	}

};




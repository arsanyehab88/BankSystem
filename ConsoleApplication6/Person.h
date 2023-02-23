#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;
#pragma once
class Person
{
protected:
	string name;
	int id;
	string pass;
public:
	Person() {
		this->name = " ";
		this->id = 0;
		this->pass = " ";
	}
	Person(int id, string pass,string name,double balance) {
		this->id = id;
		this->pass = pass;
		this->name = name;
	}
	//getters
	void setName(string name) {
		if (Validation::checkName(name)) {
			this->name = name;
		}
	}
	void set_id(int id) {
		this->id = id;
	}
	void set_pass(string pass) {
		if (Validation::checkPassword(pass)) {
			this->pass = pass;
		}
		
	}
	string get_name() {
		return name;
	}
	int get_id() {
		return id;
	}
	string get_pass() {
		return pass;
	}
	virtual void Display() = 0;
};


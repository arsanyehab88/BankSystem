#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <fstream>
#include <iterator>
#include "Person.h"
#include "Validation.h"
#include "FileHelperClient.h"
#pragma once
class Employee:public Person
{
protected:
	double salary;
	static int IDD;
public:
	Employee(){
		salary = 0;
	}
	Employee(int id, string name, string pass, double salary) {
		if (Validation::checkName(name) && Validation::checkSalary(salary) && Validation::checkPassword(pass)) {
			this->name = name;
			this->pass = pass;
			this->id = id;
			this->salary = salary;
		}
	}
	void set_balance(double salary) {
		this->salary = salary;
	}
	double get_balance() {
		return salary;
	}
	void addClient(Client t) {
		FileMangerCLient p;
		p.AddClient(t);
	}
	Client searchClient(int ID) {
		string id = to_string(ID);
		string line;
		int off;
		Client client;
		bool flag = false;
		ifstream file("Client.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, line);
				if (((off = line.find(id, 0))) != string::npos) {
					flag = true;
					break;
				}
			}
			if (flag) {
				client = Parser::split<Client>(line);
				client.Display();
				return client;
			}
			else {
				cout << "id not found";
				
			}

		}
		return client;
	}
	void SaveClient(Client t) {
		ifstream file("Client.txt");
		FileMangerCLient s;
		vector<Client> info = s.GetAllClients();
		for (int i = 0; i < info.size(); i++) {
			if (t.get_id() == info[i].get_id()) {
				info[i] = t;
			}
		}
		ofstream f("Client.txt");
		for (int i = 0; i < info.size(); i++) {
			f << info[i].get_name() << "," << info[i].get_pass() << "," << info[i].get_id() << "," << info[i].get_balance() << endl;
		}
	}
	void EditClient(int id ,string name,string pass,double balance) {
		Client s;
		s.setName(name);
		s.set_id(id);
		s.set_balance(balance);
		s.set_pass(pass);
		SaveClient(s);
	}
	void listClient(int id) {
		Client client = searchClient(id);
		client.Display();
	}

	void Display() {
		cout << "********** Employee Info :  ***********" << endl;
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Salery : " << salary << endl;
		cout << "***************************************" << endl;
	}
};


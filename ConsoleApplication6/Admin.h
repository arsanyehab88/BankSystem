#include "Employee.h"
#include "FileMangerEmployee.h"
#pragma once
class Admin:public Employee
{
public:
	Admin(){}
	Admin(int id, string name, string pass, double salery) :Employee(id, name, pass, salery) {}
	void addEmployee(Employee t) {
		FileMangerEmployee s;
		s.AddEmployee(t);
	}
	Employee searchEmployee(int ID) {
		string id = to_string(ID);
		string line;
		int off;
		Employee employee;
		bool flag = false;
		ifstream file("Employee.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, line);
				if (((off = line.find(id, 0))) != string::npos) {
					flag = true;
					break;
				}
			}
			if (flag) {
				employee= Parser::split<Employee>(line);
				employee.Display();
				return employee;
			}
			else {
				cout << "id not found";

			}

		}
		return employee;
	}
	void SaveEmployee(Employee t) {
		ifstream file("Employee.txt");
		FileMangerEmployee s;
		vector<Employee> info = s.GetAllEmployee();
		for (int i = 0; i < info.size(); i++) {
			if (t.get_id() == info[i].get_id()) {
				info[i] = t;
			}
		}
		ofstream f("Employee.txt");
		for (int i = 0; i < info.size(); i++) {
			f << info[i].get_name() << "," << info[i].get_pass() << "," << info[i].get_id() << "," << info[i].get_balance() << endl;
		}
	}
	void EditEmployee(int id, string name, string pass, double balance) {
		Employee s;
		s.setName(name);
		s.set_id(id);
		s.set_balance(balance);
		s.set_pass(pass);
		SaveEmployee(s);
	}
	void listEmployee(int id) {
		Employee employee = searchEmployee(id);
		employee.Display();
	}
	void Display() {
		cout << "********** Admin Info :  ***********" << endl;
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Salery : " << salary << endl;
		cout << "***************************************" << endl;
	}
};


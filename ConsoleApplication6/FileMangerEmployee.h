#include <iostream>
#include "Parser.h"
#include "EmployeeAbstract.h"
#pragma once
class FileMangerEmployee:public Employee
{
public:
	void AddEmployee(Employee t) {
		ofstream file("Employee.txt", ios::app);
		file << t.get_name() << "," << t.get_pass() << "," << t.get_id() << "," << t.get_balance() << endl;
		file.close();
	}
	vector<Employee> GetAllEmployee() {
		Parser p;
		return p.parserData<Employee>("Employee");
	 }
	void RemoveAllEmployee() {
		ofstream file("Employee.txt");
		file << "";
		file.close();
	}
};


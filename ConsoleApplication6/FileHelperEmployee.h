#include <iostream>
#include "FileMangerEmployee.h"
#pragma once
class FileHelperEmployee
{
public:
	static void getEmployees() {
		FileMangerEmployee s;
		vector<Employee> b = s.GetAllEmployee();
			vector<Employee>::iterator it = b.begin();
		for (; it != b.end(); it++) {
			cout << "name:" << (*it).get_name() << endl
				<< "id:" << (*it).get_id() << endl
				<< "pass:" << (*it).get_pass() << endl
				<< "salery: " << (*it).get_balance() << endl;

		}
	}

	static void clearEmployeeFile() {
		FileMangerEmployee f;
		f.RemoveAllEmployee();
	}
};


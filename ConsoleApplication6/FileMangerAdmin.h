#include "AdminAbstract.h"
#include "Parser.h"

#pragma once
class FileMangerAdmin:public Employee
{
public:
	void AddAdmin(Admin t) {
		ofstream file("Admin.txt", ios::app);
		file << endl << t.get_name() << "," << t.get_pass() << "," << t.get_id() << "," << t.get_balance();
		file.close();
	}
	vector<Admin> GetAllAdmin() {
		Parser p;
		return p.parserData<Admin>("Admin");
	}
	void RemoveAllAdmin() {
		ofstream file("Admin.txt");
		file << "";
		file.close();
	}
};


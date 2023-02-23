#include "FileMangerAdmin.h"

#pragma once
class FileHelperAdmin
{
public:
	static void getAdmin() {
		FileMangerAdmin s;
		vector<Admin> b = s.GetAllAdmin();
		vector<Admin>::iterator it = b.begin();
		for (; it != b.end(); it++) {
			cout << "name:" << (*it).get_name() << endl
				<< "id:" << (*it).get_id() << endl
				<< "pass:" << (*it).get_pass() << endl
				<< "salery: " << (*it).get_balance() << endl;

		}
	}

	static void clearAdminFile() {
		FileMangerAdmin f;
		f.RemoveAllAdmin();
	}
};


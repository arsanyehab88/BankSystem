#include<iostream>
#include "FileMangerCLient.h"
using  namespace std;
#pragma once
class FileHelperClient
{
public:
	static void getClients() {
		FileMangerCLient s;
		vector<Client> b = s.GetAllClients();
		vector<Client>::iterator it = b.begin();
		for (; it != b.end(); it++) {
			cout << "name:" << (*it).get_name() << endl
				<< "id:" << (*it).get_id() << endl
				<< "pass:" << (*it).get_pass() << endl
				<< "salery: " << (*it).get_balance() << endl;

		}
	}
	static void clearClientFile() {
		FileMangerCLient f;
		f.RemoveAllClients();
	}

};


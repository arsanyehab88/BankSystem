#include "ClientManager.h"
#include "EmployeeManger.h"
#include "FileHelperEmployee.h"
#include "Client.h"
#include "Screen.h"

#pragma once
class ClientMenu
{
public:
	
	static void withdraw() {
		int y;
		ClientManager f;
		Client client = f.login();
		if (client.get_id() == 0) {
			cout << "wrong input\n";
		}
		else {
			Screen::PrintClientMenu(client);
			cin >> y;
			if (y == 1) {
				client.checkbalance();
			}
			else if (y == 2) {
				double b;
				cout << "\n\t";
				client.checkbalance();
				cout << "\n\tEnter amount to whithdraw" << endl;
				cin >> b;
				client.withdraw(b);
				FileMangerCLient::SaveClient(client);
			}
		}
	}
	static void Updatepass() {
		ClientManager f;
		Client client;
		string s;
		cout << "\n\tEnter new password!" << endl;
		cin >> s;
		f.EditPass(s);
		FileMangerCLient::SaveClient(client);
	}
};


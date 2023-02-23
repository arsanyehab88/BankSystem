#pragma once
#include "FileMangerCLient.h"
#include "Employee.h"
#include "Screen.h"
class ClientManager
{
public:

	static Client login() {
		Client client;
		int id;
		string pass;
		cout << "enter id: ";
		cin >> id;
		cout << "enter pass: ";
		cin >> pass;
		FileMangerCLient f;
		vector<Client> t = f.GetAllClients();
		for (int i = 0; i < t.size(); i++) {
			if (t[i].get_id() == id && t[i].get_pass() == pass) {
				client = t[i];
			}
		}
		return client;
	}

	 static void SavePass(Client t) {
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

	static void EditPass(string pass) {
		Client client;
		client.set_pass(pass);
		SavePass(client);

	}
	static void startclient() {
		int y;
		system("CLS");
		ClientManager f;
		Client client = f.login();
		if (client.get_id() == 0) {
			cout << "wrong input\n";
		}
		else {
			system("CLS");
			Screen::PrintClientMenu(client);
			while (true)
			{
				cin >> y;
				if (y == 1) {
					system("CLS");
					client.checkbalance();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintClientMenu(client);
				}
				else if (y == 2) {
					double b;
					cout << "\n\t";
					client.checkbalance();
					cout << "\n\tEnter amount to whithdraw" << endl;
					cin >> b;
					client.withdraw(b);
					FileMangerCLient::SaveClient(client);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintClientMenu(client);
				}
				else if (y == 3) {
					string s;
					cout << "\n\tEnter new password!" << endl;
					cin >> s;
					f.EditPass(s);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintClientMenu(client);
				}
				else if (y == 4) {
					double b;
					int id;
					cout << "\n\tEnter amount to transfer!" << endl;
					cin >> b;
					cout << "\n\tEnter account to transfer" << endl;
					cin >> id;
					Employee e;
					system("CLS");
					Client st = e.searchClient(id);
					client.transferTo(b, st);
					FileMangerCLient::SaveClient(client);
					FileMangerCLient::SaveClient(st);
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintClientMenu(client);
				}
				else if (y == 5) {
					break;

				}

			}


		}



	}
};


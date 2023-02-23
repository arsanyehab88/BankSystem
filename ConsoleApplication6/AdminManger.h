#include "FileMangerAdmin.h"
#include "Screen.h"
#include "Admin.h"
#include "FileHelperEmployee.h"
#include "FileHelperAdmin.h"
#pragma once
class AdminManger
{
public:
	static Admin login() {
		Admin admin;
		int id;
		string pass;
		cout << "enter id: ";
		cin >> id;
		cout << "enter pass: ";
		cin >> pass;
		FileMangerAdmin f;
		vector<Admin> t = f.GetAllAdmin();
		for (int i = 0; i < t.size(); i++) {
			if (t[i].get_id() == id && t[i].get_pass() == pass) {
				admin = t[i];
			}
		}
		return admin;
	}

	static void StartAdmin() {
		int c;
		system("CLS");
		AdminManger f;
		Admin admin = f.login();
		if (admin.get_id() == 0) {
			cout << "\n\tWrong input!!" << endl;
		}
		else {
			system("CLS");
			Screen::adminMenu(admin);
			while (true)
			{
				cin >> c;
				if (c == 1) {
					FileMangerCLient s;
					Client ts;
					string name;
					string pass;
					double balance;
					int id;
					cout << "\n\tEnter Name: " << endl;
					cin >> name;
					cout << "\n\tEnter password: " << endl;
					cin >> pass;
					cout << "\n\tEnter Balance: " << endl;
					cin >> balance;
					cout << "\n\tEnter ID: " << endl;
					cin >> id;
					ts.setName(name);
					ts.set_pass(pass);
					ts.set_balance(balance);
					ts.set_id(id);
					s.AddClient(ts);
					FileMangerCLient::SaveClient(ts);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 2) {
					int x;
					cout << "\n\tPlease enter id to search!!" << endl;
					cin >> x;
					system("CLS");
					admin.searchClient(x);
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 3) {
					Client t;
					int x;
					string name;
					string pass;
					double balance;
					int id;
					cout << "\n\tenter id to search!!" << endl;
					cin >> x;
					admin.searchClient(x);
					cout << "\n\tEnter New Name!" << endl;
					cin >> name;
					cout << "\n\tEnter New Id!" << endl;
					cin >> id;
					cout << "\n\tEnter New pass!" << endl;
					cin >> pass;
					cout << "\n\tEnter New balance!";
					cin >> balance;
					t.setName(name);
					t.set_id(id);
					t.set_balance(balance);
					t.set_pass(pass);
					admin.EditClient(id, name, pass, balance);
					FileMangerCLient::SaveClient(t);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 4) {
					system("CLS");
					FileHelperClient::getClients();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 5) {
					FileMangerEmployee s;
					Employee ts;
					string name;
					string pass;
					int id;
					double balance;
					cout << "\n\tEnter Name: " << endl;
					cin >> name;
					cout << "\n\tEnter password: " << endl;
					cin >> pass;
					cout << "\n\tEnter Balance: " << endl;
					cin >> balance;
					cout << "\n\t Enter ID" << endl;
					cin >> id;
					ts.setName(name);
					ts.set_id(id);
					ts.set_pass(pass);
					ts.set_balance(balance);
					s.AddEmployee(ts);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);

				}
				else if (c == 6) {
					int x;
					cout << "\n\tPlease enter id to search!!" << endl;
					cin >> x;
					system("CLS");
					admin.searchEmployee(x);
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 7) {
					Employee t;
					int x;
					string name;
					string pass;
					double balance;
					int id;
					cout << "\n\tenter id to search!!" << endl;
					cin >> x;
					admin.searchEmployee(x);
					cout << "\n\tEnter New Name!" << endl;
					cin >> name;
					cout << "\n\tEnter New Id!" << endl;
					cin >> id;
					cout << "\n\tEnter New pass!" << endl;
					cin >> pass;
					cout << "\n\tEnter New balance!";
					cin >> balance;
					t.setName(name);
					t.set_id(id);
					t.set_balance(balance);
					t.set_pass(pass);
					admin.EditEmployee(id, name, pass, balance);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 8) {
				system("CLS");
					FileHelperEmployee::getEmployees();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 9) {

					string name;
					string pass;
					double balance;
					int id;
					cout << "\n\tEnter name ? " << endl;
					cin >> name;
					cout << "\n\tEnter password ? " << endl;
					cin >> pass;
					cout << "\n\tEnter ID ? " << endl;
					cin >> id;
					cout << "\n\tEnter balance ? " << endl;
					cin >> balance;
					admin.setName(name);
					admin.set_balance(balance);
					admin.set_id(id);
					admin.set_pass(pass);
					FileMangerAdmin f;
					f.AddAdmin(admin);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 10) {
				system("CLS");
				admin.Display();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 11) {
					FileHelperClient::clearClientFile();
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 12) {
					FileHelperEmployee::clearEmployeeFile();
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::adminMenu(admin);
				}
				else if (c == 13) {
				break;
				}


			}
		}
			
	}
};


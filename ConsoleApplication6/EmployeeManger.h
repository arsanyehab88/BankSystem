#pragma once
#include "FileMangerEmployee.h"
#include "Screen.h"
#include "Employee.h"
#include "FileHelperEmployee.h"
class EmployeeManger
{
public:
	static Employee login() {
		Employee employee;
		int id;
		string pass;
		cout << "enter id: ";
		cin >> id;
		cout << "enter pass: ";
		cin >> pass;
		FileMangerEmployee f;
		vector<Employee> t = f.GetAllEmployee();
		for (int i = 0; i < t.size(); i++) {
			if (t[i].get_id() == id && t[i].get_pass() == pass) {
				employee = t[i];
			}
		}
		return employee;
	}
	static void SavePass(Employee t) {
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
			f << info[i].get_pass() << endl;
		}
	}
	static void EditPass(string pass) {
		Employee employee;
		employee.set_pass(pass);
		SavePass(employee);

	}
	static void StartEmployee() {
		int z;
		system("CLS");
		EmployeeManger f;
		Employee employee = f.login();
		if (employee.get_id() == 0) {
			cout << "\n\tWrong input!!" << endl;
		}
		else {
			system("CLS");
			Screen::PrintEmployeeMenu(employee);
		while (true)
		{

				cin >> z;
				if (z == 1) {
					FileMangerCLient s;
					Client ts;
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
					Screen::PrintEmployeeMenu(employee);
				}
				else if (z == 2) {
					int x;
					cout << "\n\tPlease enter id to search!!" << endl;
					cin >> x;
					system("CLS");
					employee.searchClient(x);
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintEmployeeMenu(employee);
				}
				else if (z == 3) {
					Client t;
					int x;
					string name;
					string pass;
					double balance;
					int id;
					cout << "\n\tenter id to search!!" << endl;
					cin >> x;
					employee.listClient(x);
					cout << "\n\tEnter New Name!" << endl;
					cin >> name;
					cout << "\n\tEnter New Id!" << endl;
					cin >> id;
					cout << "\n\tEnter New pass!" << endl;
					cin >> pass;
					cout << "\n\tEnter New balance!";
					cin >> balance;
					t.setName(name);
					t.set_balance(balance);
					t.set_id(id);
					t.set_pass(pass);
					FileMangerCLient::SaveClient(t);
					system("CLS");
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintEmployeeMenu(employee);
					//employee.EditClient(id, name, pass, balance);


				}
				else if (z == 4) {
					system("CLS");
					FileHelperClient::getClients();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintEmployeeMenu(employee);
				}
				else if (z == 5) {
					system("CLS");
					employee.Display();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintEmployeeMenu(employee);
				}
				else if (z == 6) {
					system("CLS");
					FileHelperClient::clearClientFile();
					cout << "\n\tprocessing successful $$" << endl;
					Screen::PrintEmployeeMenu(employee);
				}
				else if (z == 7) {
					break;
				}

			}
		}

		}
	
};


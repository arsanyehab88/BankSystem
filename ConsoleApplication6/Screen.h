#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
#pragma once
class Screen
{
public:
	static void bankName() {
		cout << "\n\t**************************" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
	static void Welcome() {
		bankName();
		cout <<  << endl;
		cout << "\n\t1 - Client" << endl
			<<  "\n\t2 - Employee"<< endl
			<< "\n\t3 - Admin" << endl
			<< "\n\t4 - Exit" << endl;
	}
	static void PrintClientMenu(Client t) {
		cout << "\n\t what do you want to do ? " << endl << "\n\t\t*" << t.get_name() << "*" << endl;
		cout << "\n\t1 - Check balance" << endl;
		cout << "\n\t2 -  whithdraw" << endl;
		cout << "\n\t3 - Update password" << endl;
		cout << "\n\t4 - Transfer money to another client" << endl;
		cout << "\n\t5 - Log out\n\nYour answer: ";
	}

	static void PrintEmployeeMenu(Employee t) {

		cout << "\n\t   what do you want to do ? " << "\n\t\t*" << t.get_name() << "*" << endl;
		cout << "\n\t1 - Add new client\n";
		cout << "\n\t2 - Search for a client\n";
		cout << "\n\t3 - Edit info of a client\n";
		cout << "\n\t4 - List all clients\n";
		cout << "\n\t5 - Display my info\n";
		cout << "\n\t6 - Clear clients file\n";
		cout << "\n\t7 - Log out\n\nYour answer: ";

	}
	static void adminMenu(Admin admin) {
		cout << "\n\tWhat do you want to do, " << "\n\t\t*" << admin.get_name() << "*" << " ?\n\n";
		cout << "\n\t1 - Add new client\n";
		cout << "\n\t2 - Search for a client\n";
		cout << "\n\t3 - Edit info of a client\n";
		cout << "\n\t4 - List all clients\n";
		cout << "\n\t5 - Add new employee\n";
		cout << "\n\t6 - Search for an employee\n";
		cout << "\n\t7 - Edit info of an employee\n";
		cout << "\n\t8 - List all employees\n";
		cout << "\n\t9 - Assign new admin\n";
		cout << "\n\t10 - Display my info\n";
		cout << "\n\t11 - Clear clients file\n";
		cout << "\n\t12 - Clear employees file\n";
		cout << "\n\t13 - Log out\n\nYour answer: ";
	}


};


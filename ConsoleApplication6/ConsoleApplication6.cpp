#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include "Admin.h"
#include "Screen.h"
#include "ClientManager.h"
#include "EmployeeManger.h"
#include "FileHelperEmployee.h"
#include "FileMangerEmployee.h"
#include "FileHelperAdmin.h"
#include "AdminManger.h"
#include <Windows.h>
using namespace std;
int main() {
	int a;

	while (true)
	{
		system("color E4");
		system("CLS");
		Screen::Welcome();
			cin >> a;
			if (a == 1) {
				ClientManager::startclient();
			}
			else if (a == 2) {
				EmployeeManger::StartEmployee();
			}
			else if (a == 3) {
				AdminManger::StartAdmin();
			}
			else if (a == 4) {
				break;
			}

		}
	}


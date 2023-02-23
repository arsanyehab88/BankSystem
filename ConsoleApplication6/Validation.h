#include <iostream>
#include <string>

using namespace std;
#pragma once
class Validation
{

public:

    //Methods:
    static bool checkName(string name) {
        if (!(name.size() >= 5 && name.size() <= 20)) {
            cout << "invalid name size !\n";
            return false;
        }
        for (int i = 0; i < name.size(); i++) {
            if (!(name[i] >= 'A' && name[i] <= 'z')) {
                cout << "invalid name character !\n";
                return false;
            }
        }
        return true;
    }
    static bool checkPassword(string pass) {
        if (!(pass.size() >= 5 && pass.size() <= 20)) {
            cout << "invalid password size !\n";
            return false;
        }
        return true;
    }
    static bool checkBalance(double balance) {
        if (balance < 1500) {
            cout << "invalid balance !\n";
            return false;
        }
        return true;
    }
    static bool checkSalary(double salary) {
        if (salary < 5000) {
            cout << "invalid salary !\n";
            return false;
        }
        return true;
    }

};


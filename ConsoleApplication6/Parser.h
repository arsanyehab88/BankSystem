#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

#pragma once
class Parser
{
public:
	template <class type>
	static type split(string line) {
		type t;
		char ab = ',';
		string name;
		string pass;
		string balance;
		string id;
		stringstream in(line);

		getline(in, name, ab);
		getline(in, pass, ab);
		getline(in, id, ab);
		getline(in, balance, ab);

		t.setName(name);
		t.set_pass(pass);
		t.set_balance(stod(balance));
		t.set_id(stoi(id));
		return t;
	}
	template <class d>
	static vector<d> parserData(string fileName) {
		vector<d>info;
		fileName += ".txt";
		string line;
		ifstream readfile(fileName, ios::app);

		while (getline(readfile, line)) {


			info.push_back(split<d>(line));
		}
		return info;

	}
};

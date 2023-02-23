#pragma once
#include <iostream>
#include "Parser.h"
#include "ClientAbstruct.h"

using namespace std;
class FileMangerCLient:public ClientAbstruct
{
public:
	void AddClient(Client t){
		ofstream file("Client.txt", ios::app);
		file << t.get_name() << "," << t.get_pass() << "," << t.get_id() << "," << t.get_balance() << endl;
		file.close();
	}

	 vector<Client> GetAllClients(){
		 Parser p;
		 return p.parserData<Client>("Client");
	 }
	 void RemoveAllClients(){
		 ofstream file("Client.txt");
		 file << "";
		 file.close();
	 }
	 static void SaveClient(Client t) {
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
};


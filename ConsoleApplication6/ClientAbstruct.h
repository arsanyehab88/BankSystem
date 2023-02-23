#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <fstream>
#include <iterator>
#include "Client.h"
#pragma once
class ClientAbstruct
{
public:
	virtual void AddClient(Client t) = 0;
	virtual vector<Client> GetAllClients() = 0;
	virtual void RemoveAllClients() = 0;
};


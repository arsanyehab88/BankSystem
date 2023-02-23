#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <fstream>
#include <iterator>
#include "Admin.h"
#pragma once
class AdminAbstract
{
	virtual void AddAdmin() = 0;
	virtual void RemoveAllAdmin() = 0;
	virtual vector<Employee> GetAllAdmin() = 0;
};


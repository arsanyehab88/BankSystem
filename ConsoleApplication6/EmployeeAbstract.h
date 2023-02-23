#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <fstream>
#include <iterator>
#include "Employee.h"
#pragma once
class EmployeeAbstract
{
public:
	virtual void AddEmployee() = 0;
	virtual vector<Employee> GetAllEmployee() = 0;
	virtual void RemoveAllEmployee() = 0;
};


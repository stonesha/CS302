/**
 * @file table.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date Feb, 2020
 * @brief Self-contained header file for the table class
 */
#pragma once

#include <string>
#include <fstream>

using namespace std;

class table
{
public:
	table(string tbName, string currDB, string currData)
	{
		name = tbName;
		db = currDB;
		data = currData;
	}
	table(string tbName, string currDB)
	{
		name = tbName;
		db = currDB;
	}
	string getName()
	{
		return name;
	}
	string getData()
	{
		return data;
	}
	
	void add(string line)
	{
		//puts add in substr
		line = line.substr(line.find("ADD") + 3);
		data.append(" | " + line);
	}

	~table()
	{

	}
	
	//operator overload to check for equality to see if table exists
	bool operator==(table const& rhs)
	{
		if (name == rhs.name && db == rhs.db)
			return true;
		else
			false;
	}

private:
	string name;
	string db;
	string data;
};


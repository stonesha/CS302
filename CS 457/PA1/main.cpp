/**
 * @file main.cpp
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date Feb, 2020
 * @brief main program
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>

#include "table.h"

using namespace std;

//to parse the commands with delimiter ';'
void parseInput(const string& input, vector<string>& commands);

//execute the commands and modify the tables accordingly
void parseCommands(vector<string>& commands, vector<table>& tables);

//get the name of the database
string getName(string line);

//get the name of the table;
string getTblName(string line);

//get the data that is passed in when creating a table
string getData(string line);

int main(int argc, char* argv[])
{

	string input;
	vector<string> commands;
	vector<table> tables;
	
	//main loop
	while (input != ".EXIT")
	{
		cout << "> ";
		getline(cin, input);

		parseInput(input, commands);
		parseCommands(commands, tables);
			
	}


	return 0;
}

void parseCommands(vector<string>& commands, vector<table>& tables)
{
	string currDB;

	for (auto i : commands)
	{
		if (i.find("CREATE DATABASE") != -1)
		{
			//Get the database name
			string dbName = getName(i);
			//make directory
			const int dirErr = system(("mkdir " + dbName).c_str());
			//see if made successfully
			if (dirErr == 0)
				cout << "Database " << dbName << " created." << endl;
			else
				cout << "!Failed to create database "
				<< dbName << " because it already exists." << endl;
		}
		else if (i.find("DROP DATABASE") != -1)
		{
			string dbName = getName(i);
			//remove directory
			const int dirErr = system(("rmdir " + dbName).c_str());
			//see if successful
			if (dirErr == 0)
				cout << "Database " << dbName << " deleted." << endl;
			else
				cout << "!Failed to delete "
				<< dbName << " because it does not exist." << endl;
		}
		else if (i.find("USE") != -1)
		{
			//changes current database
			string dbName = getName(i);
			const int dirErr = system(("cd " + dbName).c_str());
			currDB = dbName;
			if (dirErr == 0)
				cout << "Using datbase " << dbName << "." << endl;
			else
				cout << "!Failed to use "
				<< dbName << " because it does not exist." << endl;
		}
		else if (i.find("CREATE TABLE") != -1)
		{
			//Get the table name
			string tbName = getTblName(i);
			//parse for the data passed in
			string data = getData(i);
			table tb(tbName, currDB, data);

			//see if table exists
			auto it = find(tables.begin(), tables.end(), tb);
			if (it != tables.end())
			{
				cout << "!Failed to create "
					<< tbName << " because it already exists." << endl;
			}
			else
			{
				tables.push_back(tb);
				cout << "Table " << tbName << " created." << endl;
			}	
		}
		else if (i.find("SELECT * FROM") != -1)
		{
			string tbName = getName(i);
			table tb(tbName, currDB);
			auto it = find(tables.begin(), tables.end(), tb);
			//finds table index if it exists
			size_t index = it - tables.begin();
			if (it != tables.end())
			{
				//prints data from table
				cout << tables[index].getData() << endl;
			}
			else
			{
				cout << "!Failed to query "
					<< tbName << " because it does not exist." << endl;
			}
		}
		else if (i.find("ALTER TABLE") != -1)
		{
			string tbName = getTblName(i);
			table tb(tbName, currDB);
			auto it = find(tables.begin(), tables.end(), tb);
			size_t index = it - tables.begin();
			if (it != tables.end())
			{
				tables[index].add(i);
				cout << "Table " << tbName << " modified." << endl;
			}
			else
			{
				cout << "!Failed to add to "
					<< tbName << " because it does not exist." << endl;
			}
		}
	}

	commands.clear();
}

string getData(string line)
{
	auto it = find(line.begin(), line.end(), '(');
	line = string(it, line.end());
	line = line.substr(1, line.size() - 2);
	replace(line.begin(), line.end(), ',', '|');

	return line;
}

string getName(string line)
{
	stringstream ss(line);
	string token;
	while (getline(ss, token, ' '))
	{
	}
	return token;
}

string getTblName(string line)
{
	stringstream ss(line);
	string token;
	int i = 0;
	while (getline(ss, token, ' ') && i < 2)
	{
		i++;
	}
	return token;
}

void parseInput(const string& input, vector<string>& commands)
{
	stringstream ss(input);
	string token;
	while (getline(ss, token, ';'))
	{
		commands.push_back(token);
	}
}

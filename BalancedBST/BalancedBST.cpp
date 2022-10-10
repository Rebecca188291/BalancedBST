// BalancedBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "BST.h"
using namespace std;


int main()
{
	BST bst;

	bst.insert("A", 60000000);
	bst.insert("B", 70000000);
	bst.insert("C", 40000000);
	bst.insert("D", 20000000);
	bst.insert("E", 30000000);
	bst.insert("F", 90000000);
	bst.insert("G", 45000000);
	bst.insert("H", 10000000);
	bst.inorder();
	bst.removeinOrder(9); //shoiuld remove E
	bst.inorder();
	/*
	string numCommands;
	getline(cin, numCommands);
	string command;

	int numCommandsInt = stoi(numCommands);
	for (int i = 0; i < numCommandsInt; i++)
	{
		getline(cin, command);
		if ((command.substr(0, 6).compare("insert") == 0) && (command.substr(6, 1).compare(" ") == 0))
		{
			//the end of the string will be length - 18. Idk why but 10 was too little?
			int stringEnd = command.length() - 18;
			string name = command.substr(8, stringEnd);
			int idBeg = command.length() - 8; // length - 8
			string id = command.substr(idBeg, 8);
			if ((id.length() > 8) || id.length() < 8 || id.substr(0, 1).compare(" ") == 0)
			{
				cout << "unsuccessful" << endl;
			}
			else
			{
				try
				{
					int idNum = stoi(id);
					bst.insert(name, idNum);
				}
				catch (const invalid_argument& e)
				{
					cout << "unsuccessful" << endl;
					continue;
				}
			}
		}
		if ((command.substr(0, 6).compare("remove") == 0) && (command.substr(6, 1).compare(" ") == 0))
		{
			int idBeg = command.length() - 8; // length - 8
			string id = command.substr(idBeg, 8);
			if ((id.length() > 8) || id.length() < 8)
			{
				cout << "unsuccessful" << endl;
			}
			else
			{
				try
				{
					int idNum = stoi(id);
					bst.removal(idNum);
				}
				catch (const invalid_argument& e)
				{
					cout << "unsuccessful" << endl;
					continue;
				}
			}
		}
		if ((command.substr(0, 6).compare("search") == 0) && (command.substr(6, 1).compare(" ") == 0) && (command.substr(7,1).compare("\"") != 0))
		{
			int idBeg = command.length() - 8; // length - 8
			string id = command.substr(idBeg, 8);
			if ((id.length() > 8) || id.length() < 8)
			{
				cout << "unsuccessful" << endl;
			}
			else
			{
				try
				{
					int idNum = stoi(id);
					bst.search(idNum);
				}
				catch (const invalid_argument& e)
				{
					cout << "unsuccessful" << endl;
					continue;
				}
			}
		}
		if ((command.substr(0, 6).compare("search") == 0) && (command.substr(6, 1).compare(" ") == 0) && (command.substr(7, 1).compare("\"") == 0))
		{
			string name = command.substr(8, command.length() - 9);
			{
				bst.search(name);
			}
		}
		if ((command.substr(0, 12).compare("printInorder") == 0))
		{
			bst.inorder();
		}
		if ((command.substr(0, 13).compare("printPreorder") == 0))
		{
			bst.preorder();
		}
		if ((command.substr(0, 14).compare("printPostorder") == 0))
		{
			bst.postorder();
		}
		if ((command.substr(0, 15).compare("printLevelCount") == 0))
		{
			bst.printLevelCount();
		}
		if ((command.substr(0, 14).compare("removeInorder ") == 0))
		{
			string N = command.substr(command.length() - 1, 1);
			try
			{
				int iN = stoi(N);
				bst.removeinOrder(iN);
			}
			catch (const invalid_argument& e)
			{
				cout << "unsuccessful" << endl;
				continue;
			}
		}
	}	
	*/
}


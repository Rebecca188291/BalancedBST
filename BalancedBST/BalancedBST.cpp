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
	/*
	string numCommands;
	getline(cin, numCommands);
	string command;

	int numCommandsInt = stoi(numCommands);
	for (int i = 0; i < numCommandsInt; i++)
	{
		getline(cin, command);
		if (command.substr(0, 5) == "insert")
		{
			int endQuotePos = command.find('\"', 8);
			string name = command.substr(7, endQuotePos - 8);
			string id = command.substr(endQuotePos + 2, command.length() - endQuotePos + 2);
			if ((id.length() > 8) || id.length() < 8)
			{
				cout << "unsuccessful" << endl;
			}
			else
			{
				int idNum = stoi(id);
				bst.insert(name, idNum);
			}
		}
	}
	*/

	BST myTree;
	myTree.insert("Rebechka", 69696969);
	//myTree.insert("hi", 72584671);
	myTree.insert("Styops", 82042069);
	//myTree.insert("Bruh", 19777777);
	//myTree.insert("tank", 18777777);
	myTree.insert("kirby", 78777777);
	//myTree.insert("chaco", 70999999);
	//myTree.insert("mabel", 90999999);
	//myTree.insert("YESSS", 21000000);
	//myTree.insert("wowww", 31000000);

	//myTree.insert("Frank", 18999999);
	myTree.preorder();
	//myTree.removal(69696969);
	//cout << endl;
	////cout << myTree.root->name << endl;
	////cout << myTree.root->left->name << endl;
	//myTree.preorder();

	//cout << endl << endl << endl;
	////myTree.bruhTester();
	////cout << myTree.root->name << endl;
	////cout << myTree.root->name << endl;
	////BST::TreeNode* parent = myTree.root->left;
	////BST::TreeNode* child = parent->left;
	////myTree.leftRotation(parent, child);
	////myTree.preorder();
}


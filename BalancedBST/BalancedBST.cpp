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

	//string numCommands;
	//vector<string> commands;
	//getline(cin, numCommands);
	//int numCommandsInt = stoi(numCommands);

	//string command;

	/*
	for (int i = 0; i < numCommandsInt; i++)
	{
		getline(cin, command);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				commands.push_back(command.substr(0, i));
				command.erase(0, i + 1); //erase the space
			}
		}

		if (commands[0] == "insert")
		{
			int key = stoi(commands[2]);
			bst.insert(commands[1], key);
		}
		else if (commands[0] == "remove")
		{
			int key = stoi(commands[1]);
			bst.removal(key);
		}
		else if (commands[0] == "printInOrder")
		{
			bst.inorder();
		}
		else
		{
			//TO DO: Add all the other possible inputs later
		}

	}
	*/


	bst.insert("Lisa", 19498849); //work to have a leading 0 work too
	bst.insert("Nicole", 22222222);
	bst.insert("Frank", 12111001);
	bst.insert("Stefan", 20202020);
	bst.insert("John", 37010101);
	bst.insert("Dina", 10345678);
	bst.insert("Gary", 14235879);
	//bst.insert("Gary", 11235879);
	//bst.insert("Gary", 64235879);


	bst.inorder();
	bst.removeinOrder(3);
	bst.inorder();
	//bst.insert("Nick", 61845122);
	//bst.preorder();
	//bst.removal(19498849);
	//bst.insert("Carol", 35264789);
	//bst.insert("Tommy", 30215174);
	//bst.insert("Todd", 11000221);
	//bst.inorder();
	//bst.printLevelCount();
	//bst.removeinOrder(3);
	//bst.preorder();
	//bst.removal(35264789);
	//cout << endl;
	//bst.inorder();
	//cout << endl;
	//bst.search(11000221);
	//bst.search("Todd");

	//bst.insert("G", 11000221);
	//bst.removeinOrder(4); // shoulld remove Gary
	//bst.inorder();
	//cout << endl;
	//bst.removal(35264789);
	//bst.inorder();
	//cout << endl;

	//bst.inorder();
}


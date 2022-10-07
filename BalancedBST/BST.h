#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BST
{
public:
	struct TreeNode
	{
		int val;
		string name;
		int height = 1;
		int BF = 0;

		TreeNode* left;
		TreeNode* right;

		TreeNode(string a, int x) : name(a), val(x), left(nullptr), right(nullptr) {}
	};

	TreeNode* root = nullptr;


	void bruhTester();


	BST::TreeNode* helperInsert(TreeNode* root, string a, int key);
	void helpInorder(TreeNode* root);
	bool helpValidName(string a);
	bool helpValidKey(int key);
	BST::TreeNode* helperSearchID(TreeNode* root, int key);
	void helperSearchName(TreeNode* root, string a);
	BST::TreeNode* parentSearch(TreeNode* root, int key);
	BST::TreeNode* successorFinder(TreeNode* root);
	void calculateBF(TreeNode* root);
	void calculateH(TreeNode* root);
	void rotation(TreeNode* parent, TreeNode* child);
	void rightRotation(TreeNode* parent, TreeNode* child);
	void leftRotation(TreeNode* parent, TreeNode* child);
	void rightLeftRotation(TreeNode* parent, TreeNode* child);
	void leftRightRotation(TreeNode* parent, TreeNode* child);
	void findNNode(TreeNode* root, int n);
	void helperPreorder(TreeNode* root);
	void helperPostorder(TreeNode* root);
	void removalHelper(int key);
	void removeMainRoot();
	void printLevelHelper(TreeNode* root);
	void test();


	void inorder();
	void preorder();
	void postorder();
	void insert(string a, int key);
	void search(int key);
	void search(string a);
	void removal(int key);
	void removeinOrder(int n);
	void printLevelCount();
};


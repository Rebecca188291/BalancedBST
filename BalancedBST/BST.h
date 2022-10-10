#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BST
{
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


	void destruct(TreeNode* root)
	{
		if (root->left != nullptr)
		{
			destruct(root->left);
		}
		if (root->right != nullptr)
		{
			destruct(root->right);
		}
		delete root;
		root = nullptr;
	}
	BST::TreeNode* helperInsert(TreeNode* root, string a, int key);
	void helpInorder(TreeNode* root, vector<string>& names);
	bool helpValidName(string a);
	bool helpValidKey(int key);
	BST::TreeNode* helperSearchID(TreeNode* root, int key);
	void helperSearchName(TreeNode* root, string a, bool& found);
	BST::TreeNode* parentSearch(TreeNode* root, int key);
	BST::TreeNode* successorFinder(TreeNode* root);
	int calculateBF(TreeNode* root);
	int calculateH(TreeNode* root);
	BST::TreeNode* rotate(TreeNode* node);
	void findNNode(TreeNode* root, int n, int& num, bool& found);
	void helperPreorder(TreeNode* root, vector<string>& names);
	void helperPostorder(TreeNode* root, vector<string>& names);
	void removalHelper(int key);
	void updateHeightAfterRemove(TreeNode* root, int key);
	void printLevelHelper(TreeNode* root);

public:

	~BST()
	{
		destruct(this->root);
	}
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


#include "BST.h"
using namespace std;


//test

//the insertion functions
BST::TreeNode* BST::helperInsert(TreeNode* root, string a, int key)
{
	if (root == nullptr)
	{
		cout << "successful" << endl;
		return new TreeNode(a, key);
	}
	else if (key < root->val)
	{
		root->left = helperInsert(root->left, a, key);
	}
	else
	{
		root->right = helperInsert(root->right, a, key);

	}

	root->height = calculateH(root);
	root->BF = calculateBF(root);

	if (root->BF > 1 || root->BF < -1)
	{
		TreeNode* newRoot = rotate(root);
		return newRoot;
	}
	return root;
}
void BST::insert(string a, int key)
{
	bool validName = helpValidName(a);
	bool validID = helpValidKey(key);
	if (!validName)
	{
		cout << "unsuccessful" << endl;
		return;
	}
	if (!validID)
	{
		cout << "unsuccessful" << endl;
		return;
	}
	this->root = helperInsert(this->root, a, key);

}

//the traversal functions
void BST::helpInorder(BST::TreeNode* root, vector<string>& names)
{
	if (root == nullptr)
	{
		cout << "";
	}
	else
	{
		helpInorder(root->left, names);
		names.push_back(root->name);
		helpInorder(root->right, names);
	}
}
void BST::inorder()
{
	vector<string> names;
	helpInorder(this->root, names);
	for (int i = 0; i < names.size(); i++)
	{
		if (i == names.size() - 1)
		{
			cout << names[i] << endl;
		}
		else
		{
			cout << names[i] << ", ";
		}
	}
}
void BST::helperPreorder(TreeNode* root, vector<string>& names)
{
	if (root == nullptr)
	{
		cout << "";
	}
	else
	{
		names.push_back(root->name);
		helperPreorder(root->left, names);
		helperPreorder(root->right, names);
	}
}
void BST::preorder()
{
	vector<string> names;
	helperPreorder(this->root, names);
	for (int i = 0; i < names.size(); i++)
	{
		if (i == names.size() - 1)
		{
			cout << names[i] << endl;
		}
		else
		{
			cout << names[i] << ", ";
		}
	}
}
void BST::helperPostorder(TreeNode* root, vector<string>& names)
{
	if (root == nullptr)
	{
		cout << "";
	}
	else
	{
		helperPostorder(root->left, names);
		helperPostorder(root->right, names);
		names.push_back(root->name);
	}
}
void BST::postorder()
{
	vector<string> names;
	helperPostorder(this->root, names);
	for (int i = 0; i < names.size(); i++)
	{
		if (i == names.size() - 1)
		{
			cout << names[i] << endl;
		}
		else
		{
			cout << names[i] << ", ";
		}
	}
}
void BST::printLevelHelper(TreeNode* root)
{
	if (root == nullptr)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << (root->height) << endl;
	}
}
void BST::printLevelCount()
{
	printLevelHelper(this->root);
}



//create checks for validity
bool BST::helpValidName(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < 65 && a[i] != 32)
		{
			return false;
		}
		if ((a[i] >= 91) && (a[i] <= 96))
		{
			return false;
		}
		if (a[i] >= 123)
		{
			return false;
		}
	}
	return true;
}
bool BST::helpValidKey(int key)
{
	TreeNode* SRoot = helperSearchID(this->root, key);
	if (SRoot != nullptr)
	{
		return false;
	}
	return true;
}

//create the search functions
BST::TreeNode* BST::helperSearchID(TreeNode* root, int key)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->val == key)
	{
		return root;
	}
	if (root->val > key)
	{
		helperSearchID(root->left, key);
	}
	else
	{
		helperSearchID(root->right, key);
	}

}
void BST::search(int key)
{
	TreeNode* SRoot = helperSearchID(this->root, key);
	if (SRoot != nullptr)
	{
		cout << SRoot->name << endl;
	}
	else
	{
		cout << "unsuccessful" << endl;
	}

}
void BST::helperSearchName(TreeNode * root, string a, bool& found)
{
	if (root == nullptr)
	{
		cout << "";
	}
	else
	{
		if (root->name == a)
		{
			string id = "";
			if (root->val < 10)
			{
				id = "0000000";
				id += to_string(root->val);
			}
			else if (root->val < 100)
			{
				id = "000000";
				id += to_string(root->val);
			}
			else if (root->val < 1000)
			{
				id = "00000";
				id += to_string(root->val);
			}
			else if (root->val < 10000)
			{
				id = "0000";
				id += to_string(root->val);
			}
			else if (root->val < 100000)
			{
				id = "000";
				id += to_string(root->val);
			}
			else if (root->val < 1000000)
			{
				id = "00";
				id += to_string(root->val);
			}
			else if (root->val < 10000000)
			{
				id = "0";
				id += to_string(root->val);
			}
			else
			{
				id = to_string(root->val);
			}

			cout << id << endl;
			found = true;
		}
		helperSearchName(root->left, a, found);
		helperSearchName(root->right, a, found);
	}
}
void BST::search(string a)
{
	bool found = false;
	helperSearchName(this->root, a, found);
	if (!found)
	{
		cout << "unsuccessful" << endl;
	}

}



//create functions for removal
void BST::updateHeightAfterRemove(TreeNode* root, int key)
{
	if (root == nullptr)
	{
		return;
	}
	else if (root->val == key)
	{
		root->height = calculateH(root);
		return;
	}
	else if (root->val < key)
	{
		updateHeightAfterRemove(root->right, key);
	}
	else
	{
		updateHeightAfterRemove(root->left, key);	
	}

	root->height = calculateH(root);
	return;
}
BST::TreeNode* BST::parentSearch(TreeNode* root, int key)
{
	if (root == nullptr || this->root->val == key)
	{
		return nullptr;
	}
	else if (root->val < key)
	{
		if (root->right == nullptr)
		{
			//cout << "ran out of tree, did not find on right" << endl;
			return nullptr;
		}
		else if (root->right->val == key)
		{
			//cout << "I found that blasted root!" << endl;
			return root;
		}
		else
		{
			//cout << "curr root val: " << root->val << "keep lookin right" << endl;
			parentSearch(root->right, key);
		}
	}
	else
	{
		if (root->left == nullptr)
		{
			//cout << "ran out of tree, did not find on left" << endl;
			return nullptr;
		}
		else if (root->left->val == key)
		{
			//cout << "I found that blasted root!" << endl;
			return root;
		}
		else
		{
			//cout << "curr root val: " << root->val << "keep lookin left" << endl;
			parentSearch(root->left, key);
		}
	}

}
BST::TreeNode* BST::successorFinder(TreeNode* root)
{
	if (root->left == nullptr)
	{
		return root;
	}
	else
	{
		successorFinder(root->left);
	}
}
void BST::removalHelper(int key)
{

	TreeNode* parentofDelete = nullptr;
	TreeNode* toDelete = nullptr;
	TreeNode* successor = nullptr;
	TreeNode* parentSuccessor = nullptr;

	//code for trying to remove the main root
	if (this->root->val == key)
	{
		successor = successorFinder(this->root->right);
		toDelete = this->root;
		if (successor != nullptr)
		{
			parentSuccessor = parentSearch(this->root, successor->val);
			if (parentSuccessor == nullptr)
			{
				cout << "null par" << endl;
			}
			if (parentSuccessor == toDelete)
			{
				successor->left = toDelete->left;
				this->root = successor;
				delete toDelete;
				toDelete = nullptr;
				return;
			}
			if (successor->right != nullptr && parentSuccessor != nullptr)
			{
				parentSuccessor->left = successor->right;
			}
			successor->left = toDelete->left;
			successor->right = toDelete->right;
			this->root = successor;
			delete toDelete;
			toDelete = nullptr;
			if (parentSuccessor != nullptr)
			{
				parentSuccessor->left = nullptr;
				updateHeightAfterRemove(this->root, parentSuccessor->val);
			}
		}
		else
		{
			cout << "unsuccessful" << endl;
		}
		return;

	}




	//if its not the main root, find the parent
	parentofDelete = parentSearch(this->root, key);
	if (parentofDelete == nullptr)
	{
		cout << "unsuccessful" << endl;
		return;
	}

	//now to find which needs to be removed
	else if (parentofDelete != nullptr && parentofDelete->val < key)
	{
		//delete right, check how many kids it has
		toDelete = parentofDelete->right;
		if ((toDelete->left == nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->right = nullptr;
			delete toDelete;
			toDelete = nullptr;
		}
		else if ((toDelete->left != nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->right = toDelete->left;
			delete toDelete;
			toDelete = nullptr;
			cout << "successful" << endl;

		}
		else if ((toDelete->left == nullptr) && (toDelete->right != nullptr))
		{
			
			parentofDelete->right = toDelete->right;
			delete toDelete;
			toDelete = nullptr;
			cout << "successful" << endl;

		}
		else 
		{
			if (toDelete->right != nullptr)
			{
				successor = successorFinder(toDelete->right);
				parentSuccessor = parentSearch(this->root, successor->val);
				parentofDelete->right = successor;
				successor->left = toDelete->left;
				if (parentSuccessor != toDelete)
				{
					parentSuccessor->left = nullptr;
					if (successor->right != nullptr)
					{
						parentSuccessor->left = successor->right;
					}
					successor->right = toDelete->right;
				}
				delete toDelete;
				toDelete = nullptr;
				cout << "successful" << endl;
			}
		}
	}
	else if (parentofDelete != nullptr && parentofDelete->val > key)
	{
		//delete left, check how many kids it has
		toDelete = parentofDelete->left;
		if ((toDelete->left == nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->left = nullptr;
			delete toDelete;
			toDelete = nullptr;
			cout << "successful" << endl;

		}
		else if ((toDelete->left != nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->left = toDelete->left;
			delete toDelete;
			toDelete = nullptr;
			cout << "successful" << endl;
		}
		else if ((toDelete->left == nullptr) && (toDelete->right != nullptr))
		{
			parentofDelete->left = toDelete->right;
			delete toDelete;
			toDelete = nullptr;
			cout << "successful" << endl;
		}
		else
		{
			if (toDelete->right != nullptr)
			{
				successor = successorFinder(toDelete->right);
				key = successor->val;
				parentSuccessor = parentSearch(this->root, successor->val);
				//cout << parentSuccessor->name << endl;
				if (parentSuccessor != toDelete)
				{
					successor->right = toDelete->right;
					parentSuccessor->left = nullptr;

				}
				successor->left = toDelete->left;
				parentofDelete->left = successor;
				delete toDelete;
				toDelete = nullptr;
				cout << "successful" << endl;

			}
			else
			{
				successor = toDelete->right;
				successor->left = toDelete->left;
				parentofDelete->right = successor;
				delete toDelete;
				toDelete = nullptr;
				cout << "successful" << endl;

			}
		}
	}
	else
	{
	cout << "nothing" << endl;
	}
	
	if (successor == nullptr)
	{
		updateHeightAfterRemove(this->root, parentofDelete->val);
	}
	else
	{
		updateHeightAfterRemove(this->root, parentSuccessor->val);
	}
	return;
}
void BST::removal(int key)
{
	removalHelper(key);
}


//create functions for rebalancing
int BST::calculateBF(TreeNode* root)
{
	int lh = 0;
	int rh = 0;
	if (root->left != nullptr)
	{
		lh = root->left->height;
	}
	if (root->right != nullptr)
	{
		rh = root->right->height;

	}
	return lh - rh;
	
}
int BST::calculateH(TreeNode* root)
{
	int lh = 0;
	int rh = 0;
	if (root->left != nullptr)
	{ 
		lh = root->left->height;
	}
	if (root->right != nullptr)
	{
		rh = root->right->height;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		return 1;
	}
	else if (lh > rh)
	{
		return lh + 1;
	}
	else
	{
		return rh + 1;
	}
}
BST::TreeNode* BST::rotate(TreeNode* node)
{
	TreeNode* child = nullptr;
	if (node->right != nullptr && (node->right->BF == -1 || node->right->BF == 1))
	{
		child = node->right;
	}
	else
	{
		child = node->left;

	}
	if (node->BF == -2)
	{
		if (child->BF == -1)
		{
			if (child->left != nullptr)
			{
				node->right = child->left;
			}
			else
			{
				node->right = nullptr;

			}
			child->left = node;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			return child;
		}
		else
		{
			TreeNode* grandchild = child->left;
			if (grandchild->left != nullptr)
			{
				child->left = grandchild->left;
			}
			else
			{
				child->left = nullptr;
			}
			if (grandchild->right != nullptr)
			{
				node->right = grandchild->right;
			}
			else
			{
				node->right = nullptr;
			}
			grandchild->right =child;
			grandchild->left = node;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			grandchild->height = calculateH(grandchild);
			grandchild->BF = calculateBF(grandchild);
			return grandchild;

		}
	}
	else
	{
		if (child->BF == -1)
		{
			TreeNode* grandchild = child->right;
			if (grandchild->left != nullptr)
			{
				child->right = grandchild->left;			}
			else
			{
				child->left = nullptr;
			}
			if (grandchild->right != nullptr)
			{
				node->left = grandchild->right;
			}
			else
			{
				node->right = nullptr;
			}
			grandchild->left = child;
			child->right = nullptr;
			grandchild->right = node;
			node->left = nullptr;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			grandchild->height = calculateH(grandchild);
			grandchild->BF = calculateBF(grandchild);
			return grandchild;
		}
		else
		{
			if (child->right != nullptr)
			{
				node->left = child->right;
			}
			else
			{
				node->left = nullptr;
			}
			child->right = node;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			return child;
		}
	}
}

//Functions for removing nth node
void BST::findNNode(TreeNode* root, int n, int& num, bool& found)
{
	if (num > n)
	{
		return;
	}
	if (root == nullptr)
	{
		return;
	}
	else
	{
		findNNode(root->left, n, num, found);
		if (num == n)
		{
			removal(root->val);
			found = true;
			num++;
			return;
		}
		num++;
		findNNode(root->right, n, num, found);
	}
}
void BST::removeinOrder(int n)
{
	int num = 0;
	bool found = false;
	findNNode(this->root, n, num, found);
	if (!found)
	{
		cout << "unsuccessful" << endl;
	}
}




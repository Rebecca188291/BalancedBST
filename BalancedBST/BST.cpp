#include "BST.h"


//the insertion functions
BST::TreeNode* BST::helperInsert(TreeNode* root, string a, int key, TreeNode*& mainRoot)
{
	//calculateH(root);
	//calculateBF(root);
	if (root == nullptr)
	{
		cout << "successful" << endl;
		return new TreeNode(a, key);
	}
	else if (key < root->val)
	{
		root->left = helperInsert(root->left, a, key, mainRoot);

	}
	else
	{
		root->right = helperInsert(root->right, a, key, mainRoot);

	}
	calculateH(root);
	calculateBF(root);	

	if ((root->BF > 1 || root->BF < -1))
	{
		if (root->left != nullptr)
		{
			if (root->left->BF == 1 || root->left->BF == -1)
			{
				cout << "will pass in left root" << endl;
				rotation(root, root->left, mainRoot);
			}
		}
		if (root->right != nullptr)
		{
			if (root->right->BF == 1 || root->right->BF == -1)
			{
				cout << "will pass in right root." <<  endl;
				rotation(root, root->right, mainRoot);
			}
		}
	}
	calculateH(root);
	calculateBF(root);
	return root;
}
void BST::insert(string a, int key)
{
	bool validName = helpValidName(a);
	bool validID = helpValidKey(key);
	if (!validName)
	{
		cout << "unsuccessful" << endl;
	}
	if (!validID)
	{
		cout << "unsuccessful" << endl;
	}
	else
	{
		if (this->root == nullptr)
		{
			this->root = new TreeNode(a, key);
			TreeNode*& mainRoot = this->root;
			cout << "successful" << endl;
			return;
		}
		helperInsert(this->root, a, key, this->root);
	}
}

//the traversal functions TO DO FIX POST ORDER
void BST::helpInorder(BST::TreeNode* root)
{
	if (root == NULL)
	{
		cout << "";
	}
	else
	{
		helpInorder(root->left);
		cout << root->name << " " << root->val << " " << root->height << " " << root->BF << endl;
		helpInorder(root->right);
	}
}
void BST::inorder()
{
	helpInorder(this->root);
}
void BST::helperPreorder(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "";
	}
	else
	{
		cout << root->name << " " << root->val << " " << root->height << " " << root->BF << endl;
		helperPreorder(root->left);
		helperPreorder(root->right);
	}
}
void BST::preorder()
{
	helperPreorder(this->root);
}
void BST::helperPostorder(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "";
	}
	else
	{
		helperPostorder(root->left);
		helperPostorder(root->right);
		cout << root->name << " " << root->val << " " << root->height << " " << root->BF << endl;
	}
}
void BST::postorder()
{
	helperPostorder(this->root);
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
	string GatorID = to_string(key);
	if (GatorID.length() != 8)
	{
		return false;
	}
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
void BST::helperSearchName(TreeNode* root, string a)
{
	if (root == nullptr)
	{
		cout << "";
	}
	else
	{
		if (root->name == a)
		{
			cout << root->val << endl;
		}
		helperSearchName(root->left, a);
		helperSearchName(root->right, a);
	}

}
void BST::search(string a)
{
	helperSearchName(this->root, a);

}



//create functions for removal
BST::TreeNode* BST::parentSearch(TreeNode* root, int key)
{
	if (root == nullptr)
	{
		cout << "root = nullptr" << endl;
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


	if (this->root->val == key)
	{
		successor = successorFinder(this->root->right);
		toDelete = this->root;
		if (successor != nullptr)
		{
			parentSuccessor = parentSearch(this->root, successor->val);
			parentSuccessor->left = nullptr;
			successor->left = toDelete->left;
			successor->right = toDelete->right;
			this->root = successor;
			delete toDelete;
		}
		else
		{
			cout << "unsuccessful" << endl;
		}
		return;

	}


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
			cout << "successful" << endl;
		}
		else if ((toDelete->left != nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->right = toDelete->left;
			cout << "successful" << endl;

		}
		else if ((toDelete->left == nullptr) && (toDelete->right != nullptr))
		{
			parentofDelete->right = toDelete->right;
			cout << "successful" << endl;

		}
		else
		{
			//cout << "toDelete left but right before finding succ " << toDelete->left->val << endl;
			if (toDelete->right->right != nullptr)
			{
				successor = successorFinder(toDelete->right);
				key = successor->val;
				//cout << "toDelete left but right after finding succ " << toDelete->left->val << endl;
				//cout << parentSuccessor->val << endl;
				parentSuccessor = parentSearch(this->root, successor->val);
				parentSuccessor->left = nullptr;
				successor->right = toDelete->right;
				//cout << "succ right: " << successor->right->val << endl;
				successor->left = toDelete->left;
				//cout << "delete left: " << toDelete->left->val << endl;
				//cout << "succ left: " << successor->left->val << endl;
				parentofDelete->right = successor;
				//cout << "parent of succ points to: " << parentofDelete->right->val;
				delete toDelete;
				cout << "successful" << endl;

			}
			else
			{
				successor = toDelete->right;
				successor->left = toDelete->left;
				parentofDelete->right = successor;
				cout << "successful" << endl;

			}

		}
	}
	else
	{
		//delete left, check how many kids it has
		toDelete = parentofDelete->left;
		if ((toDelete->left == nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->left = nullptr;
			delete toDelete;
			cout << "successful" << endl;

		}
		else if ((toDelete->left != nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->left = toDelete->left;
			delete toDelete;
			cout << "successful" << endl;


		}
		else if ((toDelete->left == nullptr) && (toDelete->right != nullptr))
		{
			parentofDelete->left = toDelete->right;
			delete toDelete;
			cout << "successful" << endl;


		}
		else
		{
			if (toDelete->right->right != nullptr)
			{
				successor = successorFinder(toDelete->right);
				key = successor->val;
				parentSuccessor = parentSearch(this->root, successor->val);
				//cout << parentSuccessor->name << endl;
				parentSuccessor->left = nullptr;
				successor->right = toDelete->right;
				successor->left = toDelete->left;
				parentofDelete->right = successor;
				delete toDelete;
				cout << "successful" << endl;

			}
			else
			{
				successor = toDelete->right;
				successor->left = toDelete->left;
				parentofDelete->right = successor;
				cout << "successful" << endl;

			}

		}

	}
	//calculateH(this->root);
	return;
}
void BST::removeMainRoot(TreeNode*& mainRoot)
{
	if (mainRoot->right != nullptr)
	{
		TreeNode* successor = successorFinder(mainRoot->right);
		TreeNode* toDelete = mainRoot;
		successor->left = mainRoot->left;
		mainRoot = successor;
		delete toDelete;
	}
	else if (mainRoot->left != nullptr)
	{
		TreeNode* toDelete = mainRoot;
		mainRoot->left = nullptr;
		mainRoot = mainRoot->left;
		delete toDelete;
	}
	else if (mainRoot == nullptr)
	{
		return;
	}
	else
	{
		mainRoot = nullptr;
	}

}
void BST::removal(int key)
{
	if (this->root->val == key)
	{
		cout << "remove main root" << endl;
		removeMainRoot(this->root);
	}
	else
	{
		removalHelper(key);
	}
}


//create functions for rebalancing
void BST::calculateBF(TreeNode* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		root->BF = 0;
	}
	else if (root->left != nullptr && root->right == nullptr)
	{
		root->BF = root->left->height;
	}
	else if (root->left == nullptr && root->right != nullptr)
	{
		root->BF = 0 - root->right->height;
	}
	else
	{
		root->BF = root->left->height - root->right->height;
	}
}
void BST::calculateH(TreeNode* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		root->height = 1;
	}
	else if (root->left == nullptr && root->right != nullptr)
	{
		root->height = root->right->height + 1;
	}
	else if (root->left != nullptr && root->right == nullptr)
	{
		root->height = root->left->height + 1;
	}
	else
	{
		if (root->left->height > root->right->height)
		{
			root->height = root->left->height + 1;
		}
		else
		{
			root->height = root->right->height + 1;

		}
	}

	//|| (root->left->height < root->right->height)
}
void BST::rotation(TreeNode* parent, TreeNode* child, TreeNode*& mainRoot)
{
	if (parent->BF == 2 && child->BF == 1)
	{
		cout << "right rotation" << endl;
		rightRotation(parent, child, mainRoot);
	}
	else if (parent->BF == -2 && child->BF == -1)
	{
		cout << "left rotation" << endl;
		leftRotation(parent, child, mainRoot);
	}
	else if (parent->BF == 2 && child->BF == -1)
	{
		cout << "left right rotation" << endl;
	}
	else
	{
		cout << "pass into right Left" << endl;
		rightLeftRotation(parent, child, mainRoot);
	}
	return;
}
void BST::rightRotation(TreeNode* parent, TreeNode* child, TreeNode*& mainRoot)
{
	TreeNode* grandpa = parentSearch(mainRoot, parent->val);
	if (grandpa == nullptr)
	{
		child->left = parent;
		parent->right = nullptr;
		mainRoot = child;
		return;
	}
	if (grandpa->val < child->val)
	{
		child->left = parent;
		parent->right = nullptr;
		grandpa->right = child;
	}
	else
	{
		child->left = parent;
		parent->right = nullptr;
		grandpa->left = child;
	}
	return;
}
void BST::leftRotation(TreeNode* parent, TreeNode* child, TreeNode*& mainRoot)
{
	TreeNode* grandpa = parentSearch(mainRoot, parent->val);
	if (grandpa == nullptr)
	{
		child->left = parent;
		parent->right = nullptr;
		mainRoot = child;
		cout << "new main root: " << mainRoot->name << endl;
		return;
	}
	if (grandpa->val < child->val)
	{
		child->left = parent;
		grandpa->right = nullptr;
		grandpa->right = child;
		parent->right = nullptr;
	}
	else
	{
		child->right = parent;
		parent->left = nullptr;
		grandpa->right = child;
	}
	return;
}
void BST::rightLeftRotation(TreeNode* parent, TreeNode* child, TreeNode*& mainRoot)
{
	TreeNode* grandpa = parentSearch(mainRoot, parent->val);
	TreeNode* grandchild = nullptr;
	if (grandpa == nullptr)
	{
		//Something wonky going on in here, fix later
		grandchild = child->left;
		grandchild->right = child;
		grandchild->left = parent;
		mainRoot = grandchild;
		parent->right = nullptr;
		child->left = nullptr;
		cout << "grandpa null" << endl;
		return;
	}
	if (grandpa->val < child->val)
	{
		grandchild->right = child;
		grandchild->left = parent;
		grandpa->right = grandchild;
		child->left = nullptr;
		parent->right = nullptr;
	}
	else
	{
		//actually have to find grandchild
		grandchild->right = child;
		grandchild->left = parent;
		grandpa->left = grandchild;
		child->left = nullptr;
		parent->right = nullptr;
	}
	return;
}
void BST::leftRightRotation(TreeNode* parent, TreeNode* child, TreeNode*& mainRoot)
{}

//Functions for removing nth node
void BST::findNNode(TreeNode* root, int n)
{
	static int count = 0;
	if (root == nullptr)
	{
		return;
	}
	if (count < n)
	{
		findNNode(root->left, n);
		count++;
		if (count == n)
		{
			cout << "removing: " << this->root->name << endl;
			removal(this->root->val);
			return;
		}
		findNNode(this->root->right, n);
	}

}
void BST::removeinOrder(int n)
{
	findNNode(this->root, n);
}



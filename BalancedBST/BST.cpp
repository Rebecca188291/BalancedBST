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
		//cout << "new root: " << newRoot->name << endl;
		//newRoot->height = calculateH(newRoot);
		//cout << newRoot->height << endl;
		//newRoot->BF = calculateBF(newRoot);
		//cout << newRoot->BF << endl;
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
	}
	if (!validID)
	{
		cout << "unsuccessful" << endl;
	}

	this->root = helperInsert(this->root, a, key);

}

//the traversal functions
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
void BST::updateHeightAfterRemove(TreeNode* root, int key)
{
	if (root == nullptr)
	{
		return;
	}
	else if (root->val == key)
	{
		int rh = 0;
		int lh = 0;
		if (root->left != nullptr)
		{
			lh = root->left->height;
		}
		if (root->right != nullptr)
		{
			rh = root->right->height;
		}
		if ((rh > lh) && (root->right != nullptr))
		{
			root->height = root->right->height + 1;
		}
		else if ((lh >= rh) && (root->left != nullptr))
		{
			root->height = root->left->height + 1;

		}
		else
		{
			root->height = 1;
		}
		return;
	}
	else if (root->val < key)
	{
		updateHeightAfterRemove(root->right, key);
		int rh = 0;
		int lh = 0;
		if (root->left != nullptr)
		{
			lh = root->left->height;
		}
		if (root->right != nullptr)
		{
			rh = root->right->height;
		}
		if (rh > lh)
		{
			root->height = rh + 1;
		}
		else
		{
			root->height = lh + 1;

		}		
		return;
	}
	else
	{
		updateHeightAfterRemove(root->left, key);
		int rh = 0;
		int lh = 0;
		if (root->left != nullptr)
		{
			lh = root->left->height;
		}
		if (root->right != nullptr)
		{
			rh = root->right->height;
		}
		if (rh > lh)
		{
			root->height = rh + 1;
		}
		else
		{
			root->height = lh + 1;

		}
		cout << "after update: " << "height: " << root->height << endl;		
		return;
	}
}
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

	//code for trying to remove the main root
	if (this->root->val == key)
	{
		successor = successorFinder(this->root->right);
		toDelete = this->root;
		if (successor != nullptr)
		{
			parentofDelete = parentSearch(this->root, toDelete->val);
			parentSuccessor = parentSearch(this->root, successor->val);
			parentSuccessor->left = nullptr;
			successor->left = toDelete->left;
			successor->right = toDelete->right;
			this->root = successor;
			delete toDelete;
			cout << "i got to this point" << endl;
			cout << this->root->right->name << endl;
			cout << this->root->name << endl;
			cout << successor->right->name << endl;
			//updateHeightAfterRemove(this->root, parentofDelete->val);
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
			cout << "successful" << endl;
		}
		else if ((toDelete->left != nullptr) && (toDelete->right == nullptr))
		{
			parentofDelete->right = toDelete->left;
			cout << "successful" << endl;

		}
		else if ((toDelete->left == nullptr) && (toDelete->right != nullptr))
		{
			
			successor = successorFinder(toDelete->right);
			parentSuccessor = parentSearch(this->root, successor->val);
			parentofDelete->right = successor;
			successor->left = toDelete->left;
			successor->right = toDelete->right;
			parentSuccessor->left = nullptr;
			cout << "successful" << endl;

		}
		else //if toDelete left is not null and to delete right is not null
		{
			//cout << "toDelete left but right before finding succ " << toDelete->left->val << endl;
			if (toDelete->right != nullptr)
			{
				successor = successorFinder(toDelete->right);
				parentSuccessor = parentSearch(this->root, successor->val);
				parentofDelete->right = successor;
				successor->left = toDelete->left;
				if (parentSuccessor != toDelete)
				{
					successor->right = toDelete->right;
					parentSuccessor->left = nullptr;

				}
				delete toDelete;
				cout << "successful" << endl;
			}
		}
		updateHeightAfterRemove(this->root, parentofDelete->val);
	}
	else if (parentofDelete != nullptr && parentofDelete->val > key)
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
	
	updateHeightAfterRemove(this->root, parentofDelete->val);

	}
	else
	{
	cout << "nothing" << endl;
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
			child->left = node;
			node->right = nullptr;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			return child;
		}
		else
		{
			TreeNode* grandchild = child->left;
			grandchild->right = child;
			child->left = nullptr;
			grandchild->left = node;
			node->right = nullptr;
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
			child->right = node;
			node->left = nullptr;
			node->height = calculateH(node);
			node->BF = calculateBF(node);
			child->height = calculateH(child);
			child->BF = calculateBF(child);
			return child;
		}
	}
}
//BST::TreeNode* BST::rightRotation(TreeNode* parent)
//{
//	
//	TreeNode* grandpa = parentSearch(this->root, parent->val);
//	if (grandpa == nullptr)
//	{
//		child->left = parent;
//		cout << child->name << endl;
//		parent->right = nullptr;
//		this->root = child;
//		return this->root;
//	}
//	else
//	{
//		child->left = parent;
//		parent->right = nullptr;
//		grandpa->left = child;
//		return child;
//	}
//	return;
//}
void BST::leftRotation(TreeNode* parent, TreeNode* child)
{
	TreeNode* grandpa = parentSearch(this->root, parent->val);
	if (grandpa == nullptr)
	{
		child->right = parent;
		parent->left = nullptr;
		this->root = child;
	}
	else if (grandpa == this->root)
	{
		child->right = parent;
		parent->left = nullptr;
		this->root->left = child;
	}
	else
	{
		//cout << "Grandma: " << grandpa->name << endl;
		//cout << "parent: " << parent->name << endl;
		//cout << "child: " << child->name << endl;
		child->right = parent;
		parent->left = nullptr;
		grandpa->left = child;
		return;
		/*cout << "child right should be: " << parent->name << " and it is: " << child->right->name << endl;
		cout << "parent left should be: nullptr" << " and it is: ";
		if (parent->left == nullptr)
		{
			cout << "nullptr " << endl;
		}*/
		//cout << "grandpa left should be: " << child->name << " and it is: " << grandpa->left->name << endl;

	}
	
	return;
}
void BST::rightLeftRotation(TreeNode* parent, TreeNode* child)
{
	
	return;
}
void BST::leftRightRotation(TreeNode* parent, TreeNode* child)
{}

//Functions for removing nth node
void BST::findNNode(TreeNode* root, int n, int& num)
{
	if (root == nullptr)
	{
		return;
	}
	if (num < n)
	{
		findNNode(root->left, n, num);
		num++;
		if (num == n)
		{
			cout << "removing: " << this->root->name << endl;
			removal(this->root->val);
			return;
		}
		findNNode(this->root->right, n, num);
	}

}
void BST::removeinOrder(int n)
{
	int num = 0;
	findNNode(this->root, n, num);
}




#include <bits/stdc++.h>
using namespace std;


class TreeNode{
	public: 
		TreeNode* left;
		TreeNode* right;
		int data;
		TreeNode(int data){
			this->data=data;
			this->left = nullptr;
			this->right = nullptr;
		}
}


class BST{
	private:
		map<int,int> index;
		
	public:
		TreeNode* createBSTInorderPreOrder(vector<int>& inorder,vector<int> preorder){
			int i = 0;
			for (int x : inorder){
				index[i]=x;
				i++;
			}
			TreeNode* root = createBSTInorderPreOrderHelper(inorder,preorder,0,0,inorder.size());
			return root;
		}
		TreeNode* createBSTInorderPreOrderHelper(vector<int>& inorder,vector<int> preorder,int prepoint,int left,int right){
			if(inorder.empty()||preorder.empty())	 return nullptr;
			if (left>right) return nullptr;
			TreeNode* node = new TreeNode(preorder[prepoint]);
			int ind = index[preorder[prepoint]];
			node->left =createBSTInorderPreOrderHelper(inorder,preorder,prepoint+1,left,ind-1);
			node->right =createBSTInorderPreOrderHelper(inorder,preorder,prepoint+1,ind+1,right);
			return node;
		}
		void printPre(TreeNode* root){
			cout << root->data << endl;
			printPre(root->left);
			printPre(root->right);
		}
};

int main(){
	BST* bst = new BST();
	vector<int> in = {1,2,3,4,5,6,7};
	vector<int> pre = {4,2,1,3,5,6,7};
	BST->printPre(BST.createBSTInorderPReORder(in,pre));
		return 0;
}


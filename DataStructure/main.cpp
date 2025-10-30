#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
struct  Node
{
    int data;
    Node* llink;
    Node* rlink;
    Node(int data,Node* rlink,Node*llink) {
        this->data = data;
        this->llink= rlink;
        this->rlink= llink;
    }
};

struct LinkedListNode{
    TreeNode* node;
    TreeNode* link;
    LinkedListNode(TreeNode* node,TreeNode* link){
        this->link = link;
        this->node = node;
    }
};


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data  = data;
    }
};

class BinaryTreeNode{
    public: 
    int inorderR(TreeNode* T){
        if (T==NULL)  return -1;
        inorderR(T->left);
        printf("%d\n",T->data);
        inorderR(T->right);
    }
    
    //program to connect all the leaf nodes of a binary tree as a DLL
    Node* conLeaves(TreeNode* T){
        if (T==NULL) return NULL;
        if (T->left == NULL && T->right == NULL) return new Node(T->data,NULL,NULL);
        stack<BinaryTreeNode> s ;
        Node* L = NULL;
        Node* F = NULL;
        s.push(*T);
        while (!s.empty());


    }

};


int main()
{
    TreeNode* T =new  TreeNode(1);
    T->left = new TreeNode(2);
    T->left->left = new TreeNode(4);
    T->left->right->left = new TreeNode(8);
    T->right = new TreeNode(3);
    T->right->right = new TreeNode(7);
    T->right->left= new TreeNode(6);
    T->right->left->right= new TreeNode(6);
    BinaryTreeNode TreeNode;
    TreeNode.inorderR(T);
}
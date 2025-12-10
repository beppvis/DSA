#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;


struct Node{
	int val;
	int type; // o for val
	char letter;
	Node* right;
	Node* left;
	Node(int val,int type,char letter){
		this->type = type;
		this->letter = letter; 
		this->val = val;
		this->right = nullptr;
		this->left = nullptr;
	}
};

map<char,int> getVals(string in) {
	map<char,int> out; 
	for (char c : in){
		if(!out[c]) out[c]=0;
		out[c] ++;
	}
	return out;
}

void inorder(Node* head,string code){
	if (!head) return;
	inorder(head->right,code+"1");
	if (head->type == 0)
		cout << head->letter << " | " << head->val << " | " << code << endl;
	inorder(head->left,code+"0");
}

struct compareNode{
	bool operator()(Node* a, Node*b){
		return a->val > b->val; 
	}
};

int main(){
	string in = "AAAABBBCDDDDDD";
	map<char,int> m = getVals(in);
	priority_queue<Node*,vector<Node*>,compareNode> pq;
	for (pair<char,int> i :m){
		pq.push(new Node(i.second,0,i.first));
	}
	// make tree
	Node*parent = nullptr;
	while(pq.size()>1){
		Node* a = pq.top();
		pq.pop();
		Node* b = pq.top();
		pq.pop();
		parent = new Node((a->val + b->val),1,' ');
		parent->left = a;
		parent->right = b;
		pq.push(parent);
	}
	parent = pq.top();	
	pq.pop();
	Node* next = parent;
	inorder(next,"");
}



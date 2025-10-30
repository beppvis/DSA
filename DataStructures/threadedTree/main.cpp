

#include <cstdio>
struct Node{
    int data;
    Node* rlink;
    Node* llink;
    Node(int data){
        this->data = data;
        this->llink=nullptr;
        this->rlink=nullptr;
    }
};


class Solution{
    public:


    void FlattenTreeHelper(Node* root, Node* prev){
        if (root != nullptr)
            return;
        FlattenTreeHelper(root->llink,prev);
        if (prev != nullptr){
            prev->rlink = root;
        }
        root->llink = nullptr;
        prev = root;
        FlattenTreeHelper(root->rlink,prev);
    }

    Node* FlattenTree(Node* root) {
        Node* new_Head = root;
        while (new_Head->llink!=nullptr){
            new_Head = new_Head->llink;
        }

        Node* prev = nullptr;
        FlattenTreeHelper(root,prev);
        return new_Head;
    }
    void inorderTraversalPrint(Node* root){
        while(root != nullptr){
            printf("-%d-",root->data);
            if(root->rlink!= nullptr){
                printf("There are values in left side.\n");
            }
            if(root->llink!= nullptr){
                printf("There are values in left side.\n");
            }
            root = root->rlink;
        }
    }
};



int main(){
    Solution sol;
    Node* root = new Node(1);
    root->llink = new Node(2);
    root->rlink = new Node(3);
    root->llink->llink = new Node(4);
    root->llink->rlink = new Node(5);
    root->rlink->llink = new Node(6);
    root->rlink->rlink = new Node(7);
    Node* prev = nullptr;
    Node* new_head = sol.FlattenTree(root );
    sol.inorderTraversalPrint(new_head);

}




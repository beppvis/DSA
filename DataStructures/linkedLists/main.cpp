#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>

struct Node{
    int val;
    Node* link;
};


class linkedList{
    public:
    bool addAtPos(Node* T , int val, int pos)
    {

        Node* x = (Node*) malloc(sizeof(Node));
        int i = 0;
        Node *P = T;
        while(i < pos -1)
        {
            P = P->link;
        }
        x->link = P->link;
        P->link = x;
        return true;
    }
    int len(Node* T){
        int len = 0;
        Node* P = T;
        while (P->link != NULL)
        {
            len ++;
            P = P->link;
        };
        return len;
    }
    Node* hop(Node*T,int n){
        for (int i = 0 ; i< n ; i++)
        {
            T = T->link;
        }
        return T;
    }
    Node* findCommonPoint(Node*T1,Node*T2){
        if(T1 == NULL || T2==NULL)
            return NULL;
        int l1 = len(T1);
        int l2 = len(T2);
        int diff  = abs(l1-l2);
        Node* p;
        Node* s;
        if (l1> l2)
        {
            p = this->hop(T1, diff); 
            s = T2; 
        }
        else{
            p = this->hop(T2,  diff);
            s = T1;
        }
        while (p!=s)
        {
        p = p->link;
        s = s->link;
        }
        return p;

    } 
};


#include <cstddef>
#include <stdio.h>

struct Node{
    int key;
    int data;
    Node* rlink;
    Node* llink;
    Node(int key,int data){
        this->key = key;
        this->data = data;
        this->rlink = NULL;
        this->llink = NULL;
    }
};

class Deque{

public:
    int insertAtFront(int key,int data,Node* front,Node* rear) {
        Node* x = new Node(key,data);
        if (front == NULL){
            front = x;
            rear = x;
            return 0;
        }
        x->rlink = front;
        front->llink = x;
        return 0;
    }


};



int  main (){}

#include <cstdio>
#include <cstdlib>

struct Node{
    int data;
    Node* link;
};

class linkedStack{
public :
    bool isEmpty(Node* T){
        if(T == NULL) return true;
        return false;
    }
    bool delAtLast(Node*T){
        if(isEmpty(T)) return false;
        Node* p = T;
        T = T->link;
        free(p);
        return true;
    }
    bool addAtLast(Node*T,int val){
        Node*x = (Node*) malloc(sizeof(Node));
        x->data = val;
        if (T == NULL){ 
            T = x;
            return true;
        }
        x->link = T;
        T = x;
        return true;
    }
};

int main(){
    linkedStack stacker;
    Node* T=NULL;
    stacker.addAtLast(T, 10);
    stacker.addAtLast(T, 11);
    stacker.addAtLast(T, 12);
    stacker.addAtLast(T, 13);
    stacker.addAtLast(T, 14);
    stacker.addAtLast(T, 15);
    if (stacker.isEmpty(T)){
        printf("Is empty");
    }
    else {
        printf("%d \n",T->data);
    }

}

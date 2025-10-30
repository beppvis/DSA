#include <cstdio>
#include <cstdlib>

struct Node{
    int data;
    Node* link;
};


class linkedlist{
public:
bool removeAdjDupe(Node* T){
    if (T == nullptr || T->link == nullptr)
        return false;
    Node * curr = T->link;
    Node * save = T;
    bool trig= false;
    while(curr!= nullptr)
    {
        trig = false;
        if(save->data!= curr->data)
        {
            save->link = curr;
            save = curr;
        }
        else{
            trig = true;
        }
        Node *tmp = curr;
        curr = curr->link;
        if (trig)
        {
            free(tmp);
        }
    }
    save->link = nullptr;
    return true;
}
Node* makeLL(int* arr,int n){
    Node* T = (Node *)malloc(sizeof(Node));
    T->data = arr[0];
    Node* p = T;
    for(int i = 1 ; i < n ; i ++)
    {
        Node* x = (Node *)malloc(sizeof(Node));
        x->data = arr[i];
        p->link = x;
        p = x;
    }
    p->link =nullptr; 
    return T;
}
bool printIt(Node* T)
{
    Node* p = T;
    while (p != nullptr)
    {
        printf("%d->",p->data);
        p = p->link;
    }
    printf("NULL\n");
    return true;
}

};

int main(void){
    linkedlist ll;
    int arr[] = {1,1,1,2,2,3,4,4,4,5};
    int n = 10;
    Node* T = ll.makeLL(arr,n);
    ll.printIt(T);
    ll.removeAdjDupe(T);
    printf("Out : \n");
    ll.printIt(T);

}


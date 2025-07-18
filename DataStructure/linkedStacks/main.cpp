#include <cstdio>
#include <cstdlib>

struct  Node
{
    int data;
    Node* link;
};


class linkedStacks{
public:
Node* insertItem(Node*T,int val)
{
    Node* x = (Node*) malloc(sizeof(Node));
    x->data = val;
    if (T == nullptr) {
        T = x;
        return T;
    };
    x->link = T;
    return T;

}
Node* popItem(Node* T){
    Node* tmp = T;
    T = T->link;
    free(tmp);
    return T;
}
bool isEmpty(Node* T){
    return T == nullptr;
}
};

int main(void)
{
    Node* T = nullptr;
    linkedStacks stacker;
    T = stacker.insertItem(T,10);
    T = stacker.insertItem(T,30);
    T = stacker.insertItem(T,50);
    T = stacker.insertItem(T,40);
    if(stacker.isEmpty(T))
    {
        printf("The stack is empty\n");
    }
    T = stacker.popItem(T);

}

/* there are three cars in a high ways labeled as a b c from left to right. 
All these cars has to passthrough an intermediate tunnel
and leave on the other side. The tunnel is a stack, give the possible combinations.
*/
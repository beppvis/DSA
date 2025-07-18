#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    Node* link;

};

class linkedQueues{
public:
Node* front;
Node* back;
int size;
linkedQueues(){
    front = nullptr;
    back = nullptr;
    size = 0;
}
~linkedQueues(){
    while (front!=nullptr) 
    {
        Node* tmp=front;
        front = front->link;
        free(tmp);
    }
}
bool insertItem(int val){
    Node* x = (Node *) malloc(sizeof(Node));
    if(x == nullptr) {
        printf("Error: cant allocate memory for a new node\n");
        return false;
    }
    x->data = val;
    x->link = nullptr;
    if(front==NULL){
        front = x;
        back = x;
        return true;
    }
    Node* tmp = front; 
    while(tmp->link != NULL)
    {
        tmp = tmp->link;
    }
    tmp->link = x;
    back = x;
    size ++;
    return true;
}
int peek(){
    if (front == nullptr)
    {
        printf("Empty queue\n");
        return 0;
    }
    return front->data;
}
bool popItem(){
    if(back == nullptr) {
        return false;
    }
    Node* tmp = front;
    front= front->link;
    free(tmp);
    size --;
    if (front == nullptr) back = nullptr;
    return true;
}
};

int main(void){
   linkedQueues queuer = linkedQueues(); 
   queuer.insertItem(20);
   queuer.insertItem(30);
   queuer.insertItem(40);
   printf("%d\n",queuer.peek());
   queuer.popItem();
   printf("%d\n",queuer.peek());
}
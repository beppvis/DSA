
#include <cstddef>
#include <cstdio>
#include <cstdlib>

struct Node {
    int coeff;
    int degree;
    Node* link;
};

class linkedPoly{
public:
Node* addTwoPoly(Node* T1, Node* T2){
    Node* S = NULL;
    Node* p3 = NULL;
    Node* p1 = T1;
    Node* p2 = T2;
    while(p1!=NULL||p2!=NULL){
        Node*x =NULL;
        if(p1->degree > p2->degree)
        {
            x = p1;
            p1 = p1->link;
        }
        else if(p2->degree > p1->degree)
        {
            x = p2;
            p2 = p2->link;
        }
        else{
            x= (Node*) malloc(sizeof(Node));
            x->degree = p2->degree;
            x->coeff = p1->coeff + p2->coeff;
            x->link = NULL;
            p1 = p1->link;
            p2 = p2->link;
        }
        if(S == NULL){
            S = x;
            p3 = x;
        }
        else{
            p3->link = x;
            p3 = p3->link;
        }
    }

    while(p1 != NULL)
    {
            p3->link = p1;
            p3 = p3->link;
            p1 = p1->link;
    }

    while(p2 != NULL)
    {
            p3->link = p2;
            p3 = p3->link;
            p2 = p2->link;
    }
    p3->link = NULL;
    return S;
}
bool printIt(Node* T)
{
    Node* p = T;
    while (p != nullptr)
    {
        printf("%dx^%d+",p->coeff,p->degree);
        p = p->link;
    }
    printf("\n");
    return true;
}
Node* makeIt(int*coeff,int*degree,int n){
        Node*T = (Node*)malloc(sizeof(Node));
        T->coeff = coeff[0];
        T->coeff = degree[0];
        T->link = NULL;
        Node*p = T;
        for(int i = 1 ; i < n ; i ++)
        {
           Node* x = (Node*) malloc(sizeof(Node));
            x->coeff=coeff[i];
            x->degree=degree[i];
            p->link = x;
            p = x;
        }
        return T;
}
};

int main(void){
    linkedPoly lp;
    int degrees[]= {1,2,3};
    Node*T1 = lp.makeIt(degrees, degrees, 3);
    Node*T2 = lp.makeIt(degrees, degrees, 3);

    lp.printIt(T1);
    lp.printIt(T2);
    Node*S = lp.addTwoPoly(T1,T2);
    printf("Fin\n");
    lp.printIt(S);



}

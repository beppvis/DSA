
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
    Node* S;
    Node* p3;
    Node* p1 = T1;
    Node* p2 = T2;
    while(p1!=NULL||p2!=NULL){
        Node*x ;
        if(p1->degree>p2->degree)
            x = p1;
        else if(p2->degree>p1->degree)
            x = p2;
        else{
            x= (Node*)malloc(sizeof(Node));
            x->degree = p2->degree;
            x->coeff = p1->coeff + p2->coeff;
            x->link = NULL;
        }
        if(S==NULL){
            S = x;
            p3 = x;
        }
        else{
            p3->link = x;
            p3 = x;
        }
    }
    return S;
}
bool printIt(Node* T)
{
    Node* p = T;
    while (p != NULL)
    {
        printf("%dx^%d+",p->coeff,p->degree);
        p = p->link;
    }
    printf("\n");
    return true;
}
};

int main(void){
    Node*T1 = (Node *)malloc(sizeof(Node));
    Node*T2 = (Node *)malloc(sizeof(Node));
    T1->degree = 2;
    T1->coeff = 2;
    T1->link = NULL;
    T2->degree = 2;
    T2->coeff = 2;
    T2->link = NULL;
    linkedPoly lp;
    lp.printIt(T1);
    lp.printIt(T2);
    Node*S = lp.addTwoPoly(T1,T2);
    printf("Fin\n");
    lp.printIt(S);



}
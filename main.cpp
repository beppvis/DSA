#include <vector>
#include <stdio.h>

using namespace std;

int partition(vector<int>A, int p ,int q){
    int pivot = A[p];
    int slow = p;
    int fast = slow +1;

    while(fast <= q){
        if(pivot > A[fast]){
            int temp = A[slow+1];
            A[slow+1] =  A[fast];
            A[fast]=temp;
            slow ++;
        }
        fast ++;
    }
    int temp = A[slow];
    A[slow] = pivot;
    A[pivot] = temp;
    return slow;
}

vector<int> quickSort(vector<int> A, int s ,int e){
    if (s < e){
        int m = partition(A,s,e);
        quickSort(A,s,m-1);
        quickSort(A,s,m+1);
    }
    return A;
}

int main(){
    vector<int> A = {12,54,2};
    vector<int> out = quickSort(A,0,2);
    for(int i = 0;i < 3; i ++)
    {
        printf("%d\n", out[i]);
    }

}



#include <bits/stdc++.h>
using namespace std;

int partition(int* arr, int start, int end){
    int slow = start;
    int fast = slow + 1;
    int pivot = arr[start];
    while (fast < end)
    {
        if (pivot > arr[fast]){
            int  temp = arr[slow + 1];
            arr[slow+1] = arr[fast];
            arr[fast] = temp;
            slow++;
        }
        fast ++;
    }
    int  temp = arr[start];
    arr[start] = arr[slow];
    arr[slow] = temp;
    return slow;
}

void quickSort(int* A,int s,int e){
    if (s>e)
        return ;
    int mid = partition(A,s,e);
    quickSort(A,s,mid-1);
    quickSort(A,mid+1,e);
}


int main(){
    int a[4]={1,5,3,2};
    int n = 4;
    quickSort(a,0,4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d \n",a[i]);
    }
    
}
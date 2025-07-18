#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

//TODO: add docs comments
class insertionSort{
    public:
    int sort(int*arr,int n){
        if (n == 0) return -1;
        if (n == 1) return 0;
        for (int curr = 1 ; curr < n;curr++){
            int left = curr - 1;
            int key = arr[curr];
            while (left > 0 && key < arr[left]){
                arr[left + 1] = arr[left];
                left-- ;
            }
            arr[left+1] = key;
        }
        return 0;
    }

};

int main(){
    insertionSort sorter;
    int arr[] = {1,5,4,6,10,45,23};
    int n = 7;
    sorter.sort(arr, n);
    for(int i = 0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}


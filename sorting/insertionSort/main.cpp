#include <bits/stdc++.h>
#include <vector>


class insertionSort{
    public :
    int insertion(int* arr,int n){
        for (int curr = 1 ; curr < n; curr++)
        {
            int left = curr - 1;
            int key = arr[curr];
            printf("key : %d\n",key);
            while (left >= 0 && arr[left] > key)
            {
                arr[left+1] = arr[left];
                left--;
            }
            arr[left+1] = key;
        }
        return 0;
    }
};



int main(void){
    int arr[] = {4,2,5,1};
    int n = 4;
    insertionSort sorter = insertionSort();
    sorter.insertion(arr,n);
    for (int i = 0 ; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }

}
#include <cstdio>
class mergeSort{
public:
    int merge(int* arr, int left,int mid,int right){
        int l1 = (mid-left)+1;
        int l2 = (right-mid);
        int leftArray[l1];
        int rightArray[l2];

        for(int i = 0 ; i< l1;i++)
        {
            leftArray[i] = arr[left+i];
        }

        for(int i = 0 ; i< l2;i++)
        {
            rightArray[i] = arr[mid+i+1];
        }

        int i(0),j(0),k(left);
        while(i < l1&&j <l2){
            if(leftArray[i]<= rightArray[j])
            {
                arr[k] = leftArray[i];
                i++;
            }
            else
            {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while(i < l1){
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while(j < l2){
            arr[k] = rightArray[j];
            k++;
            j++;
        }

        return 0;

    }
    int sort(int* arr, int left,int right){
        if(left >= right)
            return 0;
        int mid = left+(right-left)/2;
        sort(arr,left,mid);
        sort(arr,mid+1,right);
        merge(arr, left, mid, right);
        return 0;
    }
};

int main(){
    mergeSort sorter;
    int arr[] ={4,2,3,1,2};
    sorter.sort(arr, 0,4);
    for(int i = 0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }



}

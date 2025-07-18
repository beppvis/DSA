


#include <cstdio>
class quickSort{
public:
    // returns mid
    int partition(int *arr,int p, int q){
        int pivot = arr[p];
        int slow = p;
        int fast = slow + 1;
        while (fast <= q){
            if (pivot > arr[fast]){
                int tmp = arr[slow+1];
                arr[slow+1] = arr[fast];
                arr[fast] = tmp;
                slow ++;
            }
            fast ++;
        }
        int tmp = arr[slow];
        arr[slow] = pivot;
        arr[p] = tmp;
        return slow;
    }


    bool sort(int *arr,int s, int e){
        if (s >= e) return false;
        int m = partition(arr, s, e);
        sort(arr, s, m-1);
        sort(arr, m+1, e);
        return true;
    }
};


int main(void){
    int arr[] = {4,3,1,5,2};
    quickSort sorter;
    sorter.sort(arr, 0, 5);
    for (int i = 0 ; i <  5 ; i++)
        printf("%d\n",arr[i]);
}

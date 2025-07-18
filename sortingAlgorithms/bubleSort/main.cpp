


#include <cstdio>
class bubbleSort{
public:
    int sort(int*arr,int n){

        for(int i = 0 ; i < n -1;i++){
            bool swapped = false;
            for(int j = 0 ; j < n - i - 1;j++){
                if(arr[j]>arr[j+1]){
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    swapped = true;
                }
            }
            if(!swapped)
            {
                break;
            }
        }
        return 0;
    }
};



int main(){
    int arr[] = {1,3,5,4,2};
    bubbleSort sorter;
    sorter.sort(arr,  5);
    for(int elem : arr)
    {
        printf("%d\n",elem);
    }
}

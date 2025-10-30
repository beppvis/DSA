
#include <cstdio>
class selectionSort {

public:
  bool sort(int *arr, int n) {
    if (n <= 1)
      return false;
    for (int i = 0; i < n; i++) {
      int min_idx = i;
      for (int j = i; j < n; j++) {
        if (arr[j] < arr[min_idx]) {
          min_idx = j;
        }
      }
      int tmp = arr[min_idx];
      printf("Min %d\n",arr[min_idx]);
      printf("Max %d\n",arr[i]);
      arr[min_idx] = arr[i];
      arr[i] = tmp;
    }
    return 0;
  }
};

int main(void) {
    int arr[5] = {3,2,5,1,4};
    selectionSort sorter;
    sorter.sort(arr, 5);
    for(int elem:arr)
    {
        printf("%d\n",elem);
    }
}

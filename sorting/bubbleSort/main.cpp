#include <stdio.h>

class bubbleSort{
    public:
        int sort(int* arr ,int n ){
            for (int i = 0 ; i < n ; i++)
            {
                int key = arr[i];
                for (int j = i ; j < n ; j++)
                {
                    while (arr[j]<key){
                        arr[j-1] = key;
                    }
                }

            }

        }

}
#include <cstdio>
#include <cstdlib>
#include <string>
class Sorter{
public:
    std::string sorter(std::string arr,int n){
        char* oarr =(char *)malloc(sizeof(char)*n);
        for (int i = 0 ; i < n ; i++){
            oarr[i] = arr[i];
        }
        int j = 0;
        int k = n - 1;
        for (int i = 0 ; i < n ; i++){
            if (arr[i] == 'Y'){
                oarr[k] = arr[i];
                k--; 
            }
            if (arr[i]=='C'){
                oarr[j] = arr[i];
                j++;
            }
        }
        // in the psuedo code wrong point were mentioned it was j instead of i
        for(int l = j ; l <= k ; l++)
        {
            oarr[l] ='O';
        }
        return oarr;
    }
};

int main(){
    Sorter sorter;
    std::string arr;
    int n = 0;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) {
        char l ;
        scanf(" %c",&l);
        arr = arr + l;
    }
    std::string out = sorter.sorter(arr,  n);
    for (int i = 0 ; i < n ; i++) {
        printf("%c ",out[i]);
    }
    printf("\n");
}

#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    void getNum(int N){
        // find 2 five digit numbers such that abcde/fghij = N and both should have all digits present inside them
        for (int fghij=  01234 ; fghij <= 98765/N; fghij ++){
            int abcde = fghij * N;
            int tmp ,used = (fghij < 10000) ;
            // bit haxx
            tmp  = abcde ; while (tmp) {used |= 1 << (tmp % 10) ; tmp /= 10;}
            tmp  = fghij ; while (tmp) {used |= 1 << (tmp % 10) ; tmp /= 10;}
            if (used == (1 << 10) - 1){
                cout << abcde << " " << fghij << endl;
            }
       }
    }


};


int main(){
    Solution sol;
    sol.getNum(2);
}

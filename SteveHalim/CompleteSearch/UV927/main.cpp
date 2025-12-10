#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Solution{

    public:
    int getN(int d,int k){
        int  n = 0;
        int i = 0;
        while (true){
            n+=1;
            i+= n*d;
            if (k <= i){
                return n;
            }
        }
    }


};


int main(){
    Solution sol;
    int tCase;
    scanf("%d",&tCase);
    while (tCase -- ){
        string s;
        int a[21];
        memset(a,0, 20);
        int i = 0 ;
        cin >> s;
        // stupoid
        printf("%s",s.c_str());
        while (s.length() > 0){
            printf("%s",s.c_str());
            a[i++]= stoi(s.substr(0,s.find(" ")));
            s = s.substr(s.find(" "));
        }
        int d,k;
        scanf("%d",&d);
        scanf("%d",&k);
        int n = sol.getN(d, k);
        long long sum;
        for (int ind = 0 ; ind < i ; ind++){
            sum += a[ind]*pow(n,ind);
        }
        printf("%lld\n",sum);
    }

}

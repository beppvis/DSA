#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;


int price[25][25];
int memo[210][25]; // this is an safety buffer
int C,M;

int DP(int money, int g){ // asks if with the given money can I make the rest possible

    if (money < 0) return -INT_MAX;
    if(g==C) return M-money;
    
    if (memo[money][g] != -1) return memo[money][g]; // if i have calcluated it return it
    int model = price[g][0];
    int &ans = memo[money][g]; 
    while(model--){
        ans = max(ans,DP(money-price[money][g],g+1));// is it possible to achive it using the next  
    }
    return memo[money][g]=ans;
}

// bottom apporach

bool reachable[210][25];
int shop(){
    for (int g = 0; g < price[0][0] ; g++){
        if (M-price[0][g] >= 0){
            reachable[0][M-price[0][g]] = true;
        }
    }

    for (int g = 0 ; g < C; g++ ){
        for(int money = 0 ; money < M ; money++)if(reachable[g-1][money]){
            for (int k = 1 ; k < price[g][0];k++)if(money-price[g][k] >= 0 ){
                reachable[g][money-price]
            }
        }
    }



}

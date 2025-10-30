#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;


class DisjointSet{
    public:
    vector<int> link;
    vector<int> size;
    DisjointSet(int n){
        for (int i = 0 ; i < n ; i++){
            link.push_back(i);
        }
        this->size = vector<int>(n,1);
    }
    
    int find(int x){
        while (x!=link[x]) x = link[x];
        return x;
    }

    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if (size[x] < size[y]) swap(x,y);
        size[x] += size[y];
        link[y] = x;
    }

    bool same(int x, int y){
        return  find(x) == find(y);
    }

};

class Solution{
    public:
    vector<tuple<int,int,int>> getMinSpanningTreeKruskals(vector<tuple<int,int,int>> E,int n){
        sort(E.begin(),E.end(),[](auto a, auto b){
            return get<2>(a) < get<2>(b);
        });

        vector<tuple<int,int,int>> newG;
        DisjointSet* djs = new DisjointSet(n);

        for (tuple<int,int,int> t : E){
            int x = get<0>(t);
            int y = get<1>(t);
            if (!djs->same(x, y)){
                djs->unite(x,y);
                newG.push_back(t);
            }
        }
        return newG;
    }
    void printG(vector<tuple<int,int,int>>G ){
        for (tuple<int,int,int> t : G){
            printf("%d-%d=%d\n",get<0>(t),get<1>(t),get<2>(t));
        }
    }

};


int main(){
    Solution* sol = new Solution();
    sol->printG(sol->getMinSpanningTreeKruskals({{1,2,3},{1,5,5},{5,6,2},{5,2,6},{2,3,5},{3,6,3},{3,4,9},{6,4,7}}, 7));
}





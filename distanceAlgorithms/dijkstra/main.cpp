#include <climits>
#include <cstdio>
#include <functional>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> pi;




class Solution{
    public:
    vector<int> dijkstra(int n,vector<tuple<int,int,int>>edges){
        vector<vector<pi>>  adjList(n);
        vector<bool> visited(n,false);
        for (auto edge:edges){
            int a,b,w;
            tie(a,b,w)= edge;
            adjList[a].push_back(make_pair(b,w));
        }

        priority_queue<pi,vector<pi>,std::greater<pi>> q;
        vector<int> distance(n,INT_MAX);
        vector<int> parent(n,-1);
        //iota(bestVertex.begin(), bestVertex.end(), 0);

        distance[0] = 0;
        q.push(make_pair(0,0));
        while (!q.empty()){
            int d = q.top().first;
            int u = q.top().second;
            q.pop();
            if (d > distance[u])
                continue;
            for (pi edge: adjList[u]){
                int v = edge.first;
                int weight = edge.second;
                if (weight+distance[u] < distance[v]){
                    distance[v] = weight + distance[u];
                    q.push(make_pair(distance[v],v));
                    parent[v] = u;
                }
            }
        }
        return parent;

    }

};

int main(){
    Solution sol;
    vector<int> parent = sol.dijkstra(4,{{0,1,1},{1,2,1},{2,3,1},{0,3,5}});
    int u = 0 ;
    for ( int v: parent) {
        printf("%d - > %d \n",v,u);
        u++;
    }



}

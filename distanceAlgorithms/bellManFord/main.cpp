#include <climits>
#include <tuple>
#include <vector>
#include <cstdio>
using namespace std;

class solution{
public:
    vector<int> bellman(int n,vector<tuple<int,int,int>>& edges, int source){
        vector<int> distances(n,INT_MAX);
        distances[source] = 0;
        // O(n*m)
        for (int i = 0; i < n-1; i++){
            for (auto e: edges){
                int a,b,w;
                tie(a,b,w) = e;
                distances[b] = min(distances[b],distances[a]+w);
            }
        }
        return distances;
    }
};


int main(){
    solution sol;
    vector<tuple<int,int,int>> edges_Weighted= {
        {0,1,1},
        {0,4,2},
        {1,2,5},
        {1,3,6},
        {1,4,3},
        {4,7,2},
        {4,6,1},
        {4,5,2},
    };
    vector<int> distances = sol.bellman(8, edges_Weighted, 0);

    int vertex = 0;
    for (auto distance : distances){
        printf("V: %d Dist:%d\n",vertex,distance);
        vertex++;
    }

}

#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

class Solution{
    public:
    void bfs(int n, vector<vector<int>>&edges,int source) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n,false);
        for (vector<int>edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q; 
        q.push(source);
        visited[source] = true;

        while (!q.empty()){
            int curr = q.front();
            q.pop();
            printf("Curr : %d\n",curr);
            for (int node : adjList[curr]){
                if ( visited[node])continue;
                visited[node] = true;
                q.push(node);
            }
        }
    }
};


int main(){
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{1,4},{4,7},{4,6},{4,5}};
    sol.bfs(8, edges, 0);
}

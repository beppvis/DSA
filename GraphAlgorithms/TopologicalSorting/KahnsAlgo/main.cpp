#include <cstddef>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

class Solution{


    vector<int> getDAGusingKahn(vector<vector<int>>& edges){
        int n = edges.size();
        vector<int> indegree(n,0);
        vector<int> order;
        int index = 0;
        for (int node:edges[index]){
            indegree[node] += 1;
            index ++;
        }

        queue<int> q;
        // now I need to cycle through them

        for (int i = 0 ; i < n ;i++){
            if (indegree[i]==0) q.push(i);
        }

        while (!q.empty()){
            int curr = q.front();
            order.push_back(curr);
            q.pop();
            for (int node : edges[curr]){
                indegree[node] --;
                if (indegree[node] == 0 )q.push(node);
            }

        }
        if (order.size()!=n)
            return {}; 
        return order;


    }

};


int main(){
    Solution sol;
}

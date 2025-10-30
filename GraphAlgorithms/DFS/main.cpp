#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  void DFSRec(int n, vector<vector<int>> &adj, int source,
              vector<bool> visited) {
    if (visited[source])
      return;
    visited[source] = true;
    for (int node : adj[source]) {
      DFSRec(n, adj, source, visited);
    }
  }
  void DFSIter(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<vector<int>> adj;
    vector<bool> visited;
    if (n == 0)
      return;
    for (int i = 0; i < n; i++) { // O(N*E)
      visited.push_back(false);
      adj.push_back({});
    }
    for (vector<int> edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    stack<int> st;
    st.push(source);
    while (!st.empty()) {
      int curr = st.top();
      st.pop();
      visited[curr] = true;
      printf("Curr : %d\n", curr);
      for (int edge : adj[curr]) {
        if (!visited[edge]) {
          st.push(edge);
        }
      }
    }
    return;
  }
};

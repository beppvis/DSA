#include <queue>
#include <tuple>
#include <vector>
#include <cstdio>
#include <iostream> // Added for printing
#include <utility>  // Added for std::pair
#include <map>

using namespace std;

class MinHeap{
public:
    vector<tuple<int,int,int>> arr;

    /**
     * @brief Inserts an edge, sifting up to maintain heap property.
     */
    void insert(tuple<int,int,int> edge){
        arr.push_back(edge);
        int currIndx = arr.size()-1;

        // --- CORRECTED SIFT-UP LOGIC ---
        // Keep swapping with parent as long as we are smaller
        while (currIndx > 0){
            int parentIndex = (currIndx-1)/2;
            if (get<2>(arr[currIndx]) < get<2>(arr[parentIndex])){
                swap(arr[currIndx],arr[parentIndex]);
                currIndx = parentIndex; // Move up to the parent's index
            } else {
                break; // We are in the correct position
            }
        }
    }

    /**
     * @brief Sifts an element down. (Your implementation was correct)
     */
    void heapify(int index){
        int minIndx = index;
        int leftChild = (index*2)+1;
        int rightChild = (index*2)+2;

        if (leftChild < arr.size() && get<2>(arr[leftChild]) < get<2>(arr[minIndx])){
            minIndx = leftChild;
        }

        if (rightChild < arr.size() && get<2>(arr[rightChild]) < get<2>(arr[minIndx])){
            minIndx = rightChild;
        }

        if (minIndx != index){
            swap(arr[minIndx],arr[index]);
            heapify(minIndx); // Correctly recursing on the new index
        }
    }

    /**
     * @brief Not used by Prim's, but was part of your class.
     */
    void deleteInd(int index){
        swap(arr[index],arr[arr.size()-1]);
        arr.pop_back();
        heapify(index);
    }
    
    // --- FUNCTIONS NEEDED FOR PRIM'S ---

    /**
     * @brief Returns and removes the minimum edge from the heap.
     */
    tuple<int,int,int> extractMin() {
        if (arr.empty()) {
            return make_tuple(-1, -1, -1); // Should not happen if checked
        }
        // Get the root
        tuple<int,int,int> minEdge = arr[0];
        // Move last element to root
        arr[0] = arr.back();
        arr.pop_back();

        // Sift-down the new root, if heap is not empty
        if (!arr.empty()) {
            heapify(0);
        }
        return minEdge;
    }

    /**
     * @brief Checks if the heap is empty.
     */
    bool isEmpty() {
        return arr.empty();
    }
};

class Solution{
public:
    /**
     * @brief Implements Prim's algorithm to find the Minimum Spanning Tree (MST).
     * @param E The edge list of the graph.
     * @param n The number of vertices (assuming 0 to n-1).
     * @return A vector of tuples representing the edges in the MST.
     */
    vector<tuple<int,int,int>> primsMST(const vector<tuple<int,int,int>>& E, int n){
        MinHeap minHeap;
        priority_queue<tuple<int,int>, >
        
        // Adjacency list: adjList[u] = vector of {v, w}
        vector<vector<pair<int, int>>> adjList(n);
        
        for (const auto& edge : E) {
            int u,v,w;
            tie(u,v,w) = edge;
            // --- FIX: Add edge in both directions for undirected graph ---
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        
        vector<bool> visited(n, false);
        vector<tuple<int,int,int>> MST;

        // --- Start from vertex 0 ---
        int startVertex = 0;
        visited[startVertex] = true; // Mark the start vertex as visited

        // Add all edges from the start vertex to the heap
        for (const auto& edge : adjList[startVertex]){
            int v = edge.first; // Neighbor
            int w = edge.second; // Weight
            minHeap.insert(make_tuple(startVertex, v, w));
        }

        // --- Main Prim's Algorithm Loop ---
        while (!minHeap.isEmpty() && MST.size() < n - 1){
            // 1. Get the cheapest edge to a new vertex
            tuple<int,int,int> minEdge = minHeap.extractMin();
            int u, v, w;
            tie(u, v, w) = minEdge;
            
            // 2. Check if the destination vertex 'v' is already visited
            if (visited[v]) {
                continue; // This edge would form a cycle, ignore it
            }
            
            // 3. Accept the edge: 'v' is a new vertex
            visited[v] = true;
            MST.push_back(minEdge);
            
            // 4. Add all edges from this *new* vertex 'v' to the heap
            for (const auto& edge : adjList[v]) {
                int neighbor = edge.first;
                int weight = edge.second;
                
                // Only add edges to vertices we haven't visited yet
                if (!visited[neighbor]) {
                    minHeap.insert(make_tuple(v, neighbor, weight));
                }
            }
        }
        
        return MST;
    }
};


int main(){
    Solution sol;
    
    // 9 vertices (0-8)
    int n = 9;
    
    // (u, v, weight)
    vector<tuple<int,int,int>> allEdges;
    allEdges.push_back(make_tuple(0, 1, 4));
    allEdges.push_back(make_tuple(0, 7, 8));
    allEdges.push_back(make_tuple(1, 2, 8));
    allEdges.push_back(make_tuple(1, 7, 11));
    allEdges.push_back(make_tuple(2, 3, 7));
    allEdges.push_back(make_tuple(2, 8, 2));
    allEdges.push_back(make_tuple(2, 5, 4));
    allEdges.push_back(make_tuple(3, 4, 9));
    allEdges.push_back(make_tuple(3, 5, 14));
    allEdges.push_back(make_tuple(4, 5, 10));
    allEdges.push_back(make_tuple(5, 6, 2));
    allEdges.push_back(make_tuple(6, 7, 1));
    allEdges.push_back(make_tuple(6, 8, 6));
    allEdges.push_back(make_tuple(7, 8, 7));

    vector<tuple<int,int,int>> mst = sol.primsMST(allEdges, n);
    
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int totalWeight = 0;
    for (const auto& edge : mst) {
        cout << "(" << get<0>(edge) << " - " << get<1>(edge) << ") \tWeight: " << get<2>(edge) << endl;
        totalWeight += get<2>(edge);
    }
    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}

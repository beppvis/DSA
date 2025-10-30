#include <bits/stdc++.h>
#include <cstdio>
#include <utility>
using namespace std;

class Heap {
    public:
    vector<int> v;
    void insert(int value){
        v.push_back(value);
        int cur_index = v.size()-1;
        while (cur_index!= 0) {
            int parentIndex = (cur_index-1)/2;
            if (v[parentIndex]>v[cur_index]) swap(v[parentIndex],v[cur_index]);
            cur_index = parentIndex;
        }
    }

    void heapify(int index){
        int leftChild = (index*2) + 1;
        int rightChild = (index*2) + 2;
        int minIndex = index;

        if (leftChild<v.size() && v[leftChild]<v[minIndex]){
            //swap(v[leftChild],v[minIndex]);
            minIndex = leftChild;
        }

        if (rightChild<v.size() && v[rightChild]<v[minIndex]){
            //swap(v[rightChild],v[minIndex]);
            minIndex = rightChild;
        }
        if (minIndex!=index){
            swap(v[index],v[minIndex]);
            heapify(minIndex);
        }

    }

    void deleteIndex(int index){
        printf("Deleting %d \n",v[index]);
        swap(v[index],v[v.size()-1]);
        v.pop_back();
        heapify(index);
    }

};

int main() {
    Heap* h1 = new Heap();
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        h1->insert(value);
    }
    for(auto i: h1->v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


#include <vector>
#include <cstdio>
using namespace std;



void swap(int* a,int*b){
	int c = *a;
	*a =*b ;
	*b = c;
}

class MinHeap{
	private:
		vector<int> harr;
		void heapify(int index){
			int leftIndex = 2*index + 1;
			int rightIndex = 2*index + 2;
			int smallestIndex = index;
			if (harr[index]> harr[leftIndex])
				smallestIndex = leftIndex;
			if (harr[index]> harr[rightIndex])
				smallestIndex = rightIndex;
			if (smallestIndex != index){
				swap(&harr[index],&harr[smallestIndex]);
				heapify(smallestIndex);
			}

		}
	public:
		void insert(int x){
			harr.push_back(x);
			int currentIndex = harr.size() - 1;
			while (currentIndex != 0 ){
				int parentIndex = (currentIndex-1)/2;
				if (harr[currentIndex]<harr[parentIndex])
					swap(&harr[currentIndex],&harr[parentIndex]);
				currentIndex = parentIndex;
			}
		}
		// 0 1 2
		// [1,2,3]
		void deleteIndex(int index){
			if (index > harr.size()) return;
			if (harr.empty()) return;
			swap(&harr[index],&harr[harr.size()-1]);
			harr.pop_back();
			heapify(index);
		}
		void printIt(){
			for (int x : harr){
				printf("%d,",x);
			}
			printf("\n");
		}
};

int main(){
	MinHeap heap;
	heap.insert(1);
	heap.insert(8);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.printIt();
	heap.deleteIndex(0);
	heap.printIt();

}


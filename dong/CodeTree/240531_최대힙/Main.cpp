#include <iostream>
#include <vector>
using namespace std;

vector<int> maxHeap;

void Heapify(int size, int curIdx)
{
	int largest = curIdx;
	int left = curIdx * 2 + 1;
	int right = curIdx * 2 + 2;

	if (left < size && maxHeap[left] > maxHeap[largest]) {
		largest = left;
	}

	if (right < size && maxHeap[right] > maxHeap[largest]) {
		largest = right;
	}

	if (largest != curIdx) {
		swap(maxHeap[curIdx], maxHeap[largest]);
		Heapify(size, largest);
	}
}

void Insert(int value)
{
	maxHeap.push_back(value);

	int curIdx = maxHeap.size() - 1;
	while (curIdx > 0 && maxHeap[(curIdx - 1) / 2] < maxHeap[curIdx]) {
		swap(maxHeap[curIdx], maxHeap[(curIdx - 1) / 2]);
		curIdx = (curIdx - 1) / 2;
	}
}

void Remove()
{
	if (maxHeap.size() == 0) {
		cout << "heap is empty" << endl;
		return;
	}

	maxHeap[0] = maxHeap.back();
	maxHeap.pop_back();
	Heapify(maxHeap.size(), 0);

}

void BuildHeap(int size)
{
	for (int i = size / 2 - 1; i >= 0; --i) {
		Heapify(size, i);
	}
}

int main()
{

}
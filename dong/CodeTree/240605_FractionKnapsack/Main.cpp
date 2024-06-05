#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
using namespace std;

struct Item
{
	int weight;
	int value;
};

int N, W;
vector<Item> items;

bool CompareItem(Item a, Item b)
{
	double ratio1 = (double)a.value / a.weight;
	double ratio2 = (double)b.value / b.weight;
	return ratio1 > ratio2;
}

void Init()
{
	cin >> N >> W;
	items.resize(N);
	for (size_t i = 0; i < N; ++i) {
		cin >> items[i].weight >> items[i].value;
	}
}

double FractionalKnapsack()
{
	int curWeight = 0;
	double curValue = 0;

	sort(items.begin(), items.end(), CompareItem);

	for (Item& item : items) {
		if (curWeight + item.weight <= W) {		// ��� ������ ���� �� �ִ� ���
			curWeight += item.weight;
			curValue += item.value;
		}
		else {									// �Ϻ� �������� ���� �� �ִ� ��� - �ɰ��� ��
			int remain = W - curWeight;
			curValue += item.value * ((double)remain / item.weight);
			break;
		}
	}

	return curValue;
}

int main()
{
	Init();
	cout << FractionalKnapsack();
}
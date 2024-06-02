#include <iostream>
#include <algorithm>
using namespace std;

const int JEWEL_NUM = 1000;
const int KNAPSACK_CAPACITY = 1000;

// �� ������ ���Կ� ��ġ
int weight[JEWEL_NUM + 1];
int value[JEWEL_NUM + 1];

int dp[JEWEL_NUM + 1][KNAPSACK_CAPACITY + 1];

int jewelNum, knapsackCapacity;

void Init()
{
	// ������ ���� �賶 �ִ� �뷮�� �Է¹޴´�.
	cin >> jewelNum >> knapsackCapacity;

	// �� ������ ���Կ� ��ġ�� �Է¹޴´�.
	for (int i = 1; i <= jewelNum; ++i) {
		cin >> weight[i] >> value[i];
	}
}

int Knapsack()
{
	for (int i = 1; i <= jewelNum; ++i) {
		for (int w = 0; w <= knapsackCapacity; ++w) {
			if (weight[i] <= w) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	return dp[jewelNum][knapsackCapacity];
}

int main()
{
	Init();

	if (jewelNum > JEWEL_NUM || knapsackCapacity > KNAPSACK_CAPACITY) {
		cerr << "Error: �Էµ� ���� �� �Ǵ� �賶 �뷮�� �ִ� ũ�⸦ �ʰ��ߴ�." << endl;
		return 1;
	}

	int maxValue = Knapsack();
	cout << maxValue;
}
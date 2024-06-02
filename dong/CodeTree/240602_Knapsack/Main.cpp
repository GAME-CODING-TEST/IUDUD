#include <iostream>
#include <algorithm>
using namespace std;

const int JEWEL_NUM = 1000;
const int KNAPSACK_CAPACITY = 1000;

// 각 보석의 무게와 가치
int weight[JEWEL_NUM + 1];
int value[JEWEL_NUM + 1];

int dp[JEWEL_NUM + 1][KNAPSACK_CAPACITY + 1];

int jewelNum, knapsackCapacity;

void Init()
{
	// 보석의 수와 배낭 최대 용량을 입력받는다.
	cin >> jewelNum >> knapsackCapacity;

	// 각 보석의 무게와 가치를 입력받는다.
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
		cerr << "Error: 입력된 보석 수 또는 배낭 용량이 최대 크기를 초과했다." << endl;
		return 1;
	}

	int maxValue = Knapsack();
	cout << maxValue;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
using namespace std;

struct Jewel {
	size_t weight;
	size_t value;
};

size_t N, W;	// 보석의 수와 배낭의 최대 용량
vector<Jewel> jewels;

bool CompareJewel(Jewel a, Jewel b)
{
	double ratio1 = (double)a.value / a.weight;
	double ratio2 = (double)b.value / b.weight;
	return ratio1 > ratio2;		// descending sort
}

void Init()
{
	cin >> N >> W;
	jewels.resize(N);

	for (size_t i = 0; i < N; ++i) {
		cin >> jewels[i].weight >> jewels[i].value;
	}
}

double FractionalKnapsack()
{
	sort(jewels.begin(), jewels.end(), CompareJewel);

	size_t curWeight = 0;
	double value = 0;
	for (Jewel& jewel : jewels) {
		if (curWeight + jewel.weight <= W) {		// 보석을 온전히 담는 경우
			curWeight += jewel.weight;
			value += jewel.value;
		}
		else {										// 마지막 보석이 온전히 담기지 않는 경우
			size_t remain = W - curWeight;
			value += jewel.value * ((double)remain / jewel.weight);
			break;
		}
	}

	return value;
}

int main()
{
	Init();
	cout << FractionalKnapsack();
}
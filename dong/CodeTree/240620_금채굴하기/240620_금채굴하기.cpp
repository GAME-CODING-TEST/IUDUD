#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;

int mineArea[MAX_N][MAX_N];

int GetCost(int K)
{
	return K * K + (K + 1) * (K + 1);
}

// ���� ��ǥ���� k�� ������Ű�鼭 ��� gold�� �������������� Ž���Ѵ�.
int GetNumOfGold(int y, int x, int N, int M)
{
	int maxGold = 0;
	for (int k = 0; k <= N; ++k) {
		int goldCnt = 0;

		// ������ ������� Ž��
		for (int i = -k; i <= k; ++i) {
			for (int j = -(k - abs(i)); j <= (k - abs(i)); ++j) {
				int newY = y + i;
				int newX = x + j;
				if (newY >= 0 && newY < N && newX >= 0 && newX < N) {
					goldCnt += mineArea[newY][newX];
				}
			}
		}

		// ���� �� ���� ���
		if (goldCnt * M >= GetCost(k)) {
			maxGold = max(maxGold, goldCnt);
		}
	}

	return maxGold;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> mineArea[y][x];
		}
	}

	// ���� ���� ä���� �� �ִ� ���� ���� ���� ������ ����
	int numOfGold = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			numOfGold = max(numOfGold, GetNumOfGold(y, x, N, M));
		}
	}
	
	cout << numOfGold;
}
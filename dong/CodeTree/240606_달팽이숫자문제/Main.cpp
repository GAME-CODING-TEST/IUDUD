#include <iostream>
#include <stddef.h>
using namespace std;

const int MAX_NUM = 100;
const int DIR_NUM = 4;

size_t N, M;
int arr[MAX_NUM][MAX_NUM];

int dx[DIR_NUM] = { 0, 1,  0, -1 };
int dy[DIR_NUM] = { 1, 0, -1,  0 };

size_t curX, curY;			// ���� (0, 0)
size_t dir;				// 0: ������, 1: �Ʒ���, 2: ����, 3: ����

void Init()
{
	cin >> N >> M;
}

bool InRanged(size_t x, size_t y)
{
	// x�� y�� size_t�� ���ؼ� �׻� �����.
	return x < N && y < M;
}

void SetArray()
{
	arr[curX][curY] = 1;	// ���� ��ġ

	for (size_t i = 2; i <= N * M; ++i) {
		size_t nextX = curX + dx[dir];
		size_t nextY = curY + dy[dir];

		if (!InRanged(nextX, nextY) || arr[nextX][nextY] != 0) {
			dir = (dir + 1) % 4;
		}

		curX = curX + dx[dir];
		curY = curY + dy[dir];
		arr[curX][curY] = static_cast<int>(i);
	}
}

void PrintArray()
{
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Init();
	SetArray();
	PrintArray();
}
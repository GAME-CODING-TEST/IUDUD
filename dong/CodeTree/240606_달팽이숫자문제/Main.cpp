#include <iostream>
#include <stddef.h>
using namespace std;

const int MAX_NUM = 100;
const int DIR_NUM = 4;

size_t N, M;
int arr[MAX_NUM][MAX_NUM];

int dx[DIR_NUM] = { 0, 1,  0, -1 };
int dy[DIR_NUM] = { 1, 0, -1,  0 };

size_t curX, curY;			// 시작 (0, 0)
size_t dir;				// 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽

void Init()
{
	cin >> N >> M;
}

bool InRanged(size_t x, size_t y)
{
	// x와 y는 size_t에 의해서 항상 양수다.
	return x < N && y < M;
}

void SetArray()
{
	arr[curX][curY] = 1;	// 시작 위치

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
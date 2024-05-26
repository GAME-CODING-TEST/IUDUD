#include <iostream>
using namespace std;

const int MAX_N = 50;
int N;
int memo[MAX_N];

void Init()
{
	cin >> N;
	for (int i = 0; i < MAX_N; ++i) {
		memo[i] = -1;
	}

	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 1;
}

int Padovan(int num)
{
	if (memo[num] != -1) {
		return memo[num];
	}

	memo[num] = Padovan(num - 2) + Padovan(num - 3);
	return memo[num];
}

int main()
{
	Init();
	cout << Padovan(N);
}
#include <iostream>
using namespace std;

const int MAX_N = 10;
int arr[MAX_N];
int N;

void Init()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
}

int GCD(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	return (a * b) / GCD(a, b);
}

void Solution(int size)
{
	int answer = 1;

	for (int i = 0; i < size; ++i) {
		answer = LCM(answer, arr[i]);
	}

	cout << answer;
}

int main()
{
	Init();
	Solution(N);
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}

	// 서로 곱했을 때의 최솟값이 되려면, 가장 큰 값과 가장 작은 값이어야 한다.
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i] * B[i];
	}

	cout << sum;
}
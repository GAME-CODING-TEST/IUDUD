#include <string>
#include <vector>

using namespace std;

int solution1(int n) {
	int answer = 0;

	while (n > 0) {
		answer += n % 2 == 0 ? n * n : n;
		n -= 2;
	}

	return answer;
}

// 수열의 합
int solution2(int n) {
	int bit = (n + 1) >> 1;
	return (n & 1) ? bit * bit : (2 * bit * (bit + 1) * (2 * bit + 1) / 3);
}

int solution3(int n) {
	int answer = 0;

	if (n % 2) {
		for (int i = 1; i <= n; i += 2) {
			answer += i;
		}
	}
	else {
		for (int i = 2; i <= n; i += 2) {
			answer += i * i;
		}
	}

	return answer;
}

int main() {}
#include <iostream>

using namespace std;
long long answer[50] = { 0,1, };

int fibo(int n) {
	if (n == 0 || n == 1) {
		return answer[n];
	}
	else if (answer[n] == 0) {
		answer[n] = fibo(n - 1) + fibo(n - 2);
	}

	return answer[n];
}

int main() {
	int t;
	cin >> t;
	int tmp;

	for (int i = 0; i < t; i++) {
		cin >> tmp;
		if (tmp == 0)
			cout << "1 0" << endl;
		else
			cout << fibo(tmp - 1) << " " << fibo(tmp) << endl;
	}

	return 0;
}
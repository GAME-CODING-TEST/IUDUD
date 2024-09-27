// 1816 - ╬охёе╟

#include <iostream>

using namespace std;

int main() {
	
	int N;

	cin >> N;

	for (int t = 0; t < N; ++t) {
		
		long long num;
		cin >> num;

		bool check = true;

		for (int i = 2; i < 1000001; ++i) {

			if (num % i == 0) {
				cout << "NO" << endl;
				check = false;
				break;
			}

		}

		if (check)
			cout << "YES" << endl;
	}

	return 0;
}
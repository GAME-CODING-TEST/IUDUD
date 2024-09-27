#include <iostream>

using namespace std;

int main() {

	int candy;
	int result = 0;

	cin >> candy;

	for (int i = 0; i <= candy; ++i) {
		for (int j = 0; j <= candy; ++j) {
			for (int k = 0; k <= candy; ++k) {
				if (i + j + k == candy) {
					if (i >= j + 2) {
						if (i != 0 && j != 0 && k != 0) {
							if (k % 2 == 0) {
								result++;
							}
						}
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}
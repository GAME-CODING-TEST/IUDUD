// - 백준 2839 : 설탕 배달

#include <iostream>
using namespace std;

int main() {
	int n, bag = 0;
	cin >> n;

	while (n >= 0) {
		if (n % 5 == 0) {
			bag += (n / 5);
			cout << bag << endl;
			return 0;
		}
		else {
			n -= 3;
			bag++;
		}
	}
	cout << -1 << endl;
}
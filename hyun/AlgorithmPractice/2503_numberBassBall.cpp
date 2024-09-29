#include <iostream>

using namespace std;

int n;
int hint[102], strike[102], ball[102], result;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> hint[i] >> strike[i] >> ball[i];

	for (int i = 123; i <= 987; ++i) {
		bool check = true;
		  
		if (checkNum(i))
			continue;

		for (int j = 0; j < n; ++j) {
			if (!check)
				break;

			check = checkGame(j, i);
		}

		if (check)
			result++;
	}

	cout << result;

	return 0;
}
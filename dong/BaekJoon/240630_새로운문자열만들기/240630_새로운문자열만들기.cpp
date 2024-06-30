#include <iostream>
#include <string>

using namespace std;

int T;
string s, temp;

int main()
{
	cin >> T;

	while (T--) {
		cin >> s;

		temp = s;
		int idx = 0;

		while (true) {
			bool isSame = true;
			for (int i = 0; i + idx < s.size(); ++i) {
				if (s[i + idx] != s[s.size() - i - 1]) {	// 뒤의 값과 다른 경우
					++idx;
					isSame = false;
					break;
				}
			}

			if (isSame) {
				break;
			}
		}

		for (int i = idx - 1; i >= 0; --i) {	// 같은 부분이 아닌 곳부터 역순으로 temp에 넣는다.
			temp.push_back(s[i]);
		}

		cout << temp << endl;
	}
}
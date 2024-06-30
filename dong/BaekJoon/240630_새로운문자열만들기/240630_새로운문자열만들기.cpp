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
				if (s[i + idx] != s[s.size() - i - 1]) {	// ���� ���� �ٸ� ���
					++idx;
					isSame = false;
					break;
				}
			}

			if (isSame) {
				break;
			}
		}

		for (int i = idx - 1; i >= 0; --i) {	// ���� �κ��� �ƴ� ������ �������� temp�� �ִ´�.
			temp.push_back(s[i]);
		}

		cout << temp << endl;
	}
}
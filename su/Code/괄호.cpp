#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T = 0;
	string answer ="";
	cin >> T;

	for (int t = 0; t < T; t++) {
		stack<int> backet;
		string s;
		cin >> s;
		bool flag = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ')' && !backet.empty()) {
				backet.pop();
			}
			else if (s[i] == '(') {
				backet.push(1);
			}
			else
			{
				flag = true;				
				break;
			}
		}
		if (!flag && backet.empty()) {
			answer += "YES\n";
		}
		else {
			answer += "NO\n";
		}
	}

	cout << answer;

	return 0;
}
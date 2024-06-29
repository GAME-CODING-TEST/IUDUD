#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s_input;
stack<char> stk;
int ans;

void MakeIronStick()
{
	for (int i = 0; i < s_input.length(); ++i) {
		if (s_input[i] == '(') {			// '('인 경우
			stk.push(s_input[i]);
		}
		else {								// ')'인 경우
			if (s_input[i - 1] == '(') {	// 레이저인 경우
				stk.pop();
				ans += stk.size();
			}
			else {							// 막대기 끝인 경우
				stk.pop();
				ans++;
			}
		}
	}
}

int main()
{
	cin >> s_input;
	
	MakeIronStick();

	cout << ans;
}
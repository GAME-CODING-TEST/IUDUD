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
		if (s_input[i] == '(') {			// '('�� ���
			stk.push(s_input[i]);
		}
		else {								// ')'�� ���
			if (s_input[i - 1] == '(') {	// �������� ���
				stk.pop();
				ans += stk.size();
			}
			else {							// ����� ���� ���
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
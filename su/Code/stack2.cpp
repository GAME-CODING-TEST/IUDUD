#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	string answer="";
	stack<int> stack2;

	for(int i = 0; i < N; i++) {
		int command;
		cin >> command;

		switch (command)
		{
			case 1:
				int num;
				cin >> num;
				stack2.push(num);
				break;
			case 2:
				answer += to_string(stack2.empty() ? -1 : stack2.top()) + "\n";
				if(!stack2.empty())
					stack2.pop();
				break;
			case 3:
				answer += to_string(stack2.size()) + "\n";
				break;
			case 4:
				answer += to_string(stack2.empty() ? 1 : 0) + "\n";
				break;
			case 5:
				answer += to_string(stack2.empty() ? -1 : stack2.top()) + "\n";
				break;
			default:
				break;
		}
	}

	cout << answer;

	return 0;
}
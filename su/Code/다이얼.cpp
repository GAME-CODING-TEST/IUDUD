#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int num[] { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string s;
	cin >> s;
	
	int answer = 0;
	for (char c : s) {
		answer += num[c - 'A'];
	}
	cout << answer;
	return 0;
}
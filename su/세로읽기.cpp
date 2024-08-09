#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> stringArr;
	string answer = "";
	int maxLength = 0;

	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;

		stringArr.push_back(s);
		if (maxLength < stringArr[i].size()) {
			maxLength = stringArr[i].size();
		}
	}
	
	for (int i = 0; i < maxLength; i++) {
		for (int j = 0; j < 5; j++) {
			if(i< stringArr[j].size())
			answer += stringArr[j][i];
		}
	}

	cout << answer;

	return 0;
}
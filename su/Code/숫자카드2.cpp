#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string answer = "";
	unordered_map<int,int> number;

	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		number[card]++;
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		answer +=  to_string(number[card]) + " ";
	}

	cout << answer;
	return 0;
}
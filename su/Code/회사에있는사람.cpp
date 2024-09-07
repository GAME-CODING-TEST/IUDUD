#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	set<string, greater<string>> people;
	for (int i = 0; i < N; i++) {
		string name, state;

		cin >> name >> state;
		if (state == "enter") {
			people.insert(name);
		}
		else {
			people.erase(name);
		}
	}

	for(auto name : people)
		cout << name<<"\n";
	return 0;
}
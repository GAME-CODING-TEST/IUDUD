#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int x;
	string y;
	string answer="";
	vector<pair<int, int>> age(N);
	vector<pair<int, string>> name(N);

	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		age[i] = { x,i };
		name[i] = { i,y };
	}

	sort(age.begin(), age.end());
	for (int i = 0; i<N; i++)
	{
		cout << age[i].first <<" " << name[age[i].second].second<<"\n";
	}

	return 0;
}
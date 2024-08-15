#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int x, y;
	string answer="";
	vector<pair<int, int>> pos(N);

	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		pos[i] = { x,y };		
	}

	sort(pos.begin(), pos.end());
	for (int i = 0; i<N; i++)
	{
		cout << pos[i].first <<" " << pos[i].second<<"\n";
	}

	return 0;
}
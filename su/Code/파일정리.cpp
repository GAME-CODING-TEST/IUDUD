#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<string> split(string s, char c) {
    istringstream iss(s);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, c)) {
        result.push_back(buffer);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    int N;
    cin >> N;
    
    map<string, int> opr;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        vector<string> srr;
        srr = split(s, '.');

        opr[srr[1]]++;
    }

    for (auto n : opr) {
        cout << n.first << " " << n.second<<"\n";
    }
    

    return 0;
}

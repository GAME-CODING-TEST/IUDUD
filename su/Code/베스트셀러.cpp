#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    string answer="";
    map<string, int> best;
    int max=-1;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        best[name]++;

        if (best[name] > max) {
            max = best[name];
            answer = name;
        }
        if (best[name] == max) {
            answer = answer < name ? answer : name;
        }
    }

    cout << answer;

    return 0;
}

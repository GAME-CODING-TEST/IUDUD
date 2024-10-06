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
    int N, K;
    cin >> N >> K;
    N++;
    vector<int> arr(N);

    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int answer = 0;
    int r = 1, l = 0;

    while (r <N) {
        int num = arr[r] - arr[l];
        if (r == l) {
            r++;
            continue;
        }
        if (num == K) {
            answer++;
            r++;
            l++;
        }
        else if (num > K) {
            l++;
        }
        else if (num < K) {
            r++;
        }

    }

    cout << answer;
    return 0;
}

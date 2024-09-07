#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> bigNum;
    vector<int> arr(N);
    vector<int> answer(N, -1);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        while (!bigNum.empty() && arr[bigNum.top()] < arr[i]) {
            answer[bigNum.top()] = arr[i];
            bigNum.pop();
        }
        
        bigNum.push(i);
    }

    for(auto num : answer)
    {
        cout << num << " ";
    }

    return 0;
}

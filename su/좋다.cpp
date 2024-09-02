#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> arr(N);
    int answer = 0;

    for (int i = 0; i < N; i++) {
        long num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr.begin(), arr.end());


    for (int i = 0; i < N; i++) {
        int start = 0, end = N-1;
        while (start < end) {
            long long sum = arr[start] + arr[end];
            if (sum == arr[i]) {
                if(start != i && end != i){
                    answer++;
                    break;                
                }
                else if (start == i) {
                    start++;
                }
                else if (end == i) {
                    end--;
                }
            }
            else if (sum <arr[i]) {
                start++;
            }
            else if (sum > arr[i]) {
                end--;
            }
        }
    }


    cout << answer;

    return 0;
}

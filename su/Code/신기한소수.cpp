#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
string answer;

bool check(int number)
{
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int n, int length) {
    if (length == N) {
        //answer += n + "\n";
        cout << n << endl;
        return;
    }

    for (int i = 1; i < 10; i++) {
        int num = (n*10)+i;
        if (check(num)) {
            dfs(num, length + 1);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);

    cin >> N;
    int a[] = {2,3,5,7};
    
    int answer = 0;
    for (int i = 0; i <4; i++) {
        dfs(a[i], 1);
    }

    //cout << answer;

    return 0;
}

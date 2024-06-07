// - 백준 14929 : 누적 합

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> s; // 누적합
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    s.push_back(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        arr.push_back(num);

        s.push_back(s[i-1] + num);
    }

    for(int i=1;i<=n-1;i++){
        ans += arr[i-1]*(s[n]-s[i]);
    }

    cout << ans << "\n";

    return 0;
}
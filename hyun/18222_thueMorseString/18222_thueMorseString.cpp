// - 백준 18222 : 투에-모스 문자열

#include <iostream>
#include <bitset>
 
#define ll long long
 
using namespace std;
 
ll k;
 
int sol(ll x)
{
    if (x == 0) return 0;
    else if (x == 1) return 1;
    else if (x % 2 == 0)
    {
        return sol(x / 2);
    }
    else
    {
        return 1 - sol(x / 2);
    }
}
 
int main()
{
    cin >> k;
 
    // k는 0부터 시작
    cout << sol(k - 1);
 
    return 0;
}
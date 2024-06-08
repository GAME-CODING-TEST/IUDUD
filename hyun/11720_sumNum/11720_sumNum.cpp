// - 백준 11720 : 숫자의 합

#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += s[i] - '0'; //char형을 int형으로 변환
    }
    cout << sum;
    return 0;
}
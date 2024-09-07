#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    double X, Y;
    cin >> X >> Y;
    int Z = -1;
    int answer = -1;
    // Y / X * 100 = Z
    
    Z = 100.0f * Y / X;
    
    if (Z >= 99.0f) {
        cout << answer;
        return -1;
    }

    int idx = 1;
    while (1) {
        int Z2 = 100.0f * (Y+idx) / (X+idx);

        if (Z2 > Z) {
            answer = idx;
            break;
        }
        idx++;
    }
    
    cout << answer;
    //(int)roundf(answer+0.5f)
    return 0;
}

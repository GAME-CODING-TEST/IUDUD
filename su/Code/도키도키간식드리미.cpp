#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    string answer="";
    int last = 0;
    stack<int> wait;
    vector<int> people(N);
    
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        people[i] = p;
    }

    for (int i = 0; i < N; i++) {
        while (!wait.empty()) {
            if (wait.top() == last + 1) {
                last = wait.top();
                wait.pop();
            }
            else {
                break;
            }
        }
        if (people[i] == last + 1) {
            last = people[i];
            //cout << "in row2 : " << last << "\n";
        }
        else {
            wait.push(people[i]);
            //cout << "wait : "  << wait.top() << "\n";
        }

    }

    while (!wait.empty()) {
        if (wait.top() == last + 1) {
            last = wait.top();
            wait.pop();
        }
        else {
            break;
        }
    }


    cout << ((!wait.empty())? "Sad" : "Nice");

    return 0;
}

#include <string>
#include <vector>

using namespace std;

int solution1(string ineq, string eq, int n, int m) {
    int answer = 0;

    if (ineq == ">" && eq == "=") {
        answer = (n >= m) ? 1 : 0;
    }
    else if (ineq == "<" && eq == "=") {
        answer = (n <= m) ? 1 : 0;
    }
    else if (ineq == ">" && eq == "!") {
        answer = (n > m) ? 1 : 0;
    }
    else {
        answer = (n < m) ? 1 : 0;
    }

    return answer;
}


int solution2(string ineq, string eq, int n, int m) {
    string oper = ineq + eq;
    if (oper == "<=")
    {
        return n <= m;
    }
    else if (oper == ">=")
    {
        return n >= m;
    }
    else if (oper == "<!")
    {
        return n < m;
    }
    else if (oper == ">!")
    {
        return n > m;
    }
}

int main() {}
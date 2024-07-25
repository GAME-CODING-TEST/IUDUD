#include <string>
#include <vector>

using namespace std;

inline std::vector<int> MakeSequence(const int start, const int delta, int size)
{
    int current = start;
    std::vector<int> result;

    while (size--)
    {
        result.emplace_back(current);
        current += delta;
    }

    return result;
}

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    const auto seq = MakeSequence(a, d, included.size());
    for (auto i = 0; i < included.size(); ++i)
    {
        if (included[i])
            answer += seq[i];
    }

    return answer;
}

int solution2(int a, int d, vector<bool> included) {
    int answer = 0;
    a -= d;
    for (auto flag : included)
    {
        a += d;
        if (flag)
            answer += a;
    }
    return answer;
}

int main() {}
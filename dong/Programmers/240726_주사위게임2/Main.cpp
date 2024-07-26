#include <set>
#include <cmath>

int solution(int a, int b, int c)
{
	std::set<int> s{ a, b, c };
	if (s.size() == 3) {
		return a + b + c;
	}
	else if (s.size() == 2) {
		return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
	}
	else if (s.size() == 1) {
		return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
	}
}

int main() {}
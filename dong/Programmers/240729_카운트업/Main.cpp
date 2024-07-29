#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution1(int start_num, int end_num)
{
	vector<int> vec(end_num - start_num + 1);
	while (start_num <= end_num) {
		vec.push_back(start_num++);
	}
	return vec;
}

std::vector<int> solution2(int start_num, int end_num)
{
	std::vector<int> vec(end_num - start_num + 1);
	std::iota(vec.begin(), vec.end(), start_num);
	return vec;
}

int main() {}
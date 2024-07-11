#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	cout << n << " is " << ( (n % 2 == 1) ? "odd" : "even" );	// `?:` 우선순위가 `<<` 보다 낮기 때문에 괄호가 필수
}
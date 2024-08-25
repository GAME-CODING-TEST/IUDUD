// - 백준 10866 : 덱

#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	deque<int> deque1;
	int count;
	cin >> count;
	string s;
	int X;
	while (count--)//count만큼 반복
	{
		cin >> s;//문자열 입력받기
		if (s == "push_front")//pushfront라면
		{
			cin >> X;//int하나 입력받고 push_front
			deque1.push_front(X);
		}
		if (s == "push_back")//push_back이라면
		{
			cin >> X;//int하나 입력받고 push_back
			deque1.push_back(X);
		}
		if (s == "pop_front")//pop_front라면
		{
			if (deque1.empty() == 1)//덱이 비어있다면 -1출력
			{
				cout << -1 << '\n';
			}
			else//아니라면 front출력후 pop
			{
				cout << deque1.front() << '\n';
				deque1.pop_front();
			}
		}
		if (s == "pop_back")//pop_front와 동일
		{
			if (deque1.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque1.back() << '\n';
				deque1.pop_back();
			}
		}
		if (s == "size")//size라면 크기 출력
		{
			cout << deque1.size() << '\n';
		}
		if (s == "empty")//empty라면
		{
			if (deque1.empty() == 1)//비어있다면 1출력
			{
				cout << 1 << '\n';
			}
			else//안비어있으면 0출력
				cout << 0 << '\n';
		}
		if (s == "front")//front라면
		{
			if (deque1.empty() == 1)//비어있을 땐 -1출력
			{
				cout << -1 << '\n';
			}
			else//차있으면 맨 앞 값 출력
			{
				cout << deque1.front() << '\n';
			}
		}
		if (s == "back")//front와 동일
		{
			if (deque1.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque1.back()<<'\n';
			}
		}
	}
}
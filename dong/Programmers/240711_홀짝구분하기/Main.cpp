#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	cout << n << " is " << ( (n % 2 == 1) ? "odd" : "even" );	// `?:` �켱������ `<<` ���� ���� ������ ��ȣ�� �ʼ�
}
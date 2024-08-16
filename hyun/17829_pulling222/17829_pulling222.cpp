// - 백준 17829 : 222-풀링

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mat[1024][1024];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}

	while (n != 1) {
		vector< vector<int>> temp(n / 2, vector<int>(n / 2, 0));
		// NxN 행렬에 222-풀링을 수행하여 나온 N/2 x N/2 행렬을 임시로 저장

		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				vector<int> vtr(4); // 현재 (i, j)번째 2x2행렬
				vtr[0] = mat[i][j];
				vtr[1] = mat[i+1][j];
				vtr[2] = mat[i][j+1];
				vtr[3] = mat[i+1][j+1];

				sort(vtr.begin(), vtr.end());

				temp[i / 2][j / 2] = vtr[2]; // 오름차순 정렬된 상태에서 맨 끝 두번째 = 두번째로 큰 수
			}
		}
		n /= 2;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				mat[i][j] = temp[i][j];
				// 222-풀링을 수행한 결과행렬을 원래의 NxN행렬에 덧붙임
				// 어짜피 다음 while문에서는 N/2사이즈의 행렬에 풀링하는거라!
			}
		}
	}
	
	cout << mat[0][0] << "\n";
	
}
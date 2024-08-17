// - 백준 20438 : 출석체크

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, K, Q, M;
	cin >> N >> K >> Q >> M;
	
	int arr[5003] = {0,};
	bool sleep[5003] = {false,};
	for(int i=0;i<K;i++){
		int a; cin >> a;
		sleep[a] = true;
	}
	
	for(int i=0;i<Q;i++){
		int a; cin >> a;
		int k = 1;
		if(!sleep[a]){
			while(a * k <= N+2){
				if(!sleep[a * k]) arr[a * k] = 1;
				k++;
			}
		}
	}

	int sum[5003] = {0,};
	for(int i=3;i<=N+2;i++){
		sum[i] = sum[i-1] + arr[i];
	}
	
	for(int i=0;i<M;i++){
		int a, b; cin >> a >> b;
		cout << (b-a+1) - (sum[b] - sum[a-1]) << '\n';
	}
	return 0;
}
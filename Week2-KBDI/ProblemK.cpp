#include <iostream>
using namespace std;

long long ans[1 << 20] = {1LL};

int main(){
	int test_num;
	cin >> test_num;
	while(test_num--){
		int n, m;
		int board[20] = {};
		//long long ans[1 << 20] = {1LL};
		cin >> n >> m;
		//create board with bit array !!!
		while(m--){
			int x, y;
			cin >> x >> y;
			board[x-1] |= 1 << (y-1);
		}
		int size = 1 << n;
		for(int i = 1; i < size; i++){
			int p = __builtin_popcount(i);
			ans[i] = 0;
			for(int j = 1; j < size; j <<= 1)
				if((j & i) && !(j & board[p-1])){
					ans[i] += ans[i ^ j];
				}
		}
		printf("%lld\n",ans[size-1]);

	}
	
	return 0;
}

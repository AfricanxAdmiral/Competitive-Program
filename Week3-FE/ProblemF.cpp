#include <iostream>
#include <queue>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int test_num;
	cin >> test_num;
	while(test_num--){
		int n;
		cin >> n;
		int board[n][n];
		int control = 0;
		int maxid = 0, maxval = 0;
		for(int i = 0; i < n; i++){
			control = 0;
			for(int j = 0; j < n; j++){
				int num;
				cin >> num;
				if(num == 1) board[i][j] = 1;
				else board[i][j] = 0;
				control += board[i][j] ? 1 : 0;
			}
			if(control > maxval){
				maxval = control;
				maxid = i;
			}
		}
		int seen[n] = {0};
		queue<int> que;
		int ans = 0;
		que.push(maxid);
		while(!que.empty()){
			int cur = que.front();
			que.pop();
			if(seen[cur]) continue;
			seen[cur]++;
			ans++;
			for(int i = 0; i < n; i++){
				if(!board[i][cur]) continue;
				que.push(i);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
